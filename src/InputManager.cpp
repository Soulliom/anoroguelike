#include "../include/InputManager.h"
#include "../include/Player.h"
#include "../include/SceneManager.h"

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

/* Inputs for Specific Scenes*/
bool InputManager::SeedInput(int keyPress) {
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

/* WEAPONS */
void InputManager::MeleeInput(int keyPress) {
	bool contin = false;
	while (!contin) {
		scene.MeleeScene(selectState.y, item.weapons);

		keyPress = _getch();
		WSNav(keyPress, 5);
		switch (selectState.y) {
		case 0: //Rapier
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(0));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(0));
			}
			break;

		case 1: //Claymore
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(1));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(1));
			}
			break;

		case 2: //Dagger
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(2));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(2));
			}
			break;

		case 3: //Small Shield
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(3));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(3));
			}
			break;

		case 4: //Large Sheild
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(4));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(4));
			}
			break;

		case 5: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		
		}
	}
}

void InputManager::RangedInput(int keyPress) {
	bool contin = false;

	while (!contin) {
		scene.RangedScene(selectState.y, item.weapons);

		keyPress = _getch();
		WSNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Recurve Bow
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(5));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(5));
			}
			break;

		case 1: //Longbow
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(6));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(6));
			}
			break;

		case 2: //Crossbow
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(7));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(7));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}
}

void InputManager::MagicInput(int keyPress) {
	bool contin = false;

	while (!contin) {
		scene.MagicScene(selectState.y, item.weapons);

		keyPress = _getch();
		WSNav(keyPress, 4);
		switch (selectState.y) {
		case 0: //Sapphire Staff
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(8));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(8));
			}
			break;

		case 1: //Ruby Staff
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(9));
			}
			else if(keyPress == ENTR){
				contin = BuyWepInput(keyPress, item.weapons.at(9));
			}
			break;

		case 2: //Book of Chaos
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(10));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(10));
			}
			break;

		case 3: //Book of Creation
			if (keyPress == SPAC) {
				contin = ViewWepInput(keyPress, item.weapons.at(11));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(keyPress, item.weapons.at(11));
			}
			break;

		case 4: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}
}

