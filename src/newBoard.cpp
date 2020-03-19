#include "common.h"

void newBoard(Tile Board[])
{
  for (int i = 0; i < 32; i++)
  {
    if (i < 12)
    {
      Board[i].isOccupied = true;
      Board[i].isWhite = false;
      Board[i].isQueen = false;
    }
    else if (i >= 12 && i < 20)
    {
      Board[i].isOccupied = false;
      Board[i].isWhite = false;
      Board[i].isQueen = false;
    }
    else if (i >= 20 && i < 32)
    {
      Board[i].isOccupied = true;
      Board[i].isWhite = true;
      Board[i].isQueen = false;
    }
  }
};