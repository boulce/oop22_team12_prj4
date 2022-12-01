#include <string>
//#include <time.h>
#include <vector>
using namespace std;

/*
   색깔 값, setColor(int color) 함수의 인자로 사용된다.
*/
#define RED 4 
#define ORANGE 12
#define YELLOW 14
#define GREEN 10
#define CYAN 11
#define BLUE 9
#define PURPLE 13
#define WHITE 15
#define GRAY 8
#define DARK_YELLOW 6
#define DARK_BLUE 1

class UI {
public:
	UI();

	//int get_main_box_width() { return main_box_width; }
	int get_main_box_x() { return main_box_x; }
	int get_main_box_y() { return main_box_y; }

	//void set_main_box_width(int w) { main_box_width = w; }
	//void set_main_box_height(int h) { main_box_height = h; }
	//void set_main_box_x(int x) { main_box_x = x; }
	//void set_main_box_y(int y) { main_box_y = y; }

	//int get_typing_box_width() { return typing_box_width; }

	//void set_typing_box_width(int w) { typing_box_width = w; }
	//void set_typing_box_height(int h) { typing_box_height = h; }
	//void set_typing_box_x(int x) { typing_box_x = x; }
	//void set_typing_box_y(int y) { typing_box_y = y; }

	void Draw_Main_Box();
	void Draw_Typing_Box();

private:
	string window_title; // 콘솔창 제목
	int window_width; // 콘솔창 너비
	int window_height; // 콘솔창 크기

	int main_box_width; // 메인 게임 공간 너비
	int main_box_height; // 메인 게임 공간 높이
	int main_box_x; // 메인 게임 공간 왼쪽에서 시작 X좌표
	int main_box_y; // 메인 게임 공간 위쪽에서 시작 Y좌표

	int typing_box_width; // 타이핑 공간 너비
	int typing_box_height; // 타이핑 공간 높이
	int typing_box_x; // 타이핑 공간의 메인 게임 공간 왼쪽에서 시작 X좌표
	int typing_box_y; // 타이핑 공간의 메인 게임 공간 아래쪽에서 시작 Y좌표

};


class Word {
public:
	Word(string name, int x, int y, int s);

	string get_name() { return name; }
	int get_x(){ return x; }
	int get_y() { return y; }
	int get_speed() { return speed; }

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
};

class WordManager {
public:
	vector<Word>& get_current_word_list() { return current_word_list;  }

private:
	vector<Word> dictionary;
	vector<Word> current_word_list;
};

class GameManager {
public:
	void Init(); // 게임 시작시 초기 정보 설정
	void Update(); // 프레임마다 정보 Update
	void FPS(/*clock_t* FPSCurr, clock_t* FPSOld*/); // Frame Per Second 조절
private:
	//Window window;
	UI ui;
	WordManager word_manager;
};