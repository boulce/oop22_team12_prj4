#include <string>
#include <time.h>
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

	int get_main_box_width() { return main_box_width; }

	void set_main_box_width(int w) { main_box_width = w; }
	void set_main_box_height(int h) { main_box_height = h; }
	void set_main_box_x(int x) { main_box_x = x; }
	void set_main_box_y(int y) { main_box_y = y; }

	int get_typing_box_width() { return typing_box_width; }

	void set_typing_box_width(int w) { typing_box_width = w; }
	void set_typing_box_height(int h) { typing_box_height = h; }
	void set_typing_box_x(int x) { typing_box_x = x; }
	void set_typing_box_y(int y) { typing_box_y = y; }

	void Draw_Main_Box();
	void Draw_Typing_Box();

private:
	int main_box_width; // 메인 게임 공간 너비
	int main_box_height; // 메인 게임 공간 높이
	int main_box_x; // 메인 게임 공간 왼쪽에서 시작 X좌표
	int main_box_y; // 메인 게임 공간 위쪽에서 시작 Y좌표

	int typing_box_width; // 타이핑 공간 너비
	int typing_box_height; // 타이핑 공간 높이
	int typing_box_x; // 타이핑 공간의 메인 게임 공간 왼쪽에서 시작 X좌표
	int typing_box_y; // 타이핑 공간의 메인 게임 공간 아래쪽에서 시작 Y좌표

};

class Window {
public:

	int get_width() { return width;  }

	void set_width(int w) { width = w; }
	void set_height(int h) { height = h; }
	void set_title(string s) { title = s; }

	void Window_Set(); // 윈도우 창 기본 설정
private:
	string title; // 콘솔창 제목
	int width; // 콘솔창 너비
	int height; // 콘솔창 크기
};

class GameManager {
public:
	void Init(); // 게임 시작시 초기 정보 설정
	void Update(); // 프레임마다 정보 Update
	void FPS(clock_t* FPSCurr, clock_t* FPSOld); // Frame Per Second 조절
private:
	Window window;
	UI ui;
};