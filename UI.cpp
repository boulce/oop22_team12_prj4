#include <iostream>
#include "gClass.h";
void gotoXY(int x, int y);
void setColor(int color);

void UI::Draw_Main_Box() {
	for (int i = 0; i < main_box_height; i++) {
		for (int j = 0; j < main_box_width; j++) {
			gotoXY(main_box_x + j, main_box_y + i);
			if (j == 0 && i == 0) {
				cout <<"¦®";
			}
			else if (j == main_box_width - 1 && i == 0) {
				cout << "¦¯";
			}
			else if (j == 0 && i == main_box_height - 1) {
				cout << "¦±";
			}
			else if (j == main_box_width - 1 && i == main_box_height - 1) {
				cout << "¦°";
			}
			else if (i == 0 || i == main_box_height - 1) {
				cout << "¦¬";
			}
			else if (j == 0 || j == main_box_width - 1) {
				cout << "¦­";
			}
		}
	}
}

void UI::Draw_Typing_Box() {
	for (int i = 0; i < typing_box_height; i++) {
		for (int j = 0; j < typing_box_width; j++) {
			gotoXY(main_box_x + typing_box_x + j, main_box_y + typing_box_y + i);
			if (j == 0 && i == 0) {
				printf("¦®");
			}
			else if (j == typing_box_width - 1 && i == 0) {
				printf("¦¯");
			}
			else if (j == 0 && i == typing_box_height - 1) {
				printf("¦±");
			}
			else if (j == typing_box_width - 1 && i == typing_box_height - 1) {
				printf("¦°");
			}
			else if (i == 0 || i == typing_box_height - 1) {
				printf("¦¬");
			}
			else if (j == 0 || j == typing_box_width - 1) {
				printf("¦­");
			}
		}
	}
}