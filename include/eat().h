#pragma once
#include "common.h"

void eat(Tile Board[], int start, int end, int eaten[])
{
	Board[end].isOccupied = Board[start].isOccupied;
	Board[end].isWhite = Board[start].isWhite;
	Board[end].isQueen = Board[start].isQueen;

	int n = eaten[0];

	for (int i = 1; i <= n; i++) {
		Board[eaten[i]].isOccupied = false;
		Board[eaten[i]].isWhite = false;
		Board[eaten[i]].isQueen = false;
	}


	Board[start].isOccupied = false;
	Board[start].isWhite = false;
	Board[start].isQueen = false;
}
