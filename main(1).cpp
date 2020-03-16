#include "common.h"
#include "setup.h"

// printf("\033c" ) or system ("CLS") Clears screen

/*
Setup, and auxiliary functions

Actual Game rules to be checked with every play.
bool isTie();
void makeQueen();
void Eat();
*/

int main()
{
	Tile mainBoard[32];
	char player1[25], player2[25];
	bool endGame = false;

	menu(mainBoard, player1, player2);



	do { // Main game loop
		//printf("\033c" );

		char mainInput[15], inputStrA [2], inputStrB [2];

		int inputA, inputB, moveType, eaten[33];

		bool isCoordinate = false;

		printBoard(mainBoard);

		cout << "Jogador(a) 1: " << player1 << endl;
		cout << "Jogador(a) 2: " << player2 << endl;

		cout << "Digite Sair, Salvar ou Posições:\n";

		getchar();
		fgets (mainInput, 13, stdin);

		cout << "..." << endl;
		if ( (strcmp(mainInput, "\n") != 0|| strcmp(mainInput, "") !=0 )) {
			if (strcmp(mainInput,"Salvar\n") == 0  || strcmp(mainInput, "salvar\n") == 0) {
				saveGame(mainBoard, player1, player2);
			} else if ( strcmp(mainInput,"Sair\n" )== 0||strcmp( mainInput, "sair\n")== 0) {
				endGame = true;
			} else {
				inputStrA[0] = mainInput[0];
				inputStrA[1] = mainInput[1];

				inputStrB[0] = mainInput[3];
				inputStrB[1] = mainInput[4];

				inputA = coordinateToNumber(inputStrA);
				cout << inputA << endl;

				inputB = coordinateToNumber(inputStrB);
				cout << inputB << endl;


				isCoordinate = true;
			};

		}

		if (isCoordinate == true) {
			moveType = isValidMove(mainBoard, inputA, inputB, eaten);

			switch (moveType) {
			case 1:
				eat(mainBoard, inputA, inputB, eaten);
				break;
			case 2:
				eat(mainBoard, inputA, inputB, eaten);
				break;
			case 3:
				// Piece Can Eat
				break;
			case 4:
				// Queen Can Eat
				break;
			case 5:
				// Piece Can Eat Multiple Times
				break;
			case 6:
				// Queen Can Eat Multiple Times
				break;
			case 7:
				// Make queen'
				break;
			default:
				cout << "QUEEE?? Repete ai negão!"<< endl;
			};
		}
	} while (endGame == false);
	return 0;
}
