#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

struct Student
{
	int id;
	float score;
	string name;
};

vector<Student> list;
vector<Student>::iterator position;

void input();
void display();

void saveFile();
void loadFile();


void input() {
	int id; float score; string name; char cont;
	Student student;
	do {
		if (list.empty()) {
			cout << "Input student's id: "; cin >> id;
			cin.ignore();
			cout << "Input student's name: "; getline(cin, name);

			cout << "Input student's score: "; cin >> score;
			while (score>10 || score<0) {
				cout << "Input student's score again: "; cin >> score;
			}

			student.id = id;
			student.name = name;
			student.score = score;
			list.push_back(student);
		}
		else {
			cout << "Input student's id: "; cin >> id;

			for (position = list.begin(); position != list.end(); position++) {
				if ((*position).id == id) {
					cout << "Input student's id again: "; cin >> id;
				}
				position = list.begin();
			}

			cin.ignore();
			cout << "Input student's name: "; getline(cin, name);

			cout << "Input student's score: "; cin >> score;
			while (score>10 || score<0) {
				cout << "Input student's score again: "; cin >> score;
			}

			student.id = id;
			student.name = name;
			student.score = score;
			list.push_back(student);
		}
		cout << "Do you want to add more students? (Y/N) "; cin >> cont;
	} while (cont == 'y' || cont == 'Y');

}

void display() {
	cout << "ID     " << "FULL NAME               " << "SCORE" << endl;
	for (position = list.begin(); position != list.end(); position++) {
		cout << setw(8) << left << (*position).id << setw(25) << (*position).name << left
			<< setw(6) << (*position).score << left << endl;
	}
}

void saveFile() {

	fstream file;
	file.open("student.txt", ios::out);

	for (position = list.begin(); position != list.end(); position++) {
		file << (*position).id << " " << (*position).name << " " << (*position).score << endl;
	}
	file.close();
}

int StringToInteger(string NumberAsString)
{
	int NumberAsInteger;
	stringstream ss;
	ss << NumberAsString;
	ss >> NumberAsInteger;
	return NumberAsInteger;
}

void loadFile() {
	list.clear();
	string stringId, name, stringScore;

	int space1 = 0, space2 = 0;

	fstream file;
	file.open("student.txt", ios::in);

	string line;

	Student student;

	while (!file.eof()) {
		getline(file, line);

		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ' ') {
				if (space1 != 0) space2 = i;
				else space1 = i;
			}
		}

		for (int j = 0; j < line.length(); j++) {
			if (j<space1) stringId += line[j];
			else if (j > space1 && j < space2) name += line[j];
			else stringScore += line[j];
		}

		float score = atof(stringScore.c_str());

		if (name != "") {
			student.id = StringToInteger(stringId);
			student.name = name;
			student.score = score;
			list.push_back(student);
		}

		stringId = ""; stringScore = ""; name = "";
		space1 = 0; space2 = 0;
	}

	file.close();
	cout << "Load success" << endl;
}

int main() {

	char choose, choice;
	do {
		system("cls");
		cout << "---------------------MENU---------------------" << endl;
		cout << "1. Input" << endl;
		cout << "2. Display" << endl;
		cout << "3. Save to file" << endl;
		cout << "4. Load from file" << endl;
		cout << "0. Exit" << endl;
		cout << "----------------------------------------------" << endl;
		cout << " Choose: "; cin >> choose;

		switch (choose)
		{
		case '0':
			exit;
		case '1':
			input();
			break;
		case '2':
			display();
			break;
		case '3':
			saveFile();
			break;
		case '4':
			loadFile();
			break;
		}

		cout << "Do you want to continue? (Y/N) "; cin >> choice;
	} while (choice == 'y' || choice == 'Y');

	system("pause");
}
