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
			cout << "���Ͽ��� ����";
			
		}
		char temp[100]; //������ ū ����, ���Ͽ��� ���پ� �޾ƿö� �ӽ÷� ���
		while (input_stream.getline(temp, 100)) {		
			w_list.push_back(string(temp));
		}
		
		input_stream.close();
	}

	void w_list_say() { //�迭 Ȯ�ο�, wordlist3000.txt���� �о�� ��� �ܾ�
		for (int i = 0; i < w_list.size(); i++) {
			cout << w_list[i]<<endl;
		}
	}

	void falling_word_say() { //�迭 Ȯ�ο�, w_list���� ��������Ǿ� ����Ǿ��ִ�. �ҳ��⿡�� �������� �ܾ���� �迭�̴�.
		this->add_falling_word();
		for (int i = 0; i < falling_word.size(); i++) {
			cout << falling_word[i] << endl;
		}
	}

	
	void add_falling_word() { //�� �޼ҵ带 �����ϸ� �����ܾ� �ϳ��� �����ͼ� falling_word�� �߰���
		random_device  rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(0, 3000);

		falling_word.push_back(w_list[dis(gen)]);
		
	}

//-------------------���� �޼ҵ�� ���� Ŭ������ ������ ���¸� ���� �������� ��--------------------------------------

	void input_inserted(string input) { //����ڰ� typing box���� ������ �Է����� ��, �������� ������ ������ �ϴ� string���� ��
		
		vector<string>::iterator iter;

		for (iter = falling_word.begin(); iter != falling_word.end(); iter++) {
			if (input == *iter) {
				falling_word.erase(iter);
				//score++; //���� �߰�
			}
	}
	}





};




void main() {

	
	WordManager wm;
	
	wm.falling_word_say();
}