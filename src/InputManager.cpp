#include "../include/InputManager.h"

void InputManager::Pause(std::string text, const unsigned int seconds, const unsigned int key) {
	//Sleep
	Sleep(seconds * 1000);

	//Collects spammed keys pressed during sleep
	while (_kbhit()) {
		_getch();
	}

	//Print text
	std::cout << std::endl << text << std::endl;

	//If correct key is pressed continue. (Unless NULL then continue otherwise)
	bool pressed = false;
	while (!pressed) {
		if (key != NULL) {
			if (key == _getch()) {
				pressed = true;
			}
		}
		if (key == NULL) {
			_getch();
			pressed = true;
		}
		
	}
}