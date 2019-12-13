#include "../include/InputManager.h"
#include "../include/Player.h"

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
	int output = 0;
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
void InputManager::WSNav(unsigned int input, const int max) {
	if (input == WKEY) {
		selectState.y--;
		if (selectState.y < 0) {
			selectState.y = max;
		}
	}
	
	if (input == SKEY) {
		selectState.y++;
		if (selectState.y > max) {
			selectState.y = 0;
		}
	}
}

void InputManager::ADNav(unsigned int input, const int max) {
	if (input == AKEY) {
		selectState.x--;
		if (selectState.x < 0) {
			selectState.x = max;
		}
	}
	
	if (input == DKEY) {
		selectState.x++;
		if (selectState.x > max) {
			selectState.x = 0;
		}
	}
}

void InputManager::WASDNav() {

}

/* Inputs for Specific Scenes*/
bool InputManager::SeedInput(int keyPress) {
	WSNav(keyPress, 2);

	switch (selectState.y) {
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
			selectState.y = 0;
			return true;
		}
		break;
	}
	return false;
}

/* Inputs for Options in Scenes */

void InputManager::DiffInput(selectStateStruct selectState) {
	switch (selectState.x) {
	case 0:
		player.diff = "Easy";
		player.diffRate = 0.80f;
		break;
	case 1:
		player.diff = "Normal";
		player.diffRate = 1.00f;
		break;
	case 2:
		player.diff = "Hard";
		player.diffRate = 1.20f;
		break;
	}
}

void InputManager::RaceInput(selectStateStruct selectState) {
	switch (selectState.x) {
	case 0:
		player.ch.raceStr = "Elf";
		player.ch.race = Character::Elf;
		break;

	case 1:
		player.ch.raceStr = "Orc";
		player.ch.race = Character::Orc;
		break;

	case 2:
		player.ch.raceStr = "Human";
		player.ch.race = Character::Human;
		break;

	case 3:
		player.ch.raceStr = "Goblin";
		player.ch.race = Character::Goblin;
		break;

	case 4:
		player.ch.raceStr = "Dwarf";
		player.ch.race = Character::Dwarf;
		break;

	case 5:
		player.ch.raceStr = "Gnome";
		player.ch.race = Character::Gnome;
		break;
	}
}

void InputManager::ClasInput(selectStateStruct selectState) {
	switch (selectState.x) {
	case 0:
		player.ch.clasStr = "Warrior";
		player.ch.clas = Character::Warrior;
		break;
	case 1:
		player.ch.clasStr = "Ranger";
		player.ch.clas = Character::Ranger;
		break;
	case 2:
		player.ch.clasStr = "Magician";
		player.ch.clas = Character::Magician;
		break;
	case 3:
		player.ch.clasStr = "Bandit";
		player.ch.clas = Character::Bandit;
		break;
	}
}

/* Setters / Getters */
void InputManager::setSelectStateX(unsigned int x) {
	selectState.x = x;
}

void InputManager::setSelectStateY(unsigned int y) {
	selectState.y = y;
}

int InputManager::getSelectStateX() {
	return selectState.x;
}
int InputManager::getSelectStateY() {
	return selectState.y;
}