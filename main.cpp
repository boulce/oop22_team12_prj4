#include "gClass.h"


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
	

	while (true) {


		

		/*
			테스트용 FPS 계산
			참고: https://huiyu.tistory.com/entry/C%EC%96%B8%EC%96%B4%EB%A1%9C-%EA%B2%8C%EC%9E%84%EB%A7%8C%EB%93%A4%EA%B8%B0-3-%EB%A0%8C%EB%8D%94%EB%A7%81-%EA%B8%B0%EB%8A%A5-%EA%B5%AC%ED%98%84
		*/
		FrameCnt++;
		tempcur = clock();
		if (tempcur - tempold >= 10) //업데이트 주기 설정? 1000->10으로 바꾸니 life, score 변경이 자연스러워졌는데 FrameCnt가 중요한거면 life, score에 대한 다른 구현방법 생각해야함
		{
			gotoXY(3, 0);
			cout << "FPS: " << FrameCnt; 
			gotoXY(3, 26);
			cout << "score: " <<gManager.Score() ;
			gotoXY(15, 26);
			setColor(RED);
			cout << "Life: " << gManager.Life();
			setColor(WHITE);
			
			

			tempold = clock();
			FrameCnt = 0;
		}
		gManager.is_exit(); //Life가 0이되는 순간이 gManager.Update인데 Life가 0인걸 위에서 표시하고 exit에 대한 체크를 해야함.
		gManager.FPS(); // Frame Per Second 조절
		gManager.Update();
		
		
	}

	cout << "프로그램 종료";
}