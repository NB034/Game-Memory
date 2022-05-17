#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include "Header.h"

#define none -1

using namespace std;

typedef std::chrono::high_resolution_clock timer;

void title() {

	system("cls");

	cout << "\t";
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "  ";
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "  ";
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "  ";
	cout << char(220) << char(220) << char(220) << char(220) << char(220) << "  ";
	cout << char(220) << char(220) << char(220) << char(220) << " " << "  ";
	cout << char(220) << "   " << char(220);
	cout << endl;

	cout << "\t";
	cout << char(219) << " " << char(219) << " " << char(219) << "  ";
	cout << char(219) << char(254) << char(254) << char(254) << char(254) << "  ";
	cout << char(219) << " " << char(219) << " " << char(219) << "  ";
	cout << char(219) << "   " << char(219) << "  ";
	cout << char(219) << char(254) << char(254) << char(254) << char(219) << "  ";
	cout << char(223) << char(254) << char(254) << char(254) << char(219);
	cout << endl;

	cout << "\t";
	cout << char(223) << " " << char(223) << " " << char(223) << "  ";
	cout << char(223) << char(223) << char(223) << char(223) << char(223) << "  ";
	cout << char(223) << " " << char(223) << " " << char(223) << "  ";
	cout << char(223) << char(223) << char(223) << char(223) << char(223) << "  ";
	cout << char(223) << "   " << char(223) << "  ";
	cout << "    " << char(223);
	cout << endl << endl;
}
int keys_input() {

	int arrow;
	arrow = _getch();

	if (arrow == 224) {

		arrow = _getch();

		if (arrow == 72) {
			return -1;
		}
		else if (arrow == 80) {
			return 1;
		}
	}

	else if (arrow == 13) {
		return 0;
	}
}
void frame(int position, int item, int type) {

	if (position == item && type == 1) {

		cout << "\t\t" << char(201);

		for (int i = 0; i < 22; i++) {
			cout << char(205);
		}
		cout << char(187) << endl;

		cout << "\t\t" << char(186);
	}

	else if (position == item && type == 2) {

		cout << char(186) << endl;

		cout << "\t\t" << char(200);

		for (int i = 0; i < 22; i++) {
			cout << char(205);
		}
		cout << char(188) << endl;
	}

	else if (position != item && type == 1) {

		cout << "\t\t" << char(218);
		for (int i = 0; i < 22; i++) {
			cout << char(196);
		}
		cout << char(191) << endl;
		cout << "\t\t" << char(179);
	}

	else if (position != item && type == 2) {

		cout << char(179) << endl;
		cout << "\t\t" << char(192);
		for (int i = 0; i < 22; i++) {
			cout << char(196);
		}
		cout << char(217) << endl;
	}
}
int main_menu() {

	int position = 1;
	int input;

	while (true) {

		title();
		frame(position, 1, 1);
		cout << "     Start game       ";
		frame(position, 1, 2);

		frame(position, 2, 1);
		cout << "     Quit\t       ";
		frame(position, 2, 2);

		cout << endl << "\t\t   Use " << char(25) << char(24) << " to navigate!" << endl;

		input = keys_input();

		switch (input) {

		case 1: {
			if (position == 2) {
				position = 1;
			}
			else {
				position = 2;
			}
		}break;

		case -1: {
			if (position == 1) {
				position = 2;
			}
			else {
				position = 1;
			}
		}break;

		case 0: {
			return position;
		}break;
		}
	}
}
int size_menu() {

	int position = 1;
	int input;

	while (true) {

		title();
		frame(position, 1, 1);
		cout << "\t 4 x 4         ";
		frame(position, 1, 2);

		frame(position, 2, 1);
		cout << "\t 4 x 5         ";
		frame(position, 2, 2);

		frame(position, 3, 1);
		cout << "\t 4 x 6         ";
		frame(position, 3, 2);
		cout << endl << "\t\t   Use " << char(25) << char(24) << " to navigate!" << endl;

		input = keys_input();

		switch (input) {

		case 1: {
			if (position == 3) {
				position = 1;
			}
			else {
				position++;
			}
		}break;

		case -1: {
			if (position == 1) {
				position = 3;
			}
			else {
				position--;
			}
		}break;

		case 0: {
			return position;
		}break;
		}
	}
}
char** init_array(int size) {

	char** arr = new char* [4];

	for (int i = 0; i < 4; i++) {

		arr[i] = new char[size] {0};
	}

	return arr;
}
void del_array(char** table) {

	for (int i = 0; i < 4; i++) {

		delete[] table[i];
	}

	delete[] table;
}
void fill_array(char** arr, int size) {

	int step = 0;
	int pair = 0;

	while (true) {

		int i = rand() % 4;
		int j = rand() % size;

		if (arr[i][j] == 0) {

			arr[i][j] = char(65 + step);

			pair++;

			if (pair == 2) {

				pair = 0;
				step++;
			}
		}

		if (step == 4 * size / 2) {
			break;
		}
	}
}
void reset_struct(cells& cell) {

	cell.first_i = none;
	cell.first_j = none;
	cell.second_i = none;
	cell.second_j = none;
}
void shift(int size) {

	if (size == 4) {
		cout << "\t\t      ";
	}

	else if (size == 5) {
		cout << "\t\t     ";
	}

	else if (size == 6) {
		cout << "\t\t    ";
	}
}
void table_output(char** arr, int size, cells cell) {

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO start_attribute;
	GetConsoleScreenBufferInfo(hStdOut, &start_attribute);

	title();

	shift(size);

	cout << char(201);

	for (int i = 0; i < size * 2 + 1; i++) {

		cout << char(205);
	}

	cout << char(187);
	cout << endl;

	//

	for (int i = 0; i < 4; i++) {

		shift(size);

		cout << char(186) << " ";

		for (int j = 0; j < size; j++) {

			if ((i == cell.first_i && j == cell.first_j) || (i == cell.second_i && j == cell.second_j)) {

				if (i == cell.i && j == cell.j) {
					SetConsoleTextAttribute(hStdOut, 4);
				}

				cout << arr[i][j] << " ";

				SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes);
			}

			else if (arr[i][j] == 0 && cell.i == i && cell.j == j) {

				if (i == cell.i && j == cell.j) {
					SetConsoleTextAttribute(hStdOut, 8);
				}

				cout << char(254) << " ";

				SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes);
			}

			else if (arr[i][j] == 0) {
				cout << "  ";
			}

			else {

				if (i == cell.i && j == cell.j) {
					SetConsoleTextAttribute(hStdOut, 4);
				}

				cout << char(254) << " ";

				SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes);
			}
		}

		cout << char(186) << endl;
	}

	//

	shift(size);

	cout << char(200);

	for (int i = 0; i < size * 2 + 1; i++) {

		cout << char(205);
	}

	cout << char(188);
	cout << endl;

	cout << endl << "\t\t  Use " << char(25) << char(24) << " to navigate!" << endl;
}
bool movement(char** arr, int size, cells& cell) {

	int action = _getch();

	if (action == 224) {

		action = _getch();

		if (action == 72) {

			if (cell.i - 1 < 0) {
				cell.i = 3;
			}
			else {
				cell.i--;
			}
		}

		else if (action == 80) {

			if (cell.i + 1 > 3) {
				cell.i = 0;
			}
			else {
				cell.i++;
			}
		}

		else if (action == 75) {

			if (cell.j - 1 < 0) {
				cell.j = size - 1;
			}
			else {
				cell.j--;
			}
		}

		else if (action == 77) {

			if (cell.j + 1 >= size) {
				cell.j = 0;
			}
			else {
				cell.j++;
			}
		}
	}

	else if (action == 13) {

		if (cell.i != cell.first_i || cell.j != cell.first_j) {

			if (cell.i != cell.second_i || cell.j != cell.second_j) {

				if (arr[cell.i][cell.j] != 0) {
		
					return true;
				}
			}
		}
	}

	return false;
}
void game_process(char** arr, int size) {

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO start_attribute;
	GetConsoleScreenBufferInfo(hStdOut, &start_attribute);

	cells cell;
	cell.i = 0;
	cell.j = 0;

	reset_struct(cell);

	bool enter = false;
	bool win = false;
	int turns = 0;

	auto t1 = timer::now();

	while (true) {

		table_output(arr, size, cell);

		enter = movement(arr, size, cell);

		if (enter) {

			if (cell.first_i == none) {

				cell.first_i = cell.i;
				cell.first_j = cell.j;
			}
			else {

				cell.second_i = cell.i;
				cell.second_j = cell.j;

				table_output(arr, size, cell);
				Sleep(800);

				if (arr[cell.first_i][cell.first_j] == arr[cell.second_i][cell.second_j]) {

					Beep(600, 150);

					arr[cell.first_i][cell.first_j] = 0;
					arr[cell.second_i][cell.second_j] = 0;

					turns++;

					reset_struct(cell);

					win = true;

					for (int i = 0; i < 4; i++) {

						for (int j = 0; j < size; j++) {

							if (arr[i][j] != 0) {
								win = false;
							}
						}
					}
				}

				else {
					Beep(300, 150);

					turns++;
					reset_struct(cell);
				}
			}
		}

		if (win) {
			break;
		}
	}

	auto t2 = timer::now();

	title();

	SetConsoleTextAttribute(hStdOut, 2);
	frame(1, 1, 1);
	SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes);
	cout << "      You win!        ";
	SetConsoleTextAttribute(hStdOut, 2);
	frame(1, 1, 2);
	SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes);
	cout << endl;

	Sleep(500);

	cout << "\t        " << char(186) << "     Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000000 << " seconds" << endl << endl;

	Sleep(500);

	cout << "\t        " << char(186) << "     Turns: " << turns << endl << endl;

	Sleep(500);

	int pause = _getch();
}