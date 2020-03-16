#pragma once
#include "common.h"
#include "loadGame().h"
#include "newGame().h"


void menu(Tile Board[], string &player1, string &player2)
{
  // O Menu principal é o responsavel por criar um novo jogo, ou permitir que o
  // usuario insira um arquivo para continuar o jogo.
  bool end = false;
  string input;

  cout << "Olá tudo bem?" << endl;
  cout << "Gostaria de começar um jogo novo ou continuar de onde parou?"
       << endl;
  cout << "Digite 'Novo' ou  'Continuar'." << endl;

  do
  {
    cin >> input;

    if (input.compare("Novo") == 0 || input.compare("novo") == 0)
    {
      cout << "Jogo novo então??" << endl;

      newGame(Board, player1, player2);

      end = true;
    }
    else if (input.compare("continuar") == 0 ||
             input.compare("Continuar") == 0)
    {
      cout << "Você quer continuar " << endl;
      loadGame(Board, player1, player2);
      end = true;
    }
    else
    {
      cout << "Nao entendi. Pode digitar de novo?" << endl;
      cout << "Gostaria de começar um jogo novo ou continuar de onde parou?"
           << endl;
      cout << "Digite 'Novo' ou  'Continuar'." << endl;
    };
  } while (end == false);
};
