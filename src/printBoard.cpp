#include "common.h"

void printBoard(Tile Board[])
{
  int charCount = 0;
  cout << "   1 2 3 4 5 6 7 8" << endl;
  for (int i = 0; i < 32; i++)
  {
    if (i % 4 == 0)
    {
      cout << (char)(72 - charCount) << " ";
    };

    if (Board[i].isOccupied)
    {
      if (Board[i].isWhite)
      {
        if (Board[i].isQueen)
        {
          if ((i / 4) % 2 == 0)
          {
            cout << "| |O";
          }
          else
          {
            cout << "|O| ";
          };
        }
        else
        {
          if ((i / 4) % 2 == 0)
          {
            cout << "| |o";
          }
          else
          {
            cout << "|o| ";
          }
        }
      }
      else
      {
        if (Board[i].isQueen)
        {
          if ((i / 4) % 2 == 0)
          {
            cout << "| |X";
          }
          else
          {
            cout << "|X| ";
          }
        }
        else
        {
          if ((i / 4) % 2 == 0)
          {
            cout << "| |x";
          }
          else
          {
            cout << "|x| ";
          }
        }
      };
    }
    else
    {
      cout << "| | ";
    };

    if ((i + 1) % 4 == 0)
    {
      cout << "| " << (char)(72 - charCount) << endl;
      charCount++;
    }
  }
  cout << "   1 2 3 4 5 6 7 8" << endl;
};