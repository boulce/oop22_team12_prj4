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
   ���� ��, cursor_function::setColor(int color) �Լ��� ���ڷ� ���ȴ�.
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
	clock_t last_update_time; // �ܾ ���������� ������Ʈ�� �ð�
	clock_t update_time_interval; // �ܾ� ������Ʈ�� �ð� ����
	Color word_color; //�ܾ��� ��
};

class WordManager {
public:
	WordManager();

	vector<Word>& get_falling_word_list() { return falling_word_list; }
	clock_t get_last_word_birth_time() { return last_word_birth_time; }
	clock_t get_birth_time_interval() { return birth_time_interval; }

	void set_last_word_birth_time(clock_t t) { last_word_birth_time = t; }
	void set_birth_time_interval(clock_t t) { birth_time_interval = t; }
	void add_falling_word(int main_box_width); // �� �޼ҵ带 �����ϸ� �����ܾ� �ϳ��� �����ͼ� falling_word_list�� �߰���


private:
	vector<string> load_word_list;
	vector<Word> falling_word_list;
	int total_word_cnt;

	clock_t last_word_birth_time; // �ܾ ���������� ������ �ð�
	clock_t birth_time_interval; // �ܾ� ���� �ð� ����
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

	void down_life(int num); //�������� ��´�. setter���� �̷��� �ϴ°� ������ ���� �����۰����� �߰��ؼ� Ư�� �ܾ� ����� life 3�� �߰� �̷��� �ҰŸ� setter�� �ٲ�� �ҵ�

private:
	string window_title; // �ܼ�â ����
	int window_width; // �ܼ�â �ʺ�
	int window_height; // �ܼ�â ����

	int main_box_width; // ���� ���� ���� �ʺ�
	int main_box_height; // ���� ���� ���� ����
	int main_box_x; // ���� ���� ���� ���ʿ��� ���� X��ǥ
	int main_box_y; // ���� ���� ���� ���ʿ��� ���� Y��ǥ

	int typing_box_width; // Ÿ���� ���� �ʺ�
	int typing_box_height; // Ÿ���� ���� ����
	int typing_box_x; // Ÿ���� ������ ���� ���� ���� ���ʿ��� ���� X��ǥ
	int typing_box_y; // Ÿ���� ������ ���� ���� ���� �Ʒ��ʿ��� ���� Y��ǥ

	int game_over_line_y; // �ܾ ������ ������ ������ y��ǥ

	string typing_str; // ���� �Է��� ���ڿ�
	int score; //����ǥ�ÿ�
	int life; //���� ǥ�ÿ�
};

class GameManager {
public:
	void Init(); // ���� ���۽� �ʱ� ���� ����
	void Update(); // �����Ӹ��� ���� Update
	void FPS(); // Frame Per Second ����
	void is_exit(); //���α׷� ���� ����
private:
	UI ui;
	WordManager word_manager;
	clock_t system_time; // ���� �����ϰ� ����� �ð�
	
};