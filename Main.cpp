#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

int main()
{
	srand(time(NULL));

	int selection;
	int size = 0;

	while (true) {

		selection = main_menu();

		if (selection == 2) {
			return 0;
		}

		selection = size_menu();

		switch (selection) {

		case 1: {

			size = 4;
			char** table = init_array(size);
			fill_array(table, size);

			game_process(table, size);

			del_array(table);

		}break;

		case 2: {

			size = 5;
			char** table = init_array(size);
			fill_array(table, size);

			game_process(table, size);

			del_array(table);

		}break;

		case 3: {

			size = 6;
			char** table = init_array(size);
			fill_array(table, size);

			game_process(table, size);

			del_array(table);

		}break;
		}
	}
}