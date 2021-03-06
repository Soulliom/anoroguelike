#include "../include/InputManager.h"

#include "../include/GameManager.h"
#include "../include/Player.h"
#include "../include/SceneManager.h"

/* Setters / Getters */
int InputManager::getSelectStateX() {
	return selectState.x;
}
int InputManager::getSelectStateY() {
	return selectState.y;
}

InputManager::SelectState InputManager::getSelectState() {
	return selectState;
}

//Reset selectState structs
void InputManager::resetSelectState() {
	selectState.x = 0;
	selectState.y = 0;
}

/* Pauses, Inputs, Navigations.*/
void InputManager::pause(std::string t_text, const unsigned int t_seconds, const unsigned int t_key) {
	//Sleep
	Sleep(t_seconds * 1000);

	//Collects spammed keys pressed during sleep
	while (_kbhit()) {
		_getch();
	}

	//Print text
	std::cout << std::endl << t_text << std::endl;

	//If correct key is pressed continue. (Unless NULL then continue otherwise)
	bool b_contin = false;
	while (!b_contin) {
		int but = _getch();
		if (t_key != NULL) {
			if (t_key == but) {
				b_contin = true;
			}
		}
		else {
			b_contin = true;
		}
	}
}

void InputManager::output(std::string t_text, const unsigned int t_seconds) {
	//Sleep
	Sleep(t_seconds * 1000);

	//Collects spammed keys pressed during sleep
	while (_kbhit()) {
		_getch();
	}

	//Print text
	std::cout << std::endl << t_text;
}

std::string InputManager::stringInput(std::string t_text) {
	//define, get, return string output - print text param
	std::string output;
	std::cout << "\n" << t_text << "\n";
	std::cin >> output;
	return output;
}

int InputManager::intInput(std::string t_text) {
	//define, get, check and return output - print text param
	int output = 0;
	std::cout << "\n" << t_text << "\n";
	std::cin.clear();
		std::cin >> output;

	if (output > 0) {
		return output;
	}
	else {
		while (std::cin.fail()) {
			//If invalid, return false, pause and clear cin
			pause("ERROR: No negative numbers or characters! Press [Space] to continue", 1, SPAC);
			std::cin.clear();
			std::cin.ignore(256, '\n');
			return 0;
		}
	}
	return 0;
}

/* Menu Navigation Functions */
void InputManager::upDownNav(unsigned int t_input, const int t_max) {
	if (t_input == WKEY) {
		selectState.y--;
		if (selectState.y < 0) {
			selectState.y = t_max;
		}
	}
	
	if (t_input == SKEY) {
		selectState.y++;
		if (selectState.y > t_max) {
			selectState.y = 0;
		}
	}
}

void InputManager::leftRightNav(unsigned int t_input, const int t_max) {
	if (t_input == AKEY) {
		selectState.x--;
		if (selectState.x < 0) {
			selectState.x = t_max;
		}
	}
	
	if (t_input == DKEY) {
		selectState.x++;
		if (selectState.x > t_max) {
			selectState.x = 0;
		}
	}
}

/* Inputs for Specific Scenes*/
void InputManager::seedInput() {
	resetSelectState();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.seed(g_Input.getSelectStateY(), g_Game.seed);

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
				selectState.y = 0;
				b_contin = true;
			}
			break;
		}
	}

	resetSelectState();
}

