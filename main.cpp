#include "gClass.h";
#include <iostream>

void gotoXY(int x, int y);

int main() {
	GameManager gManager;

	gManager.Init();

	/*
			테스트용 FPS 계산에 쓰이는 변수
	*/
	clock_t tempcur;
	clock_t tempold = clock();
	int FrameCnt = 0;
	int exit_flag = 1; //프로그램 종료 판정

	while (exit_flag) {

		/*
			테스트용 FPS 계산
			참고: https://huiyu.tistory.com/entry/C%EC%96%B8%EC%96%B4%EB%A1%9C-%EA%B2%8C%EC%9E%84%EB%A7%8C%EB%93%A4%EA%B8%B0-3-%EB%A0%8C%EB%8D%94%EB%A7%81-%EA%B8%B0%EB%8A%A5-%EA%B5%AC%ED%98%84
		*/
		FrameCnt++;
		tempcur = clock();
		if (tempcur - tempold >= 1000)
		{
			gotoXY(3, 0);
			cout << "FPS: " << FrameCnt;
			gotoXY(3, 26);
			cout << "score: " <<gManager.Score() ;
			gotoXY(20, 26);
			cout << "Life: " << gManager.Life();

			tempold = clock();
			FrameCnt = 0;
		}
		gManager.FPS(); // Frame Per Second 조절
		gManager.Update();

		if (gManager.Life() == 0) {
			exit_flag = 0;
		}
	}

	cout << "프로그램 종료";
}