#include "gClass.h";

void GameManager::Init() {

	/*
		콘솔창 정보 설정	
	*/

	window.set_width(100);
	window.set_height(30);
	window.set_title("OOP22 TEAM12 PROJECT4");
	window.Window_Set();

	/*
		UI 정보 설정
	*/

	// Main_Box 설정
	ui.set_main_box_width(80);
	ui.set_main_box_height(25);
	ui.set_main_box_x((window.get_width() - ui.get_main_box_width()) / 2); // Main_Box가 Window5의 중간에 오도록 한다
	ui.set_main_box_y(1);
	ui.Draw_Main_Box();

	// Typing_Box 설정
	ui.set_typing_box_width(26);
	ui.set_typing_box_height(5);
	ui.set_typing_box_x((ui.get_main_box_width() - ui.get_typing_box_width()) / 2); // Typing_Box가 Main_Box의 중간에 오도록 한다
	ui.set_typing_box_y(18);
	ui.Draw_Typing_Box();
}

void GameManager::Update() {

}

void GameManager::FPS(clock_t* FPSCurr, clock_t* FPSOld)
{
	while (true)
	{
		*FPSCurr = clock();
		if (*FPSCurr - *FPSOld < 66)
		{
			*FPSOld = clock();
			break;
		}
	}
}