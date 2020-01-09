#include "../include/InputManager.h"
#include "../include/GameManager.h"
#include "../include/Player.h"
#include "../include/SceneManager.h"

//Reset selectState structs
void InputManager::SelectState::reset() {
	x = 0;
	y = 0;
}

/* Pauses, Inputs, Navigations.*/
void InputManager::pause(std::string text, const unsigned int seconds, const unsigned int key) {
	//Sleep
	Sleep(seconds * 1000);

	//Collects spammed keys pressed during sleep
	while (_kbhit()) {
		_getch();
	}

	//Print text
	std::cout << std::endl << text << std::endl;

	//If correct key is pressed continue. (Unless NULL then continue otherwise)
	bool b_contin = false;
	while (!b_contin) {
		int but = _getch();
		if (key != NULL) {
			if (key == but) {
				b_contin = true;
			}
		}
		else {
			b_contin = true;
		}
	}
}

std::string InputManager::stringInput(std::string text) {
	//define, get, return string output - print text param
	std::string output;
	std::cout << "\n" << text << "\n";
	std::cin >> output;
	return output;
}

int InputManager::intInput(std::string text) {
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
			pause("ERROR: No negative numbers or characters! -- Press [Space] to continue", 1, SPAC);
			std::cin.clear();
			std::cin.ignore(256, '\n');
			return 0;
		}
	}
	return 0;
}

/* Menu Navigation Functions */
void InputManager::upDownNav(unsigned int g_Input, const int max) {
	if (g_Input == WKEY) {
		selectState.y--;
		if (selectState.y < 0) {
			selectState.y = max;
		}
	}
	
	if (g_Input == SKEY) {
		selectState.y++;
		if (selectState.y > max) {
			selectState.y = 0;
		}
	}
}

void InputManager::leftRightNav(unsigned int g_Input, const int max) {
	if (g_Input == AKEY) {
		selectState.x--;
		if (selectState.x < 0) {
			selectState.x = max;
		}
	}
	
	if (g_Input == DKEY) {
		selectState.x++;
		if (selectState.x > max) {
			selectState.x = 0;
		}
	}
}

/* Inputs for Specific Scenes*/
void InputManager::seedInput() {
	selectState.reset();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.seedScene(g_Input.getSelectStateY(), g_Game.seed);

		int keyPress = _getch();
		g_Input.upDownNav(keyPress, 2);

		switch (selectState.y) {
		case 0: // Randomize Seed
			if (keyPress == SPAC) {
				g_Game.seed = rand() % 99999999 + 1111;
			}
			break;
		case 1: // Input Custom Seed
			if (keyPress == SPAC) {
				g_Game.seed = intInput("Enter seed, then press [Enter]");
			}
			break;
		case 2: // Continue
			if (keyPress == SPAC) {
				this->selectState.y = 0;
				b_contin = true;
			}
			break;
		}
	}

	selectState.reset();
}

/* WEAPONS */
void InputManager::wepInput() {
	bool b_contin = false;

	selectState.reset();
	while (!b_contin) {
		g_Scene.weaponsScene(selectState.y);

		int keyPress = _getch();
		g_Input.upDownNav(keyPress, 3);
		switch (g_Input.getSelectStateY()) {
		case 0: //Melee Shop
			if (keyPress == SPAC) {
				g_Input.meleeInput();
			}
			break;

		case 1: //Ranged Shop
			if (keyPress == SPAC) {
				g_Input.rangedInput();
			}
			break;

		case 2: //Magic Shop
			if (keyPress == SPAC) {
				g_Input.magicInput();
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
		}
	}
	selectState.reset();
}

void InputManager::meleeInput() {
	selectState.reset();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.meleeScene(selectState.y, g_Item.weapons);

		int keyPress = _getch();
		upDownNav(keyPress, 5);
		switch (selectState.y) {
		case 0: //Rapier
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(0));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(0));
			}
			break;

		case 1: //Claymore
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(1));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(1));
			}
			break;

		case 2: //Dagger
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(2));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(2));
			}
			break;

		case 3: //Small Shield
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(3));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(3));
			}
			break;

		case 4: //Large Sheild
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(4));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(4));
			}
			break;

		case 5: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		
		}
	}

	selectState.reset();
}

void InputManager::rangedInput() {
	selectState.reset();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.rangedScene(selectState.y, g_Item.weapons);

		int keyPress = _getch();
		upDownNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Recurve Bow
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(5));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(5));
			}
			break;

		case 1: //Longbow
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(6));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(6));
			}
			break;

		case 2: //Crossbow
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(7));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(7));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	selectState.reset();
}

