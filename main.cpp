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
	string player1, player2;
	bool endGame = false;

	menu(mainBoard, player1, player2);

	printBoard(mainBoard);


	do { // Main game loop
		char mainInput[15] = "", inputStrA [2]= "", inputStrB [2]= "" ;

		int inputA, inputB, moveType;

		bool isCoordinate = false;

		cout << "Digite Sair, Salvar ou Posições:\n";

		fgets (mainInput, 13, stdin);

		cout << "..." << endl;

		if ( strcmp(mainInput, "") !=0 ) {
			if (strcmp(mainInput,"Salvar\n") == 0  || strcmp(mainInput, "salvar\n") == 0) {
				saveGame(mainBoard, player1, player2);
			} else if ( strcmp(mainInput,"Sair\n" )== 0||strcmp( mainInput, "sair\n")== 0) {
				endGame = true;
			} else {
				cout << "xxx" << endl;
				cout<< "É aqui " << mainInput << endl;

				inputStrA[0] = mainInput[0];
				inputStrA[1] = mainInput[1];
				cout << inputStrA << endl;


				inputStrB[0] = mainInput[3];
				inputStrB[1] = mainInput[4];
				cout << inputStrB << endl;


				inputA = coordinateToNumber(inputStrA);
				cout << inputA << endl;


				inputB = coordinateToNumber(inputStrB);
				cout << inputB << endl;


				// isCoordinate = true;
			};
		}

		if (isCoordinate == true) {
			moveType = isValidMove(mainBoard, inputA, inputB);

			switch (moveType) {
			case 1:
				move(mainBoard, inputA, inputB);
				break;
			case 2:
				// moveQueen
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
				// Make queen
				break;
			default:
				cout << "QUEEE?? Repete ai negão!";
			};
			printBoard(mainBoard);
		}
	} while (endGame == false);
	return 0;
}
