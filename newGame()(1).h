#pragma once
#include "common.h"
#include "newBoard().h" 

void newGame(Tile Board[], char player1[], char player2[])
{
  newBoard(Board);
  cout << "Qual o nome do primeiro jogador? " << endl;
  cin >> player1;
  cout << "Qual o nome do segundo jogador? " << endl;
  cin >> player2;
  cout << endl;
};
