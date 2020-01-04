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
	bool contin = false;
	while (!contin) {
		int but = _getch();
		if (key != NULL) {
			if (key == but) {
				contin = true;
			}
		}
		else {
			contin = true;
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
void InputManager::SeedInput() {
	this->selectState.x = 0;
	this->selectState.y = 0;

	bool contin = false;
	while (!contin) {
		scene.SeedScene(input.getSelectStateY(), player.seed);

		int keyPress = _getch();
		input.WSNav(keyPress, 2);

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
				this->selectState.y = 0;
				contin = true;
			}
			break;
		}
	}

	this->selectState.x = 0;
	this->selectState.y = 0;
}

/* WEAPONS */
void InputManager::WepInput() {
	bool contin = false;

	selectState.y = 0;
	while (!contin) {
		scene.WeaponsScene(selectState.y);

		int keyPress = _getch();
		input.WSNav(keyPress, 3);
		switch (input.getSelectStateY()) {
		case 0: //Melee Shop
			if (keyPress == SPAC) {
				input.MeleeInput();
			}
			break;

		case 1: //Ranged Shop
			if (keyPress == SPAC) {
				input.RangedInput();
			}
			break;

		case 2: //Magic Shop
			if (keyPress == SPAC) {
				input.MagicInput();
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
		}
	}
	selectState.y = 0;
}

void InputManager::MeleeInput() {
	this->selectState.x = 0;
	this->selectState.y = 0;

	bool contin = false;
	while (!contin) {
		scene.MeleeScene(selectState.y, item.weapons);

		int keyPress = _getch();
		WSNav(keyPress, 5);
		switch (selectState.y) {
		case 0: //Rapier
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(0));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(0));
			}
			break;

		case 1: //Claymore
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(1));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(1));
			}
			break;

		case 2: //Dagger
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(2));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(2));
			}
			break;

		case 3: //Small Shield
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(3));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(3));
			}
			break;

		case 4: //Large Sheild
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(4));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(4));
			}
			break;

		case 5: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		
		}
	}

	this->selectState.x = 0;
	this->selectState.y = 0;
}

void InputManager::RangedInput() {
	this->selectState.x = 0;
	this->selectState.y = 0;

	bool contin = false;
	while (!contin) {
		scene.RangedScene(selectState.y, item.weapons);

		int keyPress = _getch();
		WSNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Recurve Bow
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(5));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(5));
			}
			break;

		case 1: //Longbow
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(6));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(6));
			}
			break;

		case 2: //Crossbow
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(7));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(7));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}

	this->selectState.x = 0;
	this->selectState.y = 0;
}

void InputManager::MagicInput() {
	this->selectState.x = 0;
	this->selectState.y = 0;

	bool contin = false;
	while (!contin) {
		scene.MagicScene(selectState.y, item.weapons);

		int keyPress = _getch();
		WSNav(keyPress, 4);
		switch (selectState.y) {
		case 0: //Sapphire Staff
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(8));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(8));
			}
			break;

		case 1: //Ruby Staff
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(9));
			}
			else if(keyPress == ENTR){
				contin = BuyWepInput(item.weapons.at(9));
			}
			break;

		case 2: //Book of Chaos
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(10));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(10));
			}
			break;

		case 3: //Book of Creation
			if (keyPress == SPAC) {
				contin = ViewWepInput(item.weapons.at(11));
			}
			else if (keyPress == ENTR) {
				contin = BuyWepInput(item.weapons.at(11));
			}
			break;

		case 4: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}

	this->selectState.x = 0;
	this->selectState.y = 0;
}

