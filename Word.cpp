#include <iostream>
#include "gClass.h"
void gotoXY(int x, int y);

Word::Word(string name, int x, int y, int s) {
	this->name = name;
	this->x = x;
	this->y = y;
	speed = s;
}

void Word::Word_Draw(int main_box_x, int main_box_y) {
	gotoXY(main_box_x + x, main_box_y + y);
	cout << name;
}

void Word::Word_Erase(int main_box_x, int main_box_y) {
	gotoXY(main_box_x + x, main_box_y + y);
	string temp;
	for (int i = 0; i < name.size(); i++) temp += " ";
	cout << temp;
}