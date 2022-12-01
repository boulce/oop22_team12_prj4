#include "gClass.h";

int main() {
	GameManager gManager;
	//clock_t FPSCurr, FPSOld;

	//FPSOld = clock();

	gManager.Init();
	while (true) {
		gManager.Update();
		gManager.FPS(/*&FPSCurr, &FPSOld*/); // Frame Per Second Á¶Àý
	}
}