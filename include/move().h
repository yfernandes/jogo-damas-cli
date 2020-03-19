#pragma once
#include "common.h"

void move(Tile Board[], int start, int end)
{
  Board[end].isOccupied = Board[start].isOccupied;
  Board[end].isWhite = Board[start].isWhite;
  Board[end].isQueen = Board[start].isQueen;

  Board[start].isOccupied = false;
  Board[start].isWhite = false;
  Board[start].isQueen = false;
}
