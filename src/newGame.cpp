#include "common.h"
#include "newBoard().h" 

void newGame(Tile Board[], string &player1, string &player2)
{
  newBoard(Board);
  cout << "Qual o nome do primeiro jogador? " << endl;
  cin >> player1;
  cout << "Qual o nome do segundo jogador? " << endl;
  cin >> player2;
  cout << endl;
};
