#include "gClass.h"
#include <fstream>
#include <random>
#include <vector>

WordManager::WordManager() {
	ifstream input_stream;
	input_stream.open("wordlist3000.txt");
	if (input_stream.fail()) {
		return;
	}
	char temp[100]; //적당히 큰 숫자, 파일에서 한줄씩 받아올때 임시로 사용
	while (input_stream.getline(temp, 100)) {
		load_word_list.push_back(string(temp));
	}

	input_stream.close();
}

void WordManager::add_falling_word(int main_box_width) { // 이 메소드를 실행하면 랜덤단어 하나만 가져와서 falling_word_list에 추가됨
	random_device  rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis_word(0, 3000 - 1);
	string selected_word = load_word_list[dis_word(gen)];

	uniform_int_distribution<int> dis_x(1, main_box_width - (int)selected_word.size() - 1); // 단어의 랜덤 x좌표를 정한다. Main Box 밖으로 나가지않게 정한다.
	int selected_x = dis_x(gen);
	
	falling_word_list.push_back(Word(selected_word, selected_x, 1, 1));

}