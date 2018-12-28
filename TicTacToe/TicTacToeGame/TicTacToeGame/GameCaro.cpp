#include <C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\iostream>

using namespace std;

void drawBoard(char board[3][3]);
void startGame(char board[3][3], char nameOfPlayer1[10], char nameOfPlayer2[10], string result);
bool check(char board[3][3], int a, int b);
int gameStatus(char board[3][3]);

void drawBoard(char board[3][3]) {
	cout << "____" << " " << "____" << " " << "____" << endl;
	for (int i = 0; i<3; i++)
		{
			//cout <<"    "<< "|" << "    " << "|" << "    "<<endl;
			cout <<"  "<<board[i][0]<<" "<<"|"<<"  "<<board[i][1]<<" "<<"|"<<"  "<<board[i][2]<<" "<<endl;
			cout << "____" << "|" << "____" << "|" << "____" << endl;
		}
}

bool check(char board[3][3], int a, int b) {
	if (board[a][b] == ' ') return true;
	else return false;
}

int gameStatus(char board[3][3]) {
	int win = 0;
	if (win == 0) {
		for (int i = 0; i < 3; i++) {
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
			for (int j = 0; j < 3; j++) {
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

void startGame(char board[3][3], char nameOfPlayer1[10], char nameOfPlayer2[10], string result) {
	int player = 1;
	int position, row, column;
	int count = 0;

	do
	{
		switch (player)
		{
		case 1:
			do {
				cout << "Your turn " << nameOfPlayer1 << " - O: ";
				cin >> position;

				row = position / 10 - 1;
				column = position % 10 - 1;

				if (check(board, row, column)) {
					board[row][column] = 'O';
					break;
				}
			} while (check(board, row, column)==false);

			system("cls");
			drawBoard(board);

			count++;
			player++;
			break;
		case 2:
			do {
				cout << "Your turn " << nameOfPlayer2 << " - X: ";
				cin >> position;

				row = position / 10 - 1;
				column = position % 10 - 1;

				if (check(board, row, column)) {
					board[row][column] = 'X';
					break;
				}
			} while (check(board, row, column) == false);

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

		switch (gameStatus(board))
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
	static char nameOfPlayer1[10]; 
	static char nameOfPlayer2[10];
	static char board[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	static string result = "playing";

	do {
	system("cls");
	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl;
	cout << "If you find any problem, please contact john.nguyen@gameloft.com" << endl;

	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): "; cin >> choice;

		switch (choice)
		{
		case '1':
			cout << "Enter Player 1 Name: "; cin >> nameOfPlayer1;
			cout << "Enter Player 2 Name: "; cin >> nameOfPlayer2;

			drawBoard(board);
			startGame(board, nameOfPlayer1, nameOfPlayer2, result);
			break;
		default:
			break;
		}
		
		cout << "Do you wanna play again? (y/n): "; cin >> confirm;
	} while (confirm == 'y' || confirm == 'Y');
	
	system("pause");
	return 0;
}