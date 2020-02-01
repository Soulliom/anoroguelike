#include "../include/GameManager.h"

#include "../include/Player.h"
#include "../include/InputManager.h"
#include "../include/Map.h"
#include "../include/SceneManager.h"

/* GAME SECTIONS */
void GameManager::init() {
	bool b_contin = false;
	unsigned int keyPress = 0;
	//Randomize seed
	srand(static_cast<unsigned int>(time(NULL)));
	seed = rand() % 99998888 + 1111;
	//Print title g_Scene
	g_Scene.title();
	g_Input.pause("Press [Space] to Continue.", 1, SPAC);

}

void GameManager::settings() {
	//define continue, loop while continue button isnt pressed
	bool b_contin = false;
	while (!b_contin) {
		//Update Scene
		g_Scene.settings(g_Input.getSelectStateY(), g_Game.diff, g_Game.seed);

		//Get g_Input
		unsigned int keyPress = _getch();
		//Check if g_Input was for navigation
		g_Input.upDownNav(keyPress, 4);

		//Use g_Input otherwise
		switch (g_Input.getSelectStateY()) {
		case 0: //Difficulty
			g_Input.leftRightNav(keyPress, 2);
			g_Input.diffInput(g_Input.getSelectState());
			break;

		case 1: //Seed -- Look above for comments
			if (keyPress == SPAC) {
				g_Input.seedInput();
			}
			break;

		case 2: //Tut on Character
			if (keyPress == SPAC) {
				g_Scene.charTut1();
				g_Input.pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				g_Scene.charTut2();
				g_Input.pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 3: //Tut on Combat
			if (keyPress == SPAC) {
				g_Scene.combatTut1();
				g_Input.pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				g_Scene.combatTut2();
				g_Input.pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 4: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
				//Init seed
				if (seed == 0) {
					//if 0 randomize seed
					srand(static_cast<unsigned int>(time(NULL)));
				}
				else {
					//if seed is present, use seed
					srand(seed);
				}
			}
			break;
		}
	};
	//Reset selectstates
	g_Input.resetSelectState();
}

void GameManager::character() {
	Character::Stats raceStat;
	//Randomize character stats
	g_Player.randStats();
	//Reset selectstates
	bool b_contin = false;
	while (!b_contin) {
		//Update Player's stats with current race
		g_Player.configRaceStats(raceStat);

		//Update Scene
		g_Scene.character(g_Input.getSelectStateY(), g_Player.raceStr, g_Player.clasStr, g_Player.stats, raceStat);

		//Get g_Input
		int keyPress = _getch();
		g_Input.upDownNav(keyPress, 3);

		switch (g_Input.getSelectStateY()) {
		case 0: //Race
			g_Input.leftRightNav(keyPress, 5);
			g_Input.raceInput(g_Input.getSelectState());
			break;

		case 1: //Class
			g_Bpinput.leftRightNav(keyPress, 3);
			g_Input.clasInput(g_Bpinput.getSelectState());
			break;

		case 2: //Reset Stats + Rand Stats
			if (keyPress == SPAC) {
				g_Player.resetStats();
				g_Player.randStats();
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				g_Player.combineRaceStats(raceStat);
				b_contin = true;
			}
			break;
		}
	}

	//Reset selectstates
	g_Input.resetSelectState();
	g_Bpinput.resetSelectState();
}

void GameManager::shop() {
	//Change gold accourding to difficulty 
	g_Player.gold = static_cast<int>(g_Player.gold / g_Game.diffRate);
	bool b_contin = false;
	while (!b_contin) {
		//Update Scene
		g_Scene.shop(g_Input.getSelectStateY(), g_Player.gold);

		int keyPress = _getch();
		g_Input.upDownNav(keyPress, 4);

		switch (g_Input.getSelectStateY()) {
		case 0: //Weapons Shop
			if (keyPress == SPAC) {
				g_Input.weapons();
			}
			break;

		case 1: //Armors Shop
			if (keyPress == SPAC) {
				g_Input.armors();
			}
			break;

		case 2: //Consumables Shop
			if (keyPress == SPAC) {
				g_Input.consume();
			}
			break;

		case 3: //Inventory
			if (keyPress == SPAC) {
				g_Input.inventory();
			}
			break;

		case 4: // Continue
			if (keyPress == SPAC) {
				if (g_Player.v_Wep.empty()) {
					g_Input.pause("You must have bought a weapon in order to continue. Press [Space] to go back.", 0, SPAC);
				}
				else {
					b_contin = true;
				}
			}
			break;
		}
	}
	//Reset selectstates
	g_Input.resetSelectState();

}

void GameManager::game() {
	/* Player Finalization */
	//Apply player stats
	g_Player.levelUp();
	//Apply Weight of items
	g_Player.applyCurrentWeight();

	/* Game */
	//Game over condition
	bool b_contin = false;
	while (!b_contin) {
		// Battle- Actions, Enemy race/v_Weapons/position, Player Position
		if (!g_Game.b_inBattle) { //Wandering Scene
			b_contin = g_Input.wander();
		}
		else if (g_Game.b_inBattle) { //Battling Scene
			b_contin = g_Input.battle();
		}
	}
}

/* GENERATORS */
//ramdomly generates any weapon
Items::Weapon GameManager::wepGenerator() {
	//Generate random weapon 
	Items::Weapon randWep = g_Item.v_Weapons.at(rand() % (g_Item.v_Weapons.size() - 1));

	//Randomize Weapon damage
	float multiAdd = ((g_Player.level / 2) * randWep.dmgMulti);
	int randAdd = rand() % 1 + ((g_Player.level + 1) / 2);

	randWep.dmg += randAdd;

	//Randomize Weapon Enchantment
	int randEnchant = rand() % 10;

	if (randEnchant >= 10) {
		randWep.enchant = Items::e_Enchant::FLAME;
	}
	else if (randEnchant == 9) {
		randWep.enchant = Items::e_Enchant::VAMP;
	}
	else if (randEnchant == 8) {
		randWep.enchant = Items::e_Enchant::PENETRATE;
	}
	else {
		randWep.enchant = Items::e_Enchant::NONE;
	}

	return randWep;
}

//ramdomly generates any armor
Items::Armor GameManager::armGenerator() {
	int ran = rand() % 10;

	if (ran >= 6) {
		return g_Item.v_Armors.at(0);
	}
	else if (ran <= 5 && ran >= 2) {
		return g_Item.v_Armors.at(1);
	}
	else if (ran <= 1) {
		return g_Item.v_Armors.at(2);
	}
	else {
		return g_Item.v_Armors.at(3);
	}
}

//ramdomly generates any consumable
Items::Consumable GameManager::conGenerator() {
	int ran = rand() % 10;

	if (ran >= 5) {
		return g_Item.v_Consumes.at(0);
	}
	else if (ran >= 2 && ran <= 4) {
		return g_Item.v_Consumes.at(1);
	}
	else {
		return g_Item.v_Consumes.at(2);
	}
}

void GameManager::roomGenerator() {
	if (!v_Enemy.empty()) {
		v_Enemy.erase(v_Enemy.begin(), v_Enemy.end());
	}
	if (!v_Block.empty()) {
		v_Block.erase(v_Block.begin(), v_Block.end());
	}

	std::vector<Character::Position> v_tPositions;

	for (unsigned int t = 0; t < v_tPositions.size(); t++) {
		v_tPositions.erase(v_tPositions.begin());
	}

	//Create Exit
	Exit.x = g_Map.border.width;
	Exit.y = rand() % (g_Map.border.height - 2) + 1;
	v_tPositions.push_back(Exit);

	//Create Enemies
	for (int i = 0; i <= g_Player.level; i++) {
		if (i <= 6) {
			bool skip = false;
			v_Enemy.push_back(new Enemy);

			v_Enemy.at(i)->setPosition();
			for (auto tPos : v_tPositions) {
				if (v_Enemy.at(i)->pos == tPos) {
					i--;
					skip = true;
					break;
				}
			}
			if (!skip) {
				v_Enemy.at(i)->num = i + 1;

				v_tPositions.push_back(v_Enemy.at(i)->pos);
			}
		}
		else {
			break;
		}
	}

	//Create Blocks
	for (int i = 0; i < (rand() % 40 + 60); i++) {
		bool skip = false;
		Character::Position Block;

		Block.x = rand() % (g_Map.border.width - 5) + 3;
		Block.y = rand() % (g_Map.border.height - 3) + 2;

		for (auto tPos : v_tPositions) {
			if (Block == tPos) {
				i--;
				skip = true;
				break;
			}
		}
		if (!skip) {
			v_tPositions.push_back(Block);
			v_Block.push_back(Block);
		}
	}

	//Set Positions
	g_Player.setPosition();
}

void GameManager::checkCollision() {
	/* Check If Out of Border */
	if (g_Player.pos.y == g_Map.border.height) {
		g_Player.pos = g_Player.prevPos;
		g_Player.speed++;
	}
	else if (g_Player.pos.y == 0) {
		g_Player.pos = g_Player.prevPos;
		g_Player.speed++;
	}
	if (g_Player.pos.x == -1) {
		g_Player.pos = g_Player.prevPos;
		g_Player.speed++;
	}
	else if (g_Player.pos.x == g_Map.border.width + 1) {
		g_Player.pos = g_Player.prevPos;
		g_Player.speed++;
	}

	/* Check for Blocks */
	for (auto b : v_Block) {
		if (b.x == g_Player.pos.x) {
			if (b.y == g_Player.pos.y) {
				g_Player.pos = g_Player.prevPos;
				g_Player.speed++;
			}
		}
	}

	/* Check for Enemies */
	for (auto e : v_Enemy) {
		if (e->pos.x == g_Player.pos.x) {
			if (e->pos.y == g_Player.pos.y) {
				g_Player.pos = g_Player.prevPos;
				g_Player.speed++;
			}
		}
	}

	//Check end
	if (Exit == g_Player.pos) {
		if (g_Player.clas == Character::e_Class::MAGICIAN) {
			g_Player.stress -= 20;
		}
		else {
			g_Player.stress -= 10;
		}

		if (g_Player.stress < 0) {
			g_Player.stress = 0;
		}

		g_Input.pause("You have proceeded to the next room. Press [Space] to continue!", 0, SPAC);
		g_Input.bState = InputManager::e_gameState::INSPECT;
		g_Game.b_isPlayerTurn = false;
		g_Game.b_inBattle = false;
	}
}

void GameManager::checkEnemyCollision(Enemy& t_enemy) {
	/* Check If Out of Border */
	if (t_enemy.pos.y == g_Map.border.height) {
		t_enemy.pos = t_enemy.prevPos;
		t_enemy.speed++;
	}
	else if (t_enemy.pos.y == 0) {
		t_enemy.pos = t_enemy.prevPos;
		t_enemy.speed++;
	}
	if (g_Player.pos.x == -1) {
		t_enemy.pos = t_enemy.prevPos;
		t_enemy.speed++;
	}
	else if (g_Player.pos.x == g_Map.border.width + 1) {
		t_enemy.pos = t_enemy.prevPos;
		t_enemy.speed++;
	}

	/* Check for Blocks */
	for (auto b : v_Block) {
		if (b.x == t_enemy.pos.x) {
			if (b.y == t_enemy.pos.y) {
				t_enemy.pos = t_enemy.prevPos;
				t_enemy.speed++;
			}
		}
	}

	/* Check for other Enemies */
	for (auto e : v_Enemy) {
		if(e->num != t_enemy.num){
			if (e->pos.x == t_enemy.pos.x) {
				if (e->pos.y == t_enemy.pos.y) {
					t_enemy.pos = t_enemy.prevPos;
					t_enemy.speed++;
				}
			}
		}
	}
}