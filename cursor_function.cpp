#include <windows.h>

void gotoXY(int x, int y) // 커서 위치 이동
{
    COORD pos = { x ,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int color) // 색깔 설정
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}