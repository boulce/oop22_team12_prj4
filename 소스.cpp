#include <iostream>
#include <vector>	
#include <string>
#include <fstream>
#include <random>


using namespace std;



class WordManager {
private:
	vector<string> w_list;
	vector <string> falling_word;

public:
	WordManager() {
		ifstream input_stream;
		input_stream.open("wordlist3000.txt");
		if (input_stream.fail()) {
			cout << "파일열기 실패";
			
		}
		char temp[100]; //적당히 큰 숫자, 파일에서 한줄씩 받아올때 임시로 사용
		while (input_stream.getline(temp, 100)) {		
			w_list.push_back(string(temp));
		}
		
		input_stream.close();
	}

	void w_list_say() { //배열 확인용, wordlist3000.txt에서 읽어온 모든 단어
		for (int i = 0; i < w_list.size(); i++) {
			cout << w_list[i]<<endl;
		}
	}

	void falling_word_say() { //배열 확인용, w_list에서 랜덤추출되어 저장되어있다. 소나기에서 떨어지는 단어들의 배열이다.
		this->add_falling_word();
		for (int i = 0; i < falling_word.size(); i++) {
			cout << falling_word[i] << endl;
		}
	}

	
	void add_falling_word() { //이 메소드를 실행하면 랜덤단어 하나만 가져와서 falling_word에 추가됨
		random_device  rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(0, 3000);

		falling_word.push_back(w_list[dis(gen)]);
		
	}

//-------------------이하 메소드는 사용될 클래스의 구조나 상태를 봐서 가져가면 됨--------------------------------------

	void input_inserted(string input) { //사용자가 typing box에서 내용을 입력했을 때, 어떤방식으로 올지는 모르지만 일단 string으로 함
		
		vector<string>::iterator iter;

		for (iter = falling_word.begin(); iter != falling_word.end(); iter++) {
			if (input == *iter) {
				falling_word.erase(iter);
				//score++; //점수 추가
			}
	}
	}





};




void main() {

	
	WordManager wm;
	
	wm.falling_word_say();
}