void InputManager::magicInput() {
	selectState.reset();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.magicScene(selectState.y, g_Item.weapons);

		int keyPress = _getch();
		upDownNav(keyPress, 4);
		switch (selectState.y) {
		case 0: //Sapphire Staff
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(8));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(8));
			}
			break;

		case 1: //Ruby Staff
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(9));
			}
			else if(keyPress == ENTR){
				b_contin = buyWepInput(g_Item.weapons.at(9));
			}
			break;

		case 2: //Book of Chaos
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(10));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(10));
			}
			break;

		case 3: //Book of Creation
			if (keyPress == SPAC) {
				b_contin = viewWepInput(g_Item.weapons.at(11));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWepInput(g_Item.weapons.at(11));
			}
			break;

		case 4: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	selectState.reset();
}

bool InputManager::viewWepInput(Items::Weapon wep) {
	g_Scene.viewWeapon(wep);
	pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::buyWepInput(Items::Weapon wep){
	//Add weapon to inventory, subtract gold by cost
	if (g_Player.gold >= wep.cost) {
		g_Player.gold -= wep.cost;
		g_Player.aquireWep(wep);
		pause("You bought a weapon! Press [Space] to continue!", 0, SPAC); 
		return true;
	}
	else {
		pause("NOT ENOUGH GOLD: Press [Space] to Continue!", 0, SPAC);
		return false;
	}
}

void InputManager::wepInvInput() 
{
	selectState.reset();

	bool b_contin = false;

	while (!b_contin) {

		if (!g_Player.wep.empty()) {
			g_Scene.viewWepInv(selectState.y, selectState.x);

			int keyPress = _getch();
			upDownNav(keyPress, 4);
			switch (selectState.y) {
			case 0: // Wep Select
				leftRightNav(keyPress, g_Player.wep.size() - 1);
				break;

			case 1: // Wep Inspect
				if (keyPress == SPAC) {
					g_Scene.viewWeapon(g_Player.wep.at(selectState.x));
					pause("Press [Space] to continue", 2, SPAC);
				}
				break;

			case 2: //Equip weapon
				if (keyPress == SPAC) {
					g_Player.selectWep(g_Player.wep.at(selectState.x));
				}
				break;

			case 3: // Delete Weapon
				// Delete g_Item
				if (keyPress == SPAC) {
					if (g_Player.wep.at(selectState.x) == g_Player.selectedWep[0]) {
						g_Player.selectedWep[0] = g_Item.weapons.at(12);
					}
					else if (g_Player.wep.at(selectState.x) == g_Player.selectedWep[1]) {
						g_Player.selectedWep[1] = g_Item.weapons.at(12);
					}

					g_Player.wep.erase(g_Player.wep.begin() + selectState.x);
				}
				break;

			case 4: // Continue
				//Reset g_Input and b_contin
				if (keyPress == SPAC) {
					this->selectState.x = 0;
					this->selectState.y = 0;

					b_contin = true;
				}
				break;
			}
		}
		else { //If g_Player wep inv empty
			pause("You do not have any weapons. Press [Space] to continue", 0, SPAC);

			b_contin = true;
		}
	}
}

/* ARMORS */
void InputManager::armInput() {
	selectState.reset();
	
	bool b_contin = false;
	while (!b_contin) {
		g_Scene.armorsScene(selectState.y, g_Item.armors);

		int keyPress = _getch();
		upDownNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Light Armor
			if (keyPress == SPAC) {
				b_contin = viewArmInput(g_Item.armors.at(0));
			}
			else if (keyPress == ENTR) {
				b_contin = buyArmInput(g_Item.armors.at(0));
			}
			break;

		case 1: //Medium Armor
			if (keyPress == SPAC) {
				b_contin = viewArmInput(g_Item.armors.at(1));
			}
			else if (keyPress == ENTR) {
				b_contin = buyArmInput(g_Item.armors.at(1));
			}
			break;

		case 2: //Heavy Armor
			if (keyPress == SPAC) {
				b_contin = viewArmInput(g_Item.armors.at(2));
			}
			else if (keyPress == ENTR) {
				b_contin = buyArmInput(g_Item.armors.at(2));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	selectState.reset();
}

bool InputManager::viewArmInput(Items::Armor arm) {
	g_Scene.viewArmor(arm);
	pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::buyArmInput(Items::Armor arm) {
	//Add weapon to inventory, subtract gold by cost
	if (g_Player.gold >= arm.cost) {
		g_Player.gold -= arm.cost;
		g_Player.aquireArm(arm);
		pause("You bought armor! Press [Space] to continue!", 0, SPAC);
		return true;
	}
	else {
		pause("NOT ENOUGH GOLD: Press [Space] to Continue!", 0, SPAC);
		return false;
	}
}

void InputManager::armInvInput() {
	selectState.reset();

	bool b_contin = false;
	
	while (!b_contin) {
		if (!g_Player.arm.empty()) {
			g_Scene.viewArmInv(selectState.y, selectState.x);

			int keyPress = _getch();
			upDownNav(keyPress, 4);
			switch (selectState.y) {
			case 0: // Armor Select
				leftRightNav(keyPress, g_Player.arm.size() - 1);
				break;

			case 1: // Armor Inspect
				if (keyPress == SPAC) {
					g_Scene.viewArmor(g_Player.arm.at(selectState.x));
					pause("Press [Space] to continue", 2, SPAC);
				}
				break;

			case 2: //Equip Armor
				if (keyPress == SPAC) {
					g_Player.selectArm(g_Player.arm.at(selectState.x));
				}
				break;

			case 3: // Delete Armor
				// Delete g_Item
				if (keyPress == SPAC) {
					if (g_Player.arm.at(selectState.x) == g_Player.selectedArm) {
						g_Player.selectedArm = g_Item.armors.at(3); //Armor is now empty armor
					}

					g_Player.arm.erase(g_Player.arm.begin() + selectState.x);
				}
				break;

			case 4: // Continue
				//Reset g_Input and b_contin
				if (keyPress == SPAC) {
					selectState.reset();

					b_contin = true;
				}
				break;
			}
		}
		else { //If g_Player wep inv empty
			pause("You do not have any armors. Press [Space] to continue", 0, SPAC);

			b_contin = true;
		}
	}
}

/* CONSUMABLES */
void InputManager::conInput() {
	selectState.reset();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.consumeScene(selectState.y, g_Item.consumes);

		int keyPress = _getch();
		upDownNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Lesser healing potion
			if (keyPress == SPAC) {
				b_contin = viewConInput(g_Item.consumes.at(0));
			}
			else if (keyPress == ENTR) {
				b_contin = buyConInput(g_Item.consumes.at(0));
			}
			break;

		case 1: //Healing potion
			if (keyPress == SPAC) {
				b_contin = viewConInput(g_Item.consumes.at(1));
			}
			else if (keyPress == ENTR) {
				b_contin = buyConInput(g_Item.consumes.at(1));
			}
			break;

		case 2: //Bigger healing potion
			if (keyPress == SPAC) {
				b_contin = viewConInput(g_Item.consumes.at(2));
			}
			else if (keyPress == ENTR) {
				b_contin = buyConInput(g_Item.consumes.at(2));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	selectState.reset();
}

bool InputManager::viewConInput(Items::Consumable con) {
	g_Scene.viewConsume(con);
	pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::buyConInput(Items::Consumable con) {
	//Add weapon to inventory, subtract gold by cost
	if (g_Player.gold >= con.cost) {
		g_Player.gold -= con.cost;
		g_Player.aquireCon(con);
		pause("You bought a Consumable! Press [Space] to continue!", 0, SPAC);
		return true;
	}
	else {
		pause("NOT ENOUGH GOLD: Press [Space] to Continue!", 0, SPAC);
		return false;
	}
}

void InputManager::conInvInput() {
	selectState.reset();

	bool b_contin = false;

	while(!b_contin)
	if (!g_Player.con.empty()) {
		g_Scene.viewConInv(selectState.y, selectState.x);

		int keyPress = _getch();
		upDownNav(keyPress, 4);
		switch (selectState.y) {
		case 0: // Consume Select
			leftRightNav(keyPress, g_Player.con.size() - 1);
			break;

		case 1: // Consume Inspect
			if (keyPress == SPAC) {
				g_Scene.viewConsume(g_Player.con.at(selectState.x));
				pause("Press [Space] to continue", 2, SPAC);
			}
			break;

		case 2: //Use Consume
			if (keyPress == SPAC) {
				g_Player.useConsume(g_Player.con.at(selectState.x), selectState.x);
			}
			break;

		case 3: // Delete Consume
			// Delete g_Item
			if (keyPress == SPAC) {
				g_Player.con.erase(g_Player.con.begin() + selectState.x);
			}
			break;

		case 4: // Continue
			//Reset g_Input and b_contin
			if (keyPress == SPAC) {
				this->selectState.x = 0;
				this->selectState.y = 0;

				b_contin = true;
			}
			break;
		}
	}
	else { //If g_Player consumables inv empty
		pause("You do not have any consumables. Press [Space] to continue", 0, SPAC);

		b_contin = true;
	}
} 

//Inventory Input/Scene
void InputManager::inventoryInput() {
	selectState.reset();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.viewInventory(selectState.y);

		int keyPress = _getch();
		upDownNav(keyPress, 3);

		switch (selectState.y) {
		case 0: // Weapons Inventory
			if (keyPress == SPAC) {
				wepInvInput();
				b_contin = false;
			}
			break;

		case 1: // Armor
			if (keyPress == SPAC) {
				g_Input.armInvInput();
				b_contin = false;
			}
			break;

		case 2: // Consumables
			if (keyPress == SPAC) {
				g_Input.conInvInput();
				b_contin = false;
			}
			break;

		case 3: // Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	selectState.reset();
}

int InputManager::wanderInput() {
	g_Scene.wanderScene(selectState.x);

	int keyPress = _getch();
	g_Input.leftRightNav(keyPress, 2);

	switch (selectState.x) {
	case 0: // Actions (move forward)
		if (keyPress == SPAC) {
			wanderActionInput();
		}
		break;

	case 1: // Inventory (Prompts inventory)
		if (keyPress == SPAC) {
			inventoryInput();
		}
		break;

	case 2: // Other (g_Game Exit, Tutorials)
		if (keyPress == SPAC) {
			if (otherInput()) {
				return true;
			}
		}
		break;
	}

	return false;
}

void InputManager::wanderActionInput() {
	selectState.reset();

	bool b_contin = false;

	while (!b_contin) {
		g_Scene.wanderActionScene(selectState.y);

		int keyPress = _getch();
		g_Input.upDownNav(keyPress, 2);

		switch (selectState.y) {
		case 0: //Loot
			if (keyPress == SPAC) {
				//check isloot
				//get num of enemies,
				//get class of enemies,
				//randomly choose dmg type corresponding to class
				//make loot g_Scene
				b_contin = true;
			}
			break;

		case 1: //Onwards
			if (keyPress == SPAC) {
				//randomly generate next room,
				//battle = true;
				//Set g_Scene
				b_contin = true;
			}
			break;

		case 2: //Back
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	selectState.reset();
}

int InputManager::otherInput() {
	selectState.reset();

	bool b_contin = false;

	while (!b_contin) {
		g_Scene.otherScene(selectState.y);

		int keyPress = _getch();
		g_Input.upDownNav(keyPress, 3);

		switch (selectState.y) {
		case 0: //Tut on Character
			if (keyPress == SPAC) {
				g_Scene.charTut1Scene();
				pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				g_Scene.charTut2Scene();
				pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 1: //Tut on Combat
			if (keyPress == SPAC) {
				g_Scene.combatTut1Scene();
				pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				g_Scene.combatTut2Scene();
				pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;
		
		case 2: // Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		
		case 3: // Exit
			if(keyPress == SPAC){
				//Exit g_Game
				return true;
			}
			break;
		}
	}

	selectState.reset();

	return false;
}

/* Inputs for Scrolls in Scenes */
void InputManager::diffInput(SelectState selectState) {
	switch (selectState.x) {
	case 0:
		g_Game.diff = "Easy";
		g_Game.diffRate = 0.80f;
		break;
	case 1:
		g_Game.diff = "Normal";
		g_Game.diffRate = 1.00f;
		break;
	case 2:
		g_Game.diff = "Hard";
		g_Game.diffRate = 1.20f;
		break;
	}
}

void InputManager::raceInput(SelectState selectState) {
	switch (selectState.x) {
	case 0:
		g_Player.raceStr = "Elf";
		g_Player.race = Character::Elf;
		break;

	case 1:
		g_Player.raceStr = "Orc";
		g_Player.race = Character::Orc;
		break;

	case 2:
		g_Player.raceStr = "Human";
		g_Player.race = Character::Human;
		break;

	case 3:
		g_Player.raceStr = "Goblin";
		g_Player.race = Character::Goblin;
		break;

	case 4:
		g_Player.raceStr = "Dwarf";
		g_Player.race = Character::Dwarf;
		break;

	case 5:
		g_Player.raceStr = "Gnome";
		g_Player.race = Character::Gnome;
		break;
	}
}

void InputManager::clasInput(SelectState selectState) {
	switch (selectState.x) {
	case 0:
		g_Player.clasStr = "Warrior";
		g_Player.clas = Character::Warrior;
		break;
	case 1:
		g_Player.clasStr = "Ranger";
		g_Player.clas = Character::Ranger;
		break;
	case 2:
		g_Player.clasStr = "Magician";
		g_Player.clas = Character::Magician;
		break;
	case 3:
		g_Player.clasStr = "Bandit";
		g_Player.clas = Character::Bandit;
		break;
	}
}

/* Setters / Getters */
int InputManager::getSelectStateX() {
	return selectState.x;
}
int InputManager::getSelectStateY() {
	return selectState.y;
}