bool InputManager::ViewWepInput(Items::Weapon wep) {
	scene.ViewWeapon(wep);
	Pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::BuyWepInput(Items::Weapon wep){
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

void InputManager::WepInvInput() 
{
	this->selectState.x = 0;
	this->selectState.y = 0;

	bool contin = false;

	while (!contin) {

		if (!player.wep.empty()) {
			scene.ViewWepInv(selectState.y, selectState.x);

			int keyPress = _getch();
			WSNav(keyPress, 4);
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

			case 2: //Equip weapon
				if (keyPress == SPAC) {
					player.selectWep(player.wep.at(selectState.x));
				}
				break;

			case 3: // Delete Weapon
				// Delete item
				if (keyPress == SPAC) {
					if (player.wep.at(selectState.x) == player.selectedWep[0]) {
						player.selectedWep[0] = item.weapons.at(12);
					}
					else if (player.wep.at(selectState.x) == player.selectedWep[1]) {
						player.selectedWep[1] = item.weapons.at(12);
					}

					player.wep.erase(player.wep.begin() + selectState.x);
				}
				break;

			case 4: // Continue
				//Reset input and contin
				if (keyPress == SPAC) {
					this->selectState.x = 0;
					this->selectState.y = 0;

					contin = true;
				}
				break;
			}
		}
		else { //If player wep inv empty
			Pause("You do not have any weapons. Press [Space] to continue", 0, SPAC);
			this->selectState.x = 0;
			this->selectState.y = 0;

			contin = true;
		}
	}
}

/* ARMORS */
void InputManager::ArmInput() {
	this->selectState.x = 0;
	this->selectState.y = 0;
	
	bool contin = false;
	while (!contin) {
		scene.ArmorsScene(selectState.y, item.armors);

		int keyPress = _getch();
		WSNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Light Armor
			if (keyPress == SPAC) {
				contin = ViewArmInput(item.armors.at(0));
			}
			else if (keyPress == ENTR) {
				contin = BuyArmInput(item.armors.at(0));
			}
			break;

		case 1: //Medium Armor
			if (keyPress == SPAC) {
				contin = ViewArmInput(item.armors.at(1));
			}
			else if (keyPress == ENTR) {
				contin = BuyArmInput(item.armors.at(1));
			}
			break;

		case 2: //Heavy Armor
			if (keyPress == SPAC) {
				contin = ViewArmInput(item.armors.at(2));
			}
			else if (keyPress == ENTR) {
				contin = BuyArmInput(item.armors.at(2));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}

	this->selectState.x = 0;
	this->selectState.y = 0;
}

bool InputManager::ViewArmInput(Items::Armor arm) {
	scene.ViewArmor(arm);
	Pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::BuyArmInput(Items::Armor arm) {
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

void InputManager::ArmInvInput() {
	this->selectState.x = 0;
	this->selectState.y = 0;

	bool contin = false;
	
	while (!contin) {
		if (!player.arm.empty()) {
			scene.ViewArmInv(selectState.y, selectState.x);

			int keyPress = _getch();
			WSNav(keyPress, 4);
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

			case 2: //Equip Armor
				if (keyPress == SPAC) {
					player.selectArm(player.arm.at(selectState.x));
				}
				break;

			case 3: // Delete Armor
				// Delete item
				if (keyPress == SPAC) {
					if (player.arm.at(selectState.x) == player.selectedArm) {
						player.selectedArm = item.armors.at(3); //Armor is now empty armor
					}

					player.arm.erase(player.arm.begin() + selectState.x);
				}
				break;

			case 4: // Continue
				//Reset input and contin
				if (keyPress == SPAC) {
					this->selectState.x = 0;
					this->selectState.y = 0;

					contin = true;
				}
				break;
			}
		}
		else { //If player wep inv empty
			Pause("You do not have any armors. Press [Space] to continue", 0, SPAC);

			this->selectState.x = 0;
			this->selectState.y = 0;

			contin = true;
		}
	}
}

/* CONSUMABLES */
void InputManager::ConInput() {
	this->selectState.x = 0;
	this->selectState.y = 0;

	bool contin = false;
	while (!contin) {
		scene.ConsumeScene(selectState.y, item.consumes);

		int keyPress = _getch();
		WSNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Lesser healing potion
			if (keyPress == SPAC) {
				contin = ViewConInput(item.consumes.at(0));
			}
			else if (keyPress == ENTR) {
				contin = BuyConInput(item.consumes.at(0));
			}
			break;

		case 1: //Healing potion
			if (keyPress == SPAC) {
				contin = ViewConInput(item.consumes.at(1));
			}
			else if (keyPress == ENTR) {
				contin = BuyConInput(item.consumes.at(1));
			}
			break;

		case 2: //Bigger healing potion
			if (keyPress == SPAC) {
				contin = ViewConInput(item.consumes.at(2));
			}
			else if (keyPress == ENTR) {
				contin = BuyConInput(item.consumes.at(2));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}

	this->selectState.x = 0;
	this->selectState.y = 0;
}

bool InputManager::ViewConInput(Items::Consumable con) {
	scene.ViewConsume(con);
	Pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::BuyConInput(Items::Consumable con) {
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

void InputManager::ConInvInput() {
	this->selectState.x = 0;
	this->selectState.y = 0;

	bool contin = false;

	while(!contin)
	if (!player.con.empty()) {
		scene.ViewConInv(selectState.y, selectState.x);

		int keyPress = _getch();
		WSNav(keyPress, 4);
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

		case 2: //Use Consume
			if (keyPress == SPAC) {
				player.useConsume(player.con.at(selectState.x), selectState.x);
			}
			break;

		case 3: // Delete Consume
			// Delete item
			if (keyPress == SPAC) {
				player.con.erase(player.con.begin() + selectState.x);
			}
			break;

		case 4: // Continue
			//Reset input and contin
			if (keyPress == SPAC) {
				this->selectState.x = 0;
				this->selectState.y = 0;

				contin = true;
			}
			break;
		}
	}
	else { //If player wep inv empty
		Pause("You do not have any consumables. Press [Space] to continue", 0, SPAC);

		this->selectState.x = 0;
		this->selectState.y = 0;

		contin = true;
	}
} 

//Inventory Input/Scene
void InputManager::InventoryInput() {
	this->selectState.x = 0;
	this->selectState.y = 0;

	bool contin = false;
	while (!contin) {
		scene.ViewInventory(selectState.y);

		int keyPress = _getch();
		WSNav(keyPress, 3);

		switch (selectState.y) {
		case 0: // Weapons Inventory
			if (keyPress == SPAC) {
				WepInvInput();
				contin = false;
			}
			break;

		case 1: // Armor
			if (keyPress == SPAC) {
				input.ArmInvInput();
				contin = false;
			}
			break;

		case 2: // Consumables
			if (keyPress == SPAC) {
				input.ConInvInput();
				contin = false;
			}
			break;

		case 3: // Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}

	this->selectState.x = 0;
	this->selectState.y = 0;
}

/* Inputs for Scrolls in Scenes */
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