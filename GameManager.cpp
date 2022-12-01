#include "gClass.h";
#include <iostream>
#include <time.h>

void GameManager::Init() {

}

void GameManager::Update() {
	word_manager.add_falling_word(ui.get_main_box_width()); // 랜덤으로 단어 추가
	vector<Word>& falling_word_list = word_manager.get_falling_word_list();
	for (int i = 0; i < falling_word_list.size(); i++) {
		falling_word_list[i].Word_Erase(ui.get_main_box_x(), ui.get_main_box_y());
		falling_word_list[i].set_y(falling_word_list[i].get_y() + falling_word_list[i].get_speed());
		falling_word_list[i].Word_Draw(ui.get_main_box_x(), ui.get_main_box_y());

		// 단어가 게임 오버 라인에 닿으면 사라진다
		if (falling_word_list[i].get_y() >= ui.get_game_over_line_y()) {
			falling_word_list[i].Word_Erase(ui.get_main_box_x(), ui.get_main_box_y());
			falling_word_list.erase(falling_word_list.begin() + i);
		}
	}


}

void GameManager::FPS()
{
	clock_t FPSOld = clock();
	clock_t FPSCurr;
	while (true)
	{
		FPSCurr = clock();
		if (FPSCurr - FPSOld > 66)
		{
			break;
		}
	}
}