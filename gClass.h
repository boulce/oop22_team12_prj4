#include <string>
#include <vector>
#include <time.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <random>

using namespace std;

/*
   색깔 값, cursor_function::setColor(int color) 함수의 인자로 사용된다.
*/


enum Color {
	DARK_BLUE = 1,
	RED = 4,
	DARK_YELLOW = 6,
	GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN=11,
	ORANGE=12,
	PURPLE=13,
	YELLOW=14,
	WHITE=15

};




void gotoXY(int, int); //cursor_function::gotoXY
void setColor(int); //cursor_function::setColor

class Word {
public:
	Word(string name, int x = 0, int y = 0, int s = 0, clock_t update_time_interval = 0, Color word_color=WHITE);

	string get_name() { return name; }
	int get_x() { return x; }
	int get_y() { return y; }
	int get_speed() { return speed; }
	Color get_color() { return word_color; }

	clock_t get_last_update_time() { return last_update_time; }
	clock_t get_update_time_interval() { return update_time_interval; }

	void set_last_update_time(clock_t t) { last_update_time = t; }
	void set_update_time_interval(clock_t t) { update_time_interval = t; }


	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }
	void set_speed(int s) { speed = s; }

	void Word_Draw(int main_box_x, int main_box_y);
	void Word_Erase(int main_box_x, int main_box_y);

private:
	string name;
	int x;
	int y;
	int speed;
	clock_t last_update_time; // 단어가 마지막으로 업데이트된 시각
	clock_t update_time_interval; // 단어 업데이트된 시간 간격
	Color word_color; //단어의 색
};

class WordManager {
public:
	WordManager();

	vector<Word>& get_falling_word_list() { return falling_word_list; }
	clock_t get_last_word_birth_time() { return last_word_birth_time; }
	clock_t get_birth_time_interval() { return birth_time_interval; }

	void set_last_word_birth_time(clock_t t) { last_word_birth_time = t; }
	void set_birth_time_interval(clock_t t) { birth_time_interval = t; }
	void add_falling_word(int main_box_width); // 이 메소드를 실행하면 랜덤단어 하나만 가져와서 falling_word_list에 추가됨


private:
	vector<string> load_word_list;
	vector<Word> falling_word_list;
	int total_word_cnt;

	clock_t last_word_birth_time; // 단어가 마지막으로 생성된 시각
	clock_t birth_time_interval; // 단어 생성 시간 간격
};

class UI {
public:
	UI();

	int get_main_box_width() { return main_box_width; }
	int get_main_box_x() { return main_box_x; }
	int get_main_box_y() { return main_box_y; }
	int get_game_over_line_y() { return game_over_line_y; }
	int get_score() { return score; }
	int get_life() { return life; }
	
	void Draw_Main_Box();
	void Draw_Typing_Box();

	void Draw_Score();
	void Draw_Life();

	void keyboardEvent(vector<Word>& falling_word_list);

	void down_life(int num); //라이프를 깎는다. setter보다 이렇게 하는게 나은듯 만약 아이템같은걸 추가해서 특정 단어 맞출시 life 3개 추가 이런거 할거면 setter로 바꿔야 할듯

private:
	string window_title; // 콘솔창 제목
	int window_width; // 콘솔창 너비
	int window_height; // 콘솔창 높이

	int main_box_width; // 메인 게임 공간 너비
	int main_box_height; // 메인 게임 공간 높이
	int main_box_x; // 메인 게임 공간 왼쪽에서 시작 X좌표
	int main_box_y; // 메인 게임 공간 위쪽에서 시작 Y좌표

	int typing_box_width; // 타이핑 공간 너비
	int typing_box_height; // 타이핑 공간 높이
	int typing_box_x; // 타이핑 공간의 메인 게임 공간 왼쪽에서 시작 X좌표
	int typing_box_y; // 타이핑 공간의 메인 게임 공간 아래쪽에서 시작 Y좌표

	int game_over_line_y; // 단어가 닿으면 게임이 끝나는 y좌표

	string typing_str; // 현재 입력한 문자열
	int score; //점수표시용
	int life; //생명 표시용
};

class GameManager {
public:
	void Init(); // 게임 시작시 초기 정보 설정
	void Update(); // 프레임마다 정보 Update
	void FPS(); // Frame Per Second 조절
	void is_exit(); //프로그램 종료 판정
private:
	UI ui;
	WordManager word_manager;
	clock_t system_time; // 게임 시작하고 경과된 시간
	
};