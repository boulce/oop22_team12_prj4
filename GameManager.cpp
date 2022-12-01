#include "gClass.h";
#include <iostream>
#include <time.h>

void GameManager::Init() {

	Word test("abcde", 10, 2, 1);
	Word test2("abcde222222222", 20, 5, 1);
	word_manager.get_current_word_list().push_back(test);
	word_manager.get_current_word_list().push_back(test2);
	for (int i = 0; i < word_manager.get_current_word_list().size(); i++) {
		word_manager.get_current_word_list()[i].Word_Draw(ui.get_main_box_x(), ui.get_main_box_y());
	}

}

void GameManager::Update() {
	for (int i = 0; i < word_manager.get_current_word_list().size(); i++) {
		word_manager.get_current_word_list()[i].Word_Erase(ui.get_main_box_x(), ui.get_main_box_y());
		word_manager.get_current_word_list()[i].set_y(word_manager.get_current_word_list()[i].get_y() + word_manager.get_current_word_list()[i].get_speed());
		word_manager.get_current_word_list()[i].Word_Draw(ui.get_main_box_x(), ui.get_main_box_y());
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