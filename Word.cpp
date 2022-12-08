#include "gClass.h"

void gotoXY(int x, int y);

Word::Word(string name, int x, int y, int s, clock_t update_time_interval,Color word_color) {
	this->name = name;
	this->x = x;
	this->y = y;
	speed = s;

	this->update_time_interval = update_time_interval;

	
	this->word_color = word_color;
	
	last_update_time = clock(); // 단어가 처음 생성됐을 때 시간을 저장한다
}

void Word::Word_Draw(int main_box_x, int main_box_y) {
	gotoXY(main_box_x + x, main_box_y + y);
	setColor(word_color);
	cout << name;
	setColor(WHITE);
}

void Word::Word_Erase(int main_box_x, int main_box_y) {
	gotoXY(main_box_x + x, main_box_y + y);
	string temp;
	for (int i = 0; i < name.size(); i++) temp += " ";
	cout << temp;
}