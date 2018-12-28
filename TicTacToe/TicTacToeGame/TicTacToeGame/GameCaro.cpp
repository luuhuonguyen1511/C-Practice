#include <C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\iostream>

using namespace std;

void drawBoard(char board[3][3]);
void startGame(char board[3][3], char nameOfPlayer1[10], char nameOfPlayer2[10]);
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
	if (board[a][b] != ' ') return false;
	else return true;
}

int gameStatus(char board[3][3]) {
	int win = 0;
	if (win == 0) {
		for (int i = 0; i < 3; i++) {
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'O')
				win = 1;
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'X')
				win = 2;
		}
	
		for (int j = 0; j < 3; j++) {
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == 'O')
				win = 3;
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == 'X')
				win = 4;
		}
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) win = 5;
	else if (board[0][2] == board[1][1] && board[2][0] == board[1][1]) win = 6;
	
	return win;
}

void startGame(char board[3][3], char nameOfPlayer1[10], char nameOfPlayer2[10]) {
	int player = 1;
	int position, row, column;
	int count = 0;
	
	string result = "playing";

	do
	{
		switch (gameStatus(board))
		{
		case 1: cout << "Player 1 win!" << endl;
			break;
		case 2: cout << "Player 2 win!" << endl;
			break;
		case 3: cout << "Player 1 win!" << endl;
			break;
		case 4: cout << "Player 2 win!" << endl;
			break;
		default:
			break;
		}

		if (player == 1) {
			cout << "Your turn " << nameOfPlayer1 << " - O: ";
			cin >> position;
			
			row = position / 10 - 1;
			column = position % 10 - 1;
			board[row][column] = 'O';
			system("cls");
			drawBoard(board);

			count++;
			player++;
		}

		if (count == 9) {
			cout << "Draw game"<<endl;
			break;
		}

		if (player == 2) {
			cout << "Your turn " << nameOfPlayer2 << " - X: ";
			cin >> position;

			row = position / 10 - 1;
			column = position % 10 - 1;
			board[row][column] = 'X';
			system("cls");
			drawBoard(board);

			/*if (gameStatus(board)==true) {
				cout<<"Player 2 win"<<endl;
				break;
			}*/
			count++;
			player--;
		}
	} while (result == "playing");
}

int main() {

	system("cls");
	
	char choice;
	static char nameOfPlayer1[10]; 
	static char nameOfPlayer2[10];
	static char board[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	
	cout << "Welcome To Tic-tac-toe game! Play with your way!"<<endl;
	cout << "If you find any problem, please contact john.nguyen@gameloft.com"<<endl;

	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): "; cin >> choice;

	switch (choice)
	{
	case '1':
		cout << "Enter Player 1 Name: "; cin>>nameOfPlayer1;
		cout << "Enter Player 2 Name: "; cin>>nameOfPlayer2;

		drawBoard(board);
		startGame(board, nameOfPlayer1, nameOfPlayer2);
		break;
	default:
		break;
	}
	
	system("pause");
	return 0;
}