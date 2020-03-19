#pragma once
#include "common.h"

void loadGame(Tile Board[], char player1[], char player2[])
{

	ifstream load;

	load.open("test.txt", fstream::in);

	load.getline(player1, 24);

	load.getline(player2, 24);

	char auxChar;

	for (int i = 0; i < 32; i++) {
		do {
			load.get(auxChar);
		} while (auxChar == '\n' || auxChar == '\0');

		if (auxChar == '-') {
			Board[i].isOccupied = false;
			Board[i].isWhite = false;
			Board[i].isQueen = false;
		} else {
			if (auxChar == 'x' || auxChar == 'X') {
				Board[i].isOccupied = true;
				Board[i].isWhite = false;
				if (auxChar == 'x') {
					Board[i].isQueen = false;
				} else {
					Board[i].isQueen = true;
				}
			} else {
				Board[i].isOccupied = true;
				Board[i].isWhite = true;
				if (auxChar == 'o') {
					Board[i].isQueen = false;
				} else {
					Board[i].isQueen = true;
				}
			}
		}
	};

	load.close();
};
