#include "gClass.h";

int main() {
	GameManager gManager;

	gManager.Init();
	while (true) {
		gManager.Update();
		gManager.FPS(); // Frame Per Second Á¶Àý
	}
}