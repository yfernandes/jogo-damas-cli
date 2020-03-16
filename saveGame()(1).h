#pragma once
#include "common.h"

void saveGame(Tile Board[], char player1[], char player2[])
{
  cout << "Salvando Jogo!" << endl;
  ofstream save;
  save.open("test.txt", fstream::out);

  save << player1 << endl;
  save << player2 << endl;

  for (int i = 0; i < 32; i++)
  {
    if (Board[i].isOccupied)
    {
      if (Board[i].isWhite)
      {
        if (Board[i].isQueen)
        {
          save << 'O';
        }
        else
        {
          save << 'o';
        }
      }
      else
      {
        if (Board[i].isQueen)
        {
          save << 'X';
        }
        else
        {
          save << 'x';
        };
      };
    }
    else
    {
      save << '-';
    };

    if ((i + 1) % 4 == 0)
    {
      save << endl;
    }
  };

  save.close();
};
