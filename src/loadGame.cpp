#include "common.h"

void loadGame(Tile Board[], string &player1, string &player2)
{
  ifstream load;
  string auxString = "";
  load.open("test.txt", fstream::in);

  getline(load, auxString);
  player1 = auxString;
  getline(load, auxString);
  player2 = auxString;
  char auxChar;

  for (int i = 0; i < 32; i++)
  {
    do
    {
      load.get(auxChar);
    } while (auxChar == '\n' || auxChar == '\0');

    if (auxChar == '-')
    {
      Board[i].isOccupied = false;
      Board[i].isWhite = false;
      Board[i].isQueen = false;
    }
    else
    {
      if (auxChar == 'x' || auxChar == 'X')
      {
        Board[i].isOccupied = true;
        Board[i].isWhite = false;
        if (auxChar == 'x')
        {
          Board[i].isQueen = false;
        }
        else
        {
          Board[i].isQueen = true;
        }
      }
      else
      {
        Board[i].isOccupied = true;
        Board[i].isWhite = true;
        if (auxChar == 'o')
        {
          Board[i].isQueen = false;
        }
        else
        {
          Board[i].isQueen = true;
        }
      }
    }
  };

  load.close();
};
