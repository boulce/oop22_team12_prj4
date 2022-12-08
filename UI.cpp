#include "gClass.h"





UI::UI() {

	/*
		콘솔창 정보 설정
	*/
	string temp;

	window_title = "OOP22 TEAM12 PROJECT4";
	window_width = 100;
	window_height = 40;

	temp = "title " + window_title;
	system(temp.c_str()); // 제목 설정

	temp = "mode concols=" + to_string(window_width) + " lines=" + to_string(window_height);
	system(temp.c_str()); // 크기 설정

	// 커서 깜빡거림 제거
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	/*
		게임 내 UI 정보 설정
	*/


	// Main_Box 설정
	main_box_width = 80;
	main_box_height = 25;
	main_box_x = (window_width - main_box_width) / 2; // Main_Box가 Window의 중간에 오도록 한다
	main_box_y = 1;
	Draw_Main_Box();

	// Typing_Box 설정
	typing_box_width = 26 ;
	typing_box_height = 3;
	typing_box_x = (main_box_width - typing_box_width) / 2; // Typing_Box가 Main_Box의 중간에 오도록 한다
	typing_box_y = 21;
	Draw_Typing_Box();

	// 게임 오버 라인 y좌표 설정
	game_over_line_y = typing_box_y - 1; // Typing_Box 바로 위로 설정

	score = 0; //처음 점수 설정
	life = 5; //처음 라이프 설정
}

void UI::Draw_Main_Box() {
	for (int i = 0; i < main_box_height; i++) {
		for (int j = 0; j < main_box_width; j++) {
			gotoXY(main_box_x + j, main_box_y + i);
			if (j == 0 && i == 0) {
				cout <<"┏";
			}
			else if (j == main_box_width - 1 && i == 0) {
				cout << "┓";
			}
			else if (j == 0 && i == main_box_height - 1) {
				cout << "┗";
			}
			else if (j == main_box_width - 1 && i == main_box_height - 1) {
				cout << "┛";
			}
			else if (i == 0 || i == main_box_height - 1) {
				cout << "━";
			}
			else if (j == 0 || j == main_box_width - 1) {
				cout << "┃";
			}
		}
	}
}

void UI::Draw_Typing_Box() {
	for (int i = 0; i < typing_box_height; i++) {
		for (int j = 0; j < typing_box_width; j++) {
			gotoXY(main_box_x + typing_box_x + j, main_box_y + typing_box_y + i);
			if (j == 0 && i == 0) {
				printf("┏");
			}
			else if (j == typing_box_width - 1 && i == 0) {
				printf("┓");
			}
			else if (j == 0 && i == typing_box_height - 1) {
				printf("┗");
			}
			else if (j == typing_box_width - 1 && i == typing_box_height - 1) {
				printf("┛");
			}
			else if (i == 0 || i == typing_box_height - 1) {
				printf("━");
			}
			else if (j == 0 || j == typing_box_width - 1) {
				printf("┃");
			}
		}
	}
}


void UI::keyboardEvent(vector<Word>& falling_word_list) {
	char c;
	if (_kbhit()) {
		c = _getch();

		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == ' - ') {
			if (typing_str.size() <= typing_box_width - 4) {
				typing_str += c;
				gotoXY(main_box_x + typing_box_x + 2, main_box_y + typing_box_y + 1);
				cout << typing_str;
			}
		}

		if (c == 8) { // 백스페이스
			if (typing_str.size()) {
				gotoXY(main_box_x + typing_box_x + 2 + typing_str.size() - 1, main_box_y + typing_box_y + 1);
				cout << " ";
				typing_str.pop_back();
			}
		}

		if (c == 13) { // 엔터
			if (typing_str.size()) {	
				for (vector<Word>::iterator it = falling_word_list.begin(); it != falling_word_list.end(); it++) {
					if (it->get_name() == typing_str) { // 일치하는 글자가 있으면 지운다.
						if (it->get_color() == BLUE) { //벡터에서 지우기 전에 색에 따라 score추가 다르게 구현
							score += 3;
						}

						else score++;
						it->Word_Erase(main_box_x, main_box_y);
						falling_word_list.erase(it);

						

						gotoXY(main_box_x + typing_box_x + 2, main_box_y + typing_box_y + 1);
						for (int i = 0; i < typing_str.size(); i++) cout << " "; // Typing_Box 안의 글자 비움

						typing_str.clear();
						break;
					}
				}
			}
		}
	}
}

void UI::down_life(int num)
{
	life-=num;

}