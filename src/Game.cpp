/*
 * Game.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: Capellán
 */

#include "Game.h"
#include <iostream>
using namespace std;

namespace tictactoe {

	Game::Game() : jugadorActual('X')
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				tabla[i][j] = '.';
			}
		}
	}

	void Game::desplegarTablero()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << tabla[i][j]  << "\t";
			}
			cout << endl << endl;
		}
	}

	bool Game::ganador()
	{
		char jugadorEncontrado = '.';

		//Revisado horizontal
		for(int i = 0; i < 3; i++)
		{
			jugadorEncontrado = tabla[i][0];
			for(int j = 0; j < 3; j++)
			{
				if(jugadorEncontrado != tabla[i][j] or tabla[i][j] == '.')
				{
					break;
				}
				jugadorEncontrado = tabla[i][j];
				if(j == 2)
				{
					cout << "El jugador '" << jugadorEncontrado << "' ha ganado este encuentro " << endl;
					return true;
				}
			}
		}



		//Revisado vertical
		for(int i = 0; i < 3; i++)
		{
			jugadorEncontrado = tabla[0][i];
			for(int j = 0; j < 3; j++)
			{
				if(jugadorEncontrado != tabla[j][i] || tabla[j][i] == '.')
				{
					break;
				}
				jugadorEncontrado = tabla[j][i];
				if(j == 2)
				{
					cout << "El jugador '" << jugadorEncontrado << "' ha ganado este encuentro " << endl;
					return true;
				}
			}
		}

		//Revisado diagonal hizquierda -> derecha
		jugadorEncontrado = tabla[0][0];
		for(int i = 0; i < 3; i++)
		{
			if(jugadorEncontrado != tabla[i][i] || tabla[i][i] == '.')
			{
				break;
			}
			jugadorEncontrado = tabla[i][i];
			if(i == 2)
			{
				cout << "El jugador '" << jugadorEncontrado << "' ha ganado este encuentro " << endl;
				return true;
			}
		}

		//Revisado diagonal derecha -> hizquierda
		jugadorEncontrado = tabla[0][2];
		for(int i = 0; i < 3; i++)
		{
			if(jugadorEncontrado != tabla[i][2 - i] || tabla[i][2 - i] == '.')
			{
				break;
			}
			jugadorEncontrado = tabla[i][2 - i];
			if(i == 2)
			{
				cout << "El jugador '" << jugadorEncontrado << "' ha ganado este encuentro " << endl;
				return true;
			}
		}

		return false;
	}

	bool Game::empatar()
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if (tabla[i][j] == '.')
				{
					return false;
				}
			}
		}
		cout << "Esto ha sido un empate." << endl;
		return true;
	}

	bool Game::verificarCasilla(int fila, int columna)
	{
		if(fila > 2 || fila < 0 || columna > 2 || columna < 0)
		{
			cout << "Ha introducido una casilla inexistente, solo se aceptan valores desde '0' hasta '2'" << endl;
			return true;
		}

		if (tabla[fila][columna] != '.')
		{
			cout << "Por favor seleciona otra casilla, esta esta ocupada!!!" << endl;
			return true;
		}

		return false;
	}

	Game::~Game()
	{

	}

}
