#include <iostream>
#include <cstdlib>
#define arraySize 3
#define nameSize 20

using namespace std;

void drawBoard(char board[arraySize][arraySize]);
void startGame(char board[arraySize][arraySize], char nameOfPlayer1[nameSize], char nameOfPlayer2[nameSize], string result);
bool checkEmpty(char board[arraySize][arraySize], int a, int b);
int getGameStatus(char board[arraySize][arraySize]);

void drawBoard(char board[arraySize][arraySize]) {
	cout << " _____" << " " << "_____" << " " << "_____" << endl;
	for (int i = 0; i<arraySize; i++)
		{
			cout <<"|" << "     " << "|" << "     " << "|" << "     " << "|" << endl;
			cout << "|" <<"  "<<board[i][0]<<"  "<<"|"<<"  "<<board[i][1]<<"  "<<"|"<<"  "<<board[i][2]<<"  "<< "|"<<endl;
			cout << "|" << "_____" << "|" << "_____" << "|" << "_____" << "|" << endl;
		}
}

bool checkEmpty(char board[arraySize][arraySize], int a, int b) {
	if (board[a][b] == ' ') return true;
	else return false;
}

int getGameStatus(char board[arraySize][arraySize]) {
	int win = 0;
	if (win == 0) {
		for (int i = 0; i < arraySize; i++) {
			switch (board[i][0])
			{
			case 'O':
				if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
					win = 1;
				break;
			case 'X':
				if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
					win = 2;
				break;
			default:
				break;
			}
		}
	
		if (win == 0) {
			for (int j = 0; j < arraySize; j++) {
				switch (board[0][j])
				{
				case 'O':
					if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
						win = 1;
					break;
				case 'X':
					if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
						win = 2;
					break;
				default:
					break;
				}
			}
		
		if (win == 0) {
				switch (board[0][0])
				{
				case 'O':
					if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
						win = 1;
					break;
				case 'X':
					if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
						win = 2;
					break;
				default:
					break;
				}
		
		
		if (win == 0)
			switch (board[0][2])
			{
			case 'O':
				if (board[0][2] == board[1][1] && board[2][0] == board[1][1])
					win = 1;
				break;
			case 'X':
				if (board[0][2] == board[1][1] && board[2][0] == board[1][1])
					win = 2;
				break;
			default:
				break;
			}
	}}}
	return win;
}

void startGame(char board[arraySize][arraySize], char nameOfPlayer1[nameSize], char nameOfPlayer2[nameSize], string result) {
	int player = 1;
	int position, row, column;
	int count = 0;

	do
	{
		switch (player)
		{
		case 1:
			cout << "Your turn " << nameOfPlayer1 << " - O: ";
			cin >> position;

			row = position / 10 - 1;
			column = position % 10 - 1;

			if (checkEmpty(board, row, column)) {
				board[row][column] = 'O';
			}
			else
			{
				do {
					cout << "Please mark again - O: ";
					cin >> position;

					row = position / 10 - 1;
					column = position % 10 - 1;
				} while (checkEmpty(board, row, column)==false);
				board[row][column] = 'O';
			}
				
			system("cls");
			drawBoard(board);

			count++;
			player++;
			break;
		case 2:
			cout << "Your turn " << nameOfPlayer2 << " - X: ";
			cin >> position;

			row = position / 10 - 1;
			column = position % 10 - 1;

			if (checkEmpty(board, row, column)) {
				board[row][column] = 'X';
			}
			else
			{
				do {
					cout << "Please mark again - X: ";
					cin >> position;

					row = position / 10 - 1;
					column = position % 10 - 1;
				} while (checkEmpty(board, row, column) == false);
				board[row][column] = 'X';
			}

			system("cls");
			drawBoard(board);

			count++;
			player--;
			break;
		}

		if (count == 9) {
			cout << "DRAW GAME!!!"<<endl;
			result = 'draw';
			break;
		}

		switch (getGameStatus(board))
			{
			case 1: cout << "PLAYER 1 WIN!!!" << endl;
				result = 'win';
				break;
			case 2: cout << "PLAYER 2 WIN!!!" << endl;
				result = 'win';
				break;
			default:
				break;
			}

	} while (result == "playing");
}

int main() {

	char choice, confirm;
	static char nameOfPlayer1[nameSize]; 
	static char nameOfPlayer2[nameSize];
	static char board[arraySize][arraySize] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	static string result = "playing";

	
	system("cls");
	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl;
	cout << "If you find any problem, please contact john.nguyen@gameloft.com" << endl;

	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): "; cin >> choice;
	
	
	do {
		system("cls");
		for (int i = 0; i < arraySize; i++)
			for (int j = 0; j < arraySize; j++)
				board[i][j] = ' ';
			
		switch (choice)
		{
		case '1':
			cin.ignore();
			cout << "Enter Player 1 Name: "; cin.getline(nameOfPlayer1,nameSize) ;
			cout << "Enter Player 2 Name: "; cin.getline(nameOfPlayer2,nameSize);	
			drawBoard(board);
			startGame(board, nameOfPlayer1, nameOfPlayer2, result);
			break;
		default:
			exit(0);
		}
		
		cout << "Do you wanna play again? (y/n): "; cin >> confirm;
	} while (confirm == 'y' || confirm == 'Y');
	
	system("pause");
	return 0;
}