/* WEAPONS */
void InputManager::weapons() {
	bool b_contin = false;

	resetSelectState();
	while (!b_contin) {
		g_Scene.weapons(selectState.y);

		int keyPress = _getch();
		g_Input.upDownNav(keyPress, 3);
		switch (g_Input.getSelectStateY()) {
		case 0: //Melee Shop
			if (keyPress == SPAC) {
				g_Input.melee();
			}
			break;

		case 1: //Ranged Shop
			if (keyPress == SPAC) {
				g_Input.ranged();
			}
			break;

		case 2: //Magic Shop
			if (keyPress == SPAC) {
				g_Input.magic();
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
		}
	}
	resetSelectState();
}

void InputManager::melee() {
	resetSelectState();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.melee(selectState.y, g_Item.v_Weapons);

		int keyPress = _getch();
		upDownNav(keyPress, 3);
		switch (selectState.y) {
		case 0: //Rapier
			if (keyPress == SPAC) {
				b_contin = viewWeapons(g_Item.v_Weapons.at(0));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWeapons(g_Item.v_Weapons.at(0));
			}
			break;

		case 1: //Claymore
			if (keyPress == SPAC) {
				b_contin = viewWeapons(g_Item.v_Weapons.at(1));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWeapons(g_Item.v_Weapons.at(1));
			}
			break;

		case 2: //Small Shield
			if (keyPress == SPAC) {
				b_contin = viewWeapons(g_Item.v_Weapons.at(3));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWeapons(g_Item.v_Weapons.at(3));
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		
		}
	}

	resetSelectState();
}

void InputManager::ranged() {
	resetSelectState();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.ranged(selectState.y, g_Item.v_Weapons);

		int keyPress = _getch();
		upDownNav(keyPress, 1);
		switch (selectState.y) {
		case 0: //Recurve Bow
			if (keyPress == SPAC) {
				b_contin = viewWeapons(g_Item.v_Weapons.at(5));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWeapons(g_Item.v_Weapons.at(5));
			}
			break;

		case 1: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	resetSelectState();
}

void InputManager::magic() {
	resetSelectState();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.magic(selectState.y, g_Item.v_Weapons);

		int keyPress = _getch();
		upDownNav(keyPress, 2);
		switch (selectState.y) {
		case 0: //Saphire Staff
			if (keyPress == SPAC) {
				b_contin = viewWeapons(g_Item.v_Weapons.at(8));
			}
			else if(keyPress == ENTR){
				b_contin = buyWeapons(g_Item.v_Weapons.at(8));
			}
			break;

		case 1: //Book of Creation
			if (keyPress == SPAC) {
				b_contin = viewWeapons(g_Item.v_Weapons.at(11));
			}
			else if (keyPress == ENTR) {
				b_contin = buyWeapons(g_Item.v_Weapons.at(11));
			}
			break;

		case 2: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	resetSelectState();
}

bool InputManager::viewWeapons(Items::Weapon t_wep) {
	g_Scene.viewWeapon(t_wep);
	pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::buyWeapons(Items::Weapon t_wep){
	//Add weapon to inventory, subtract gold by cost
	if (g_Player.gold >= t_wep.cost) {
		g_Player.gold -= t_wep.cost;
		g_Player.aquireWep(t_wep);
		pause("You bought a weapon! Press [Space] to continue!", 0, SPAC); 
		return true;
	}
	else {
		pause("NOT ENOUGH GOLD: Press [Space] to Continue!", 0, SPAC);
		return false;
	}
}

void InputManager::wepInv() 
{
	resetSelectState();
	bool b_contin = false;

	while (!b_contin) {

		if (!g_Player.v_Wep.empty()) {
			g_Scene.viewWepInv(selectState.y, selectState.x);

			int keyPress = _getch();
			upDownNav(keyPress, 4);
			switch (selectState.y) {
			case 0: // Wep Select
				leftRightNav(keyPress, g_Player.v_Wep.size() - 1);
				break;

			case 1: // Wep Inspect
				if (keyPress == SPAC) {
					g_Scene.viewWeapon(g_Player.v_Wep.at(selectState.x));
					pause("Press [Space] to continue", 1, SPAC);
				}
				break;

			case 2: //Equip weapon
				if (keyPress == SPAC) {
					g_Player.selectWep(g_Player.v_Wep.at(selectState.x));
				}
				break;

			case 3: // Delete Weapon
				// Delete g_Item
				if (keyPress == SPAC) {
					if (g_Player.v_Wep.at(selectState.x) == g_Player.selectedWep[0]) {
						g_Player.selectedWep[0] = g_Item.v_Weapons.at(12);
					}
					else if (g_Player.v_Wep.at(selectState.x) == g_Player.selectedWep[1]) {
						g_Player.selectedWep[1] = g_Item.v_Weapons.at(12);
					}

					g_Player.v_Wep.erase(g_Player.v_Wep.begin() + selectState.x);
					b_contin = true;
				}
				break;

			case 4: // Continue
				//Reset g_Input and b_contin
				if (keyPress == SPAC) {
					selectState.x = 0;
					selectState.y = 0;

					b_contin = true;
				}
				break;
			}
		}
		else { //If g_Player wep inv empty
			pause("You do not have any Weapons. Press [Space] to continue", 0, SPAC);

			b_contin = true;
		}
	}
	resetSelectState();
}

/* ARMORS */
void InputManager::armors() {
	resetSelectState();
	
	bool b_contin = false;
	while (!b_contin) {
		g_Scene.armors(selectState.y, g_Item.v_Armors);

		int keyPress = _getch();
		upDownNav(keyPress, 2);
		switch (selectState.y) {
		case 0: //Light Armor
			if (keyPress == SPAC) {
				b_contin = viewArmors(g_Item.v_Armors.at(0));
			}
			else if (keyPress == ENTR) {
				b_contin = buyArmors(g_Item.v_Armors.at(0));
			}
			break;

		case 1: //Medium Armor
			if (keyPress == SPAC) {
				b_contin = viewArmors(g_Item.v_Armors.at(1));
			}
			else if (keyPress == ENTR) {
				b_contin = buyArmors(g_Item.v_Armors.at(1));
			}
			break;

		case 2: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	resetSelectState();
}

bool InputManager::viewArmors(Items::Armor t_arm) {
	g_Scene.viewArmor(t_arm);
	pause("Press [Space] to Continue!", 1, SPAC);
	return false;
}

bool InputManager::buyArmors(Items::Armor t_arm) {
	//Add weapon to inventory, subtract gold by cost
	if (g_Player.gold >= t_arm.cost) {
		g_Player.gold -= t_arm.cost;
		g_Player.aquireArm(t_arm);
		pause("You bought armor! Press [Space] to continue!", 0, SPAC);
		return true;
	}
	else {
		pause("NOT ENOUGH GOLD: Press [Space] to Continue!", 0, SPAC);
		return false;
	}
}

void InputManager::armInv() {
	resetSelectState();
	bool b_contin = false;
	
	while (!b_contin) {
		if (!g_Player.v_Arm.empty()) {
			g_Scene.viewArmInv(selectState.y, selectState.x);

			int keyPress = _getch();
			upDownNav(keyPress, 4);
			switch (selectState.y) {
			case 0: // Armor Select
				leftRightNav(keyPress, g_Player.v_Arm.size() - 1);
				break;

			case 1: // Armor Inspect
				if (keyPress == SPAC) {
					g_Scene.viewArmor(g_Player.v_Arm.at(selectState.x));
					pause("Press [Space] to continue", 1, SPAC);
				}
				break;

			case 2: //Equip Armor
				if (keyPress == SPAC) {
					g_Player.selectArm(g_Player.v_Arm.at(selectState.x));
				}
				break;

			case 3: // Delete Armor
				// Delete g_Item
				if (keyPress == SPAC) {
					if (g_Player.v_Arm.at(selectState.x) == g_Player.selectedArm) {
						g_Player.selectedArm = g_Item.v_Armors.at(3); //Armor is now empty armor
					}

					g_Player.v_Arm.erase(g_Player.v_Arm.begin() + selectState.x);
					b_contin = true;
				}
				break;

			case 4: // Continue
				//Reset g_Input and b_contin
				if (keyPress == SPAC) {
					resetSelectState();

					b_contin = true;
				}
				break;
			}
		}
		else { //If g_Player wep inv empty
			pause("You do not have any Armors. Press [Space] to continue", 0, SPAC);

			b_contin = true;
		}
	}
	resetSelectState();
}

/* CONSUMABLES */
void InputManager::consume() {
	resetSelectState();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.consume(selectState.y, g_Item.v_Consumes);

		int keyPress = _getch();
		upDownNav(keyPress, 2);
		switch (selectState.y) {
		case 0: //Lesser healing potion
			if (keyPress == SPAC) {
				b_contin = viewCon(g_Item.v_Consumes.at(0));
			}
			else if (keyPress == ENTR) {
				b_contin = buyCon(g_Item.v_Consumes.at(0));
			}
			break;

		case 1: //Healing potion
			if (keyPress == SPAC) {
				b_contin = viewCon(g_Item.v_Consumes.at(1));
			}
			else if (keyPress == ENTR) {
				b_contin = buyCon(g_Item.v_Consumes.at(1));
			}
			break;

		case 2: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	resetSelectState();
}

bool InputManager::viewCon(Items::Consumable t_con) {
	g_Scene.viewConsume(t_con);
	pause("Press [Space] to Continue!", 2, SPAC);
	return false;
}

bool InputManager::buyCon(Items::Consumable t_con) {
	//Add weapon to inventory, subtract gold by cost
	if (g_Player.gold >= t_con.cost) {
		g_Player.gold -= t_con.cost;
		g_Player.aquireCon(t_con);
		pause("You bought a Consumable! Press [Space] to continue!", 0, SPAC);
		return true;
	}
	else {
		pause("NOT ENOUGH GOLD: Press [Space] to Continue!", 0, SPAC);
		return false;
	}
}

void InputManager::conInv() {
	resetSelectState();
	bool b_contin = false;

	while(!b_contin)
	if (!g_Player.v_Con.empty()) {
		g_Scene.viewConInv(selectState.y, selectState.x);

		int keyPress = _getch();
		upDownNav(keyPress, 4);
		switch (selectState.y) {
		case 0: // Consume Select
			leftRightNav(keyPress, g_Player.v_Con.size() - 1);
			break;

		case 1: // Consume Inspect
			if (keyPress == SPAC) {
				g_Scene.viewConsume(g_Player.v_Con.at(selectState.x));
				pause("Press [Space] to continue", 2, SPAC);
			}
			break;

		case 2: //Use Consume
			if (keyPress == SPAC) {
				g_Player.useConsume(g_Player.v_Con.at(selectState.x), selectState.x);
				b_contin = true;
			}
			break;

		case 3: // Delete Consume
			// Delete g_Item
			if (keyPress == SPAC) {
				g_Player.v_Con.erase(g_Player.v_Con.begin() + selectState.x);
				b_contin = true;
			}
			break;

		case 4: // Continue
			//Reset g_Input and b_contin
			if (keyPress == SPAC) {
				selectState.x = 0;
				selectState.y = 0;

				b_contin = true;
			}
			break;
		}
	}
	else { //If g_Player consumables inv empty
		pause("You do not have any Consumables. Press [Space] to continue", 0, SPAC);

		b_contin = true;
	}
	resetSelectState();
} 

//Inventory Input/Scene
void InputManager::inventory() {
	resetSelectState();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.viewInventory(selectState.y);

		int keyPress = _getch();
		upDownNav(keyPress, 3);

		switch (selectState.y) {
		case 0: // Weapons Inventory
			if (keyPress == SPAC) {
				wepInv();
				b_contin = false;
			}
			break;

		case 1: // Armor
			if (keyPress == SPAC) {
				g_Input.armInv();
				b_contin = false;
			}
			break;

		case 2: // Consumables
			if (keyPress == SPAC) {
				g_Input.conInv();
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

	resetSelectState();
}

bool InputManager::wander() {
	if (bState == e_gameState::INSPECT) {
		g_Scene.wander(selectState.x);

		int keyPress = _getch();
		g_Input.leftRightNav(keyPress, 2);

		switch (selectState.x) {
		case 0: // Actions (move forward)
			if (keyPress == SPAC) {
				bState = e_gameState::ACTION;
			}
			break;

		case 1: // Inventory (Prompts inventory)
			if (keyPress == SPAC) {
				inventory();
			}
			break;

		case 2: // Other (g_Game Exit, Tutorials)
			if (keyPress == SPAC) {
				if (other()) {
					return true;
				}
			}
			break;
		}
	}

	else if (bState == e_gameState::ACTION) {
		g_Scene.action(selectState.x);

		int keyPress = _getch();
		g_Input.leftRightNav(keyPress, 2);

		switch (selectState.x) {
		case 0: // Change View
			if (keyPress == SPAC) {
				bState = e_gameState::INSPECT;
			}
			break;

		case 1: // Onwards
			if (keyPress == SPAC) {
				//Player stuff
				//Speed
				g_Player.speed = g_Player.maxSpeed;
				//Stress
				g_Player.stress += 1;

				if (g_Player.clas == Character::e_Class::RANGER) {
					g_Player.selectedWep.at(0).uses = 2;
				}
				else {
					g_Player.selectedWep.at(0).uses = 1;
				}
				g_Player.selectedWep.at(1).uses = 1;

				if (g_Player.clas == Character::e_Class::WARRIOR) {
					if (g_Player.health < g_Player.maxHealth) {
						g_Player.health++;
					}
				}

				g_Game.b_isPlayerTurn = true;
				g_Game.b_inBattle = true;
				g_Game.roomGenerator();
				bState = e_gameState::PLAYER;
			}
			break;

		case 2: // Other
			if (keyPress == SPAC) {
				if (other()) {
					return true;
				}
			}
			break;
		}
	}
	return false;
}

bool InputManager::other() {
	resetSelectState();

	bool b_contin = false;

	while (!b_contin) {
		g_Scene.other(selectState.y);

		int keyPress = _getch();
		upDownNav(keyPress, 3);

		switch (selectState.y) {
		case 0: //Tut on Character
			if (keyPress == SPAC) {
				g_Scene.charTut1();
				pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				g_Scene.charTut2();
				pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 1: //Tut on Combat
			if (keyPress == SPAC) {
				g_Scene.combatTut1();
				pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				g_Scene.combatTut2();
				pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;
		
		case 2: // Exit
			if(keyPress == SPAC){
				//Exit Game
				return true;
			}
			break;

		case 3: // Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}

	resetSelectState();

	return false;
}

bool InputManager::battle() {
	//Display
	switch (bState) {
	case e_gameState::PLAYER:
		g_Scene.battlePlayer(selectState.x);
		break;

	case e_gameState::ENEMY:
		g_Scene.battleEnemy(selectState.x);
		break;

	case e_gameState::MAP:
		g_Scene.battleMap(selectState.x);
		break;
	}

	if (g_Game.b_isPlayerTurn) {
		//Input
		int keyPress = _getch();
		leftRightNav(keyPress, 2);

		//Process
		switch (selectState.x) {
		case 0:
			if (keyPress == SPAC) {
				switch (bState) {
				case e_gameState::PLAYER:
					bState = e_gameState::ENEMY;
					break;

				case e_gameState::ENEMY:
					bState = e_gameState::MAP;
					break;

				case e_gameState::MAP:
					bState = e_gameState::PLAYER;
					break;
				}
			}
			break;

		case 1: // ACTIONS 
			if (keyPress == SPAC) {
				switch (bState) {
				case e_gameState::PLAYER: // Inventory
					inventory();
					break;

				case e_gameState::ENEMY: //ATTACK INPUT
					battleAction();
					break;

				case e_gameState::MAP: //MOVEMENT INPUT
					moveInput();
					break;
				}
			}
			break;

		case 2: // Other (Game Exit, Tutorials)
			if (keyPress == SPAC) {
				if (other()) {
					return true;
				}
			}
			break;
		}
		
		if (keyPress == ENTR) { //Skip turn
			g_Game.b_isPlayerTurn = false;
			pause("You have ended your turn! Press [Space] to continue!", 0, SPAC);
		}
	}
	else { //Not player's turn, Process Enemy turns and setup.

		for (auto e : g_Game.v_Enemy) {
			e->speed = e->maxSpeed;
			e->enemyTurn();
		}

		//Player stuff
		//Speed
		g_Player.speed = g_Player.maxSpeed;
		//Stress
		g_Player.stress++; 
		if (g_Player.stress >= g_Player.maxStress) {
			pause("You become self destructive, and lose a 1/4 of your health", 0);
			g_Player.health -= (g_Player.maxHealth / 4);
			g_Player.stress = 0;
		}

		//Reset Block
		g_Player.b_block = true;
		g_Player.block = 1;
		g_Player.blockType = Items::e_Type::NONE;

		if (g_Player.clas == Character::e_Class::RANGER) {
			g_Player.selectedWep.at(0).uses = 2;
		}
		else {
			g_Player.selectedWep.at(0).uses = 1;
		}
		g_Player.selectedWep.at(1).uses = 1;

		g_Game.b_isPlayerTurn = true;
		
		//Check if player is dead
		if (g_Player.health <= 0) {
			return true;
		}

	}

	return false;
}

void InputManager::battleAction() {
	resetSelectState();
	bool b_contin = false;

	while (!b_contin) {
		g_Scene.battleAction(selectState.y);

		//Input
		int keyPress = _getch();
		upDownNav(keyPress, 3);

		switch (selectState.y) {
		case 0: // Wep 1
			if (keyPress == SPAC) {
				playerAttack(g_Player.selectedWep.at(0));
			}
			break;

		case 1: // Wep 2
			if (keyPress == SPAC) {
				playerAttack(g_Player.selectedWep.at(1));
			}
			break;

		case 2: // Block
			if (keyPress == SPAC ) {
				if (g_Player.b_block) {
					pause("You ready for an attack. Press [Space] to continue!", 0, SPAC);
					g_Player.blockType = g_Player.selectedWep.at(0).type;

					switch (g_Player.blockType) {
					case Items::e_Type::NONE:
						g_Player.block = 0.95f;
						break;

					case Items::e_Type::MELEE:
						
						if (g_Player.selectedWep.at(0) == g_Item.v_Weapons.at(3) || g_Player.selectedWep.at(0) == g_Item.v_Weapons.at(4)) {
							g_Player.block = 0.70f;
						}
						else {
							g_Player.block = 0.80f;
						}
						break;

					case Items::e_Type::RANGED:
						g_Player.block = 0.90f;
						break;

					case Items::e_Type::MAGIC:
						g_Player.block = 0.85f;
						break;
					}


					g_Player.speed = 0;
					b_contin = true;
				}
				else {
					pause("You have already moved! Press [Space] to continue!", 0, SPAC);
				}
			}
			break;

		case 3: // Back
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}
}

void InputManager::playerAttack(Items::Weapon& t_wep) {
	resetSelectState();

	bool b_contin = false;
	selectState.y = 1;

	while (!b_contin) {
		g_Scene.playerAttack(t_wep, selectState.y);

		int keyPress = _getch();
		upDownNav(keyPress, g_Game.v_Enemy.size());

		if (selectState.y == 0 && keyPress == SPAC) {
			b_contin = true;
			break;
		}

		if (keyPress == SPAC) {
			if (t_wep.uses > 0) {
				if (((t_wep.range + g_Player.pos.x >= g_Game.v_Enemy.at(selectState.y - 1)->pos.x) && (t_wep.range - g_Player.pos.x <= g_Game.v_Enemy.at(selectState.y - 1)->pos.x))
					&& ((t_wep.range + g_Player.pos.y >= g_Game.v_Enemy.at(selectState.y - 1)->pos.y) && (t_wep.range - g_Player.pos.y <= g_Game.v_Enemy.at(selectState.y - 1)->pos.y))) {

					if ((g_Player.stats.perception * 2) + g_Player.pos.x >= g_Game.v_Enemy.at(selectState.y - 1)->pos.x){

						int hitChance = 0;
						int randChance = rand() % 10 + 1;

						switch (t_wep.type) {
						case Items::e_Type::MELEE:
							hitChance = g_Player.stats.strength;
							break;

						case Items::e_Type::RANGED:
							hitChance = g_Player.stats.perception;
							break;

						case Items::e_Type::MAGIC:
							hitChance = g_Player.stats.wisdom;
							break;
						}

						if (hitChance > randChance) {
							bool b_isDead = g_Game.v_Enemy.at(selectState.y - 1)->takeDamage(t_wep);
							if (b_isDead) {
								g_Game.v_Enemy.erase(g_Game.v_Enemy.begin() + selectState.y - 1);
							}

							t_wep.uses--;
							b_contin = true;
							break;
						}
						else {
							g_Player.stress += 2;
							pause("You missed your attack.", 0);

							t_wep.uses--;
							b_contin = true;
							break;
						}
					}
					else {
						pause("Your perception isn't good enough to hit this target! Press [Space] to Continue!", 0, SPAC);
						b_contin = true;
						break;
					}
				}
				else {
					pause("Your weapon doesn't have enough range to hit this target! Press [Space] to Continue!", 0, SPAC);
					b_contin = true;
					break;
				}
			}
			
			else {
				pause("Your weapon doesn't have anymore uses! Press [Space] to Continue!", 0, SPAC);
			}
		}
	}

	resetSelectState();
	g_Player.levelUp();
	resetSelectState();
}

void InputManager::levelUp(Character::Stats& t_stats) {
	resetSelectState();

	bool b_contin = false;
	while (!b_contin) {
		g_Scene.levelUp(t_stats, selectState.y);

		int keyPress = _getch();
		upDownNav(keyPress, 5);

		switch (selectState.y) {
		case 0: // Str
			if (keyPress == SPAC) {
				t_stats.strength++;
				b_contin = true;
			}
			break;

		case 1: // Fort
			if (keyPress == SPAC) {
				t_stats.fortitude++;
				b_contin = true;
			}
			break;

		case 2: // Agl
			if (keyPress == SPAC) {
				t_stats.agility++;
				b_contin = true;
			}
			break;

		case 3: // Wis
			if (keyPress == SPAC) {
				t_stats.wisdom++;
				b_contin = true;
			}
			break;

		case 4: // Perc
			if (keyPress == SPAC) {
				t_stats.perception++;
				b_contin = true;
			}
			break;

		case 5: // Tutorial
			if (keyPress == SPAC) {
				g_Scene.charTut1();
				pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				g_Scene.charTut2();
				pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;
		}
	}
}


/* Inputs for Scrolls in Scenes */
void InputManager::diffInput(SelectState t_selectState) {
	switch (t_selectState.x) {
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

void InputManager::raceInput(SelectState t_selectState) {
	switch (t_selectState.x) {
	case 0:
		g_Player.raceStr = "Elf";
		g_Player.race = Character::e_Race::ELF;
		break;

	case 1:
		g_Player.raceStr = "Orc";
		g_Player.race = Character::e_Race::ORC;
		break;

	case 2:
		g_Player.raceStr = "Human";
		g_Player.race = Character::e_Race::HUMAN;
		break;

	case 3:
		g_Player.raceStr = "Goblin";
		g_Player.race = Character::e_Race::GOBLIN;
		break;

	case 4:
		g_Player.raceStr = "Dwarf";
		g_Player.race = Character::e_Race::DWARF;
		break;

	case 5:
		g_Player.raceStr = "Gnome";
		g_Player.race = Character::e_Race::GNOME;
		break;
	}
}

void InputManager::clasInput(SelectState t_selectState) {
	switch (t_selectState.x) {
	case 0:
		g_Player.clasStr = "Warrior";
		g_Player.clas = Character::e_Class::WARRIOR;
		break;
	case 1:
		g_Player.clasStr = "Ranger";
		g_Player.clas = Character::e_Class::RANGER;
		break;
	case 2:
		g_Player.clasStr = "Magician";
		g_Player.clas = Character::e_Class::MAGICIAN;
		break;
	case 3:
		g_Player.clasStr = "Bandit";
		g_Player.clas = Character::e_Class::BANDIT;
		break;
	}
}

void InputManager::moveInput() {
	if (g_Player.speed > 0) {
		while (g_Game.b_inBattle) {
			g_Scene.battleMap(3);

			output(static_cast<std::string>("Moves left: ").append(std::to_string(g_Player.speed)), 0);
			if (g_Player.clas == Character::e_Class::BANDIT) {
				output("Press [Space] to pause your move!", 0);
			}
			else {
				output("Press [Space] to end your move!", 0);
			}

			int keyPress = _getch();

			
			g_Player.prevPos = g_Player.pos;
			switch (keyPress) {

			case WKEY:
				if (g_Player.speed > 0) {
					g_Player.pos.y -= 1;
					g_Player.speed -= 1;
				}
				break;

			case AKEY:
				if (g_Player.speed > 0) {
					g_Player.pos.x -= 1;
					g_Player.speed -= 1;
				}
				break;

			case SKEY:
				if (g_Player.speed > 0) {
					g_Player.pos.y += 1;
					g_Player.speed -= 1;
				}
				break;

			case DKEY:
				if (g_Player.speed > 0) {
					g_Player.pos.x += 1;
					g_Player.speed -= 1;
				}
				break;

			case SPAC:
				if (g_Player.clas != Character::e_Class::BANDIT) {
					g_Player.speed = 0;
				}
				return;
			}
			g_Game.checkCollision();
		}

		if (g_Game.b_inBattle) {
			g_Scene.battleMap(3);
		}
	}
	else if (g_Game.b_inBattle) {
		pause("You have already moved! Press [Space] to continue!", 0, SPAC);
	}
	
}