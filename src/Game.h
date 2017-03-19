/*
 * Game.h
 *
 *  Created on: Feb 5, 2017
 *      Author: Capellán
 */

#ifndef GAME_H_
#define GAME_H_

namespace tictactoe {

	class Game {
		public:
			Game();
			void desplegarTablero();
			bool ganador();
			bool empatar();
			bool verificarCasilla(int fila, int columna);
			char tabla[3] [3];
			char jugadorActual;
			virtual ~Game();
	};

}

#endif
