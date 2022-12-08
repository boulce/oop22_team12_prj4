﻿#include "gClass.h"


WordManager::WordManager() {
	ifstream input_stream;
	input_stream.open("wordlist3000.txt");
	if (input_stream.fail()) {
		return;
	}
	char temp[100]; //적당히 큰 숫자, 파일에서 한줄씩 받아올때 임시로 사용
	total_word_cnt = 0;
	while (input_stream.getline(temp, 100)) {
		load_word_list.push_back(string(temp));
		total_word_cnt++;
	}

	input_stream.close();

	last_word_birth_time = clock();
	birth_time_interval = (clock_t)2000;
}

void WordManager::add_falling_word(int main_box_width) { // 이 메소드를 실행하면 랜덤단어 하나만 가져와서 falling_word_list에 추가됨
	random_device  rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis_word(0, total_word_cnt - 1);
	string selected_word = load_word_list[dis_word(gen)];

	uniform_int_distribution<int> dis_x(1, main_box_width - (int)selected_word.size() - 1); // 단어의 랜덤 x좌표를 정한다. Main Box 밖으로 나가지않게 정한다.
	int selected_x = dis_x(gen);

	uniform_int_distribution<clock_t> dis_update_interval(500, 500); // 단어 업데이트 시간 간격을 랜덤으로 정한다.
																	   // 그러나 각 단어의 속도가 다르면 단어가 겹치는 문제가 생기고
																	   // 나중에 만들어졌던 같은 이름의 단어가 먼저 만들어지는 같은 이름의
																	   // 단어들을 추월 했을 때 더 밑에 있는 단어 없애도록 구현해야함
																	   // 그래서 일단 속도가 동일하다고 가정
	clock_t selected_interval = dis_update_interval(gen);

	uniform_int_distribution<int> dis_color(0, 99); //색상을 정하기 위한 랜덤
	int temp_color_prob = dis_color(gen);
	Color temp_color = WHITE;
	if (temp_color_prob < 10) temp_color = BLUE; //파란색글자는 맞추면 점수 3점줌
	else if (temp_color_prob < 20) temp_color = RED; //붉은 글자는 틀리면 life 2점깎임

	
	falling_word_list.push_back(Word(selected_word, selected_x, 1, 1, selected_interval,temp_color));

}