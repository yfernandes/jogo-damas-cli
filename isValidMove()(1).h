#pragma once
#include "common.h"

int isValidMove(Tile Board[], int start, int end, int eaten[])
{
	int code = -6; // Number that is returnd in order to carry the game
	int startRow = start / 4,
	    startColumn = start % 4,
	    endRow = end / 4,
	    endColumn = end % 4;

	// Codes :
	//-2 = Nao implementado
	//-1 = Movimento invalido
	// 0 = Pedra inicial não existe;
	// 1 = Pedra pode Mover ou Comer
	// 2 = Tornar Dama NAO IMPLEMENTADO

	if (Board[start].isOccupied == true) {
		// Check if ending row is +2n -2n or = to start row
		// if so the move is a eating move
		if (endRow == startRow + 0 || endRow == startRow + 2 ||
		    endRow == startRow - 2 || endRow == startRow + 4 ||
		    endRow == startRow - 4 || endRow == startRow + 6 ||
		    endRow == startRow - 6 || endRow == startRow + 8 ||
		    endRow == startRow - 8 ) {
			// Eat
		} else if (endRow == startRow + 1 || endRow == startRow - 1) {
			// Piece Move
			if (startColumn == 0 || startColumn == 3 ) {
				if (endColumn == 0) {}
			} else {};
		} else if (endRow == startRow + 3 || endRow == startRow - 3 ||
		           endRow == startRow + 5 || endRow == startRow - 5 ||
		           endRow == startRow + 7 || endRow == startRow - 7) {
			// Queen Move or Eat
		} else {
			cout << "erro" << endl;
		};
	} else {
		cout << "Pedra inicial no encontrada!" << endl;
		code = -1;
	};
	return code;
}