bool InputManager::ViewWepInput(int keyPress, Items::Weapon wep) {
	scene.ViewWeapon(wep);
	Pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::BuyWepInput(int keyPress, Items::Weapon wep){
	//Add weapon to inventory, subtract gold by cost
	if (player.gold >= wep.cost) {
		player.gold -= wep.cost;
		player.aquireWep(wep);
		Pause("You bought a weapon! Press [Space] to continue!", 0, SPAC); 
		return true;
	}
	else {
		Pause("NOT ENOUGH GOLD: Press [Space] to Continue!", 0, SPAC);
		return false;
	}
}

bool InputManager::WepInvInput(int keyPress) {
	if (!player.wep.empty()) {
		scene.ViewWepInv(selectState.y, selectState.x);

		keyPress = _getch();
		WSNav(keyPress, 3);
		switch (selectState.y) {
		case 0: // Wep Select
			ADNav(keyPress, player.wep.size() - 1);
			break;
		case 1: // Wep Inspect
			if (keyPress == SPAC) {
				scene.ViewWeapon(player.wep.at(selectState.x));
				Pause("Press [Space] to continue", 2, SPAC);
			}
			break;
		case 2: // Delete Weapon
			// Delete item
			if (keyPress == SPAC) {
				player.wep.erase(player.wep.begin() + selectState.x);
				return true;
			}
			break;
		case 3: // Continue
			//Reset input and contin
			if (keyPress == SPAC) {
				return true;
			}
			break;
		}
		return false;
	}
	else { //If player wep inv empty
		Pause("You do not have any weapons. Press [Space] to continue", 0, SPAC);
		return true;
	}
}

/* ARMORS */
void InputManager::ArmInput(int keyPress) {
	bool contin = false;

	while (!contin) {
		scene.ArmorsScene(selectState.y, item.armors);

		keyPress = _getch();
		WSNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Light Armor
			if (keyPress == SPAC) {
				contin = ViewArmInput(keyPress, item.armors.at(0));
			}
			else if (keyPress == ENTR) {
				contin = BuyArmInput(keyPress, item.armors.at(0));
			}
			break;

		case 1: //Medium Armor
			if (keyPress == SPAC) {
				contin = ViewArmInput(keyPress, item.armors.at(1));
			}
			else if (keyPress == ENTR) {
				contin = BuyArmInput(keyPress, item.armors.at(1));
			}
			break;

		case 2: //Heavy Armor
			if (keyPress == SPAC) {
				contin = ViewArmInput(keyPress, item.armors.at(2));
			}
			else if (keyPress == ENTR) {
				contin = BuyArmInput(keyPress, item.armors.at(2));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}
}

bool InputManager::ViewArmInput(int keyPress, Items::Armor arm) {
	scene.ViewArmor(arm);
	Pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::BuyArmInput(int keyPress, Items::Armor arm) {
	//Add weapon to inventory, subtract gold by cost
	if (player.gold >= arm.cost) {
		player.gold -= arm.cost;
		player.aquireArm(arm);
		Pause("You bought armor! Press [Space] to continue!", 0, SPAC);
		return true;
	}
	else {
		Pause("NOT ENOUGH GOLD: Press [Space] to Continue!", 0, SPAC);
		return false;
	}
}

bool InputManager::ArmInvInput(int keyPress) {
	if (!player.arm.empty()) {
		scene.ViewArmInv(selectState.y, selectState.x);

		keyPress = _getch();
		WSNav(keyPress, 3);
		switch (selectState.y) {
		case 0: // Armor Select
			ADNav(keyPress, player.arm.size() - 1);
			break;

		case 1: // Armor Inspect
			if (keyPress == SPAC) {
				scene.ViewArmor(player.arm.at(selectState.x));
				Pause("Press [Space] to continue", 2, SPAC);
			}
			break;

		case 2: // Delete Armor
			// Delete item
			if (keyPress == SPAC) {
				player.arm.erase(player.arm.begin() + selectState.x);
				return true;
			}
			break;

		case 3: // Continue
			//Reset input and contin
			if (keyPress == SPAC) {
				return true;
			}
			break;
		}
		return false;
	}
	else { //If player wep inv empty
		Pause("You do not have any armors. Press [Space] to continue", 0, SPAC);
		return true;
	}
}

void InputManager::ConInput(int keyPress) {
	bool contin = false;

	while (!contin) {
		scene.ConsumeScene(selectState.y, item.consumes);

		keyPress = _getch();
		WSNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Light Armor
			if (keyPress == SPAC) {
				contin = ViewConInput(keyPress, item.consumes.at(0));
			}
			else if (keyPress == ENTR) {
				contin = BuyConInput(keyPress, item.consumes.at(0));
			}
			break;

		case 1: //Medium Armor
			if (keyPress == SPAC) {
				contin = ViewConInput(keyPress, item.consumes.at(1));
			}
			else if (keyPress == ENTR) {
				contin = BuyConInput(keyPress, item.consumes.at(1));
			}
			break;

		case 2: //Heavy Armor
			if (keyPress == SPAC) {
				contin = ViewConInput(keyPress, item.consumes.at(2));
			}
			else if (keyPress == ENTR) {
				contin = BuyConInput(keyPress, item.consumes.at(2));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}
}

bool InputManager::ViewConInput(int keyPress, Items::Consumable con) {
	scene.ViewConsume(con);
	Pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::BuyConInput(int keyPress, Items::Consumable con) {
	//Add weapon to inventory, subtract gold by cost
	if (player.gold >= con.cost) {
		player.gold -= con.cost;
		player.aquireCon(con);
		Pause("You bought a Consumable! Press [Space] to continue!", 0, SPAC);
		return true;
	}
	else {
		Pause("NOT ENOUGH GOLD: Press [Space] to Continue!", 0, SPAC);
		return false;
	}
}

bool InputManager::ConInvInput(int keyPress) {
	if (!player.con.empty()) {
		scene.ViewConInv(selectState.y, selectState.x);

		keyPress = _getch();
		WSNav(keyPress, 3);
		switch (selectState.y) {
		case 0: // Consume Select
			ADNav(keyPress, player.con.size() - 1);
			break;
		case 1: // Consume Inspect
			if (keyPress == SPAC) {
				scene.ViewConsume(player.con.at(selectState.x));
				Pause("Press [Space] to continue", 2, SPAC);
			}
			break;

		case 2: // Consume Armor
			// Delete item
			if (keyPress == SPAC) {
				player.con.erase(player.con.begin() + selectState.x);
				return true;
			}
			break;

		case 3: // Continue
			//Reset input and contin
			if (keyPress == SPAC) {
				return true;
			}
			break;

		}
		return false;
	}
	else { //If player wep inv empty
		Pause("You do not have any consumables. Press [Space] to continue", 0, SPAC);
		return true;
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