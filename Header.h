#pragma once

struct cells {
	int i, j, first_i, first_j, second_i, second_j;
};

void title();
int keys_input();
void frame(int position, int item, int type);
int main_menu();
int size_menu();
char** init_array(int size);
void del_array(char** table);
void fill_array(char** arr, int size);
void reset_struct(cells& cell);
void shift(int size);
void table_output(char** arr, int size, cells cell);
bool movement(char** arr, int size, cells& cell);
void game_process(char** arr, int size);