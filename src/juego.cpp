//============================================================================
// Name        : juego.cpp
// Author      : Capellan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Game.h"
using namespace std;
using namespace tictactoe;

int main()
{

	Game tic = Game();


	while(!tic.ganador() && !tic.empatar())
	{
		tic.desplegarTablero();
		int fila = 0;
		int columna = 0;
		cout << "Cual fila desea ocupar: " <<  tic.jugadorActual << endl;
		cin >> fila;
		cout << "Cual columna desea ocupar: " <<  tic.jugadorActual << endl;
		cin >> columna;

		if(!tic.verificarCasilla(fila,columna))
		{
			tic.tabla[fila][columna] = tic.jugadorActual;
			if(tic.jugadorActual == 'X')
			{
				tic.jugadorActual = 'O';
			}
			else
			{
				tic.jugadorActual = 'X';
			}
		}
	}

	tic.desplegarTablero();
	return 0;
}
