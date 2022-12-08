﻿#include "gClass.h"


void GameManager::Init() {
	word_manager.add_falling_word(ui.get_main_box_width()); // 랜덤으로 단어 추가

	vector<Word>& falling_word_list = word_manager.get_falling_word_list();


	falling_word_list[0].Word_Draw(ui.get_main_box_x(), ui.get_main_box_y()); // 처음 생성된 단어 그리기
	
	
}


void GameManager::Update() {
	ui.Draw_Score();
	ui.Draw_Life();
	vector<Word>& falling_word_list = word_manager.get_falling_word_list();
	system_time = clock(); // 시스템 시간 갱신

	ui.keyboardEvent(falling_word_list);
	for (int i = 0; i < falling_word_list.size(); i++) {
		if (system_time - falling_word_list[i].get_last_update_time() >= falling_word_list[i].get_update_time_interval()) 
		{
			falling_word_list[i].Word_Erase(ui.get_main_box_x(), ui.get_main_box_y());
			// 단어가 게임 오버 라인에 닿으면 사라진다
			if (falling_word_list[i].get_y() >= ui.get_game_over_line_y()) {

				if (falling_word_list[i].get_color() == RED) { //붉은단어가 내려온거면 2점을 깎는다.
					ui.down_life(2);
				}
				else ui.down_life(1); //붉은 단어가 아니면 1점만 깎는다.



				falling_word_list.erase(falling_word_list.begin() + i);
				i--;
				
				continue;
			}
			falling_word_list[i].set_y(falling_word_list[i].get_y() + falling_word_list[i].get_speed());
			falling_word_list[i].set_last_update_time(system_time);
			falling_word_list[i].Word_Draw(ui.get_main_box_x(), ui.get_main_box_y());
		} // 각각의 단어가 자신의 update_time_interval 후에 좌표가 갱신된다
	}
	if (system_time - word_manager.get_last_word_birth_time() >= word_manager.get_birth_time_interval()) {
		word_manager.add_falling_word(ui.get_main_box_width()); // 랜덤으로 단어 추가
		falling_word_list[falling_word_list.size() - 1].Word_Draw(ui.get_main_box_x(), ui.get_main_box_y()); // 처음 생성된 단어 그리기
		word_manager.set_last_word_birth_time(system_time);
	}	// birth_time_interval 후에 단어가 생성된다
}

void GameManager::FPS()
{
	clock_t FPSOld = clock();
	clock_t FPSCurr;

	while (true)
	{
		FPSCurr = clock();

		if (FPSCurr - FPSOld > 10)
		{
			break;
		}
	}
}

void GameManager::is_exit()
{
	if (ui.get_life() <= 0) {
		gotoXY(15, 30);
		cout << "\n\n\n\n 게임 종료\n";
		exit(0);



	}
}


