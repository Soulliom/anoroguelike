#include "../include/InputManager.h"

void InputManager::Pause(std::string text, const unsigned int key) {
	std::cout << std::endl << text << std::endl;
	Sleep(1000);

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