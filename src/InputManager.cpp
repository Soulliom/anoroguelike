#include "../include/InputManager.h"

extern Player player;

/* Pauses, Inputs, Navigations.*/
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
		else {
			_getch();
			pressed = true;
		}
	}
}

std::string InputManager::StringInput(std::string text) {
	//define, get, return string output - print text param
	std::string output;
	std::cout << "\n" << text << "\n";
	std::cin >> output;
	return output;
}

int InputManager::IntInput(std::string text) {
	//define, get, check and return output - print text param
	long long output = 0;
	std::cout << "\n" << text << "\n";
	std::cin.clear();
		std::cin >> output;

	if (output > 0) {
		return output;
	}
	else {
		while (std::cin.fail()) {
			//If invalid, return false, pause and clear cin
			Pause("ERROR: No negative numbers or characters! -- Press [Space] to continue", 1, SPAC);
			std::cin.clear();
			std::cin.ignore(256, '\n');
			return 0;
		}
	}
	return 0;
}

/* Menu Navigation Functions */
void InputManager::WSNav(unsigned int input, const unsigned int max) {
	if (selectState > 0) {
		if (input == WKEY) {
			selectState--;
		}
	}
	if(selectState < max){
		if (input == SKEY) {
			selectState++;
		}
	}
}

void InputManager::ADNav(unsigned int input, const unsigned int max) {
	if (selectState > 0) {
		if (input == AKEY) {
			selectState--;
		}
	}
	if (selectState < max) {
		if (input == DKEY) {
			selectState++;
		}
	}
}

void InputManager::WASDNav() {

}

/* Inputs for Specific Scenes*/
bool InputManager::DiffInput(int keyPress) {
	WSNav(keyPress, 3);

	switch (selectState) {
	case 0: //Easy
		if (keyPress == SPAC) {
			player.diff = "Easy";
			player.diffRate = 0.80f;
		}
		break;
	case 1: //Medium
		if (keyPress == SPAC) {
			player.diff = "Normal";
			player.diffRate = 1.00f;
		}
		break;
	case 2: //Hard
		if (keyPress == SPAC) {
			player.diff = "Hard";
			player.diffRate = 1.20f;
		}
		break;
	case 3: //Continue
		if (keyPress == SPAC) {
			selectState = 0;
			return true;
		}
		break;
	}
	return false;
}

bool InputManager::SeedInput(int keyPress) {
	WSNav(keyPress, 2);

	switch (selectState) {
	case 0: // Randomize Seed
		if (keyPress == SPAC) {
			player.seed = rand() % 99999999 + 1111;
		}
		break;
	case 1: // Input Custom Seed
		if (keyPress == SPAC) {
			player.seed = IntInput("Enter seed, then press [Enter]");
		}
		break;
	case 2: // Continue
		if (keyPress == SPAC) {
			selectState = 0;
			return true;
		}
		break;
	}
	return false;
}

/* Setters / Getters */
void InputManager::setSelectState(unsigned int state) {
	selectState = state;
}

int InputManager::getSelectState() {
	return selectState;
}