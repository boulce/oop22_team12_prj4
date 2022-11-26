#include <windows.h>
#include "gClass.h";

void Window::Window_Set() {
	string temp;
	temp = "title " + title;
	system(temp.c_str()); // 제목 설정

	temp = "mode concols=" + to_string(width) + " lines=" + to_string(height);
	system(temp.c_str()); // 크기 설정

	/*
		커서 깜빡거림 제거
	*/
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}