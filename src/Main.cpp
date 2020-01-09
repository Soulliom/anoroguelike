#include "../include/DEFINITIONS.h"

#include "../include/GameManager.h"
#include "../include/SceneManager.h"
#include "../include/InputManager.h"
#include "../include/Character.h"
#include "../include/Player.h"
#include "../include/Items.h"
#include "../include/Enemy.h"

/*-------TODO--------
 1/2 dmg from other class weapons
 random enemy gen
 random wep gen
 Battle Scene
 Class bonus check in each battle
 Combat Tutorial Scene 
 Vector enemies
 Balance Scenes 
 if weight > maxweight -50% speed
*/

GameManager g_Game;
SceneManager g_Scene;
InputManager g_Input;
InputManager g_Bpinput;
Items g_Item;
Player g_Player;
Enemy g_Enemy;

int main() {
	/* INIT */
	bool b_contin = false;
	unsigned int keyPress = 0;
	//Randomize seed
	srand(time(NULL));
	g_Game.seed = rand() % 99998888 + 1111;
	//Print title g_Scene
	g_Scene.titleScene();
	g_Input.pause("Press [Space] to Continue.", 1, SPAC);

	/* SETTINGS */
	//define continue, loop while continue button isnt pressed
	b_contin = false;
	while (!b_contin) {
		//Update Scene
		g_Scene.settingsScene(g_Input.getSelectStateY(), g_Game.diff, g_Game.seed);

		//Get g_Input
		keyPress = _getch();
		//Check if g_Input was for navigation
		g_Input.upDownNav(keyPress, 4);

		//Use g_Input otherwise
		switch (g_Input.getSelectStateY()) {
		case 0: //Difficulty
			g_Input.leftRightNav(keyPress, 2);
			g_Input.diffInput(g_Input.selectState);
			break;

		case 1: //Seed -- Look above for comments
			if (keyPress == SPAC) {
				g_Input.seedInput();
			}
			break;

		case 2: //Tut on Character
			if (keyPress == SPAC) {
				g_Scene.charTut1Scene();
				g_Input.pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				g_Scene.charTut2Scene();
				g_Input.pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 3: //Tut on Combat
			if (keyPress == SPAC) {
				g_Scene.combatTut1Scene();
				g_Input.pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				g_Scene.combatTut2Scene();
				g_Input.pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 4: //Continue
			if (keyPress == SPAC) {
				b_contin = true;
				//Init seed
				if (g_Game.seed == 0) {
					//if 0 randomize seed
					srand(time(NULL));
				}
				else {
					//if seed is present, use seed
					srand(g_Game.seed);
				}
			}
			break;
		}
	};
	//Reset selectstates
	g_Input.selectState.reset();

	/* CHARACTER CUSTOMIZATION */
	//Temporary raceStats which show stats upon choosing a race and applies them when continue = true.
	Character::Stats* raceStat = new Character::Stats;
	//Randomize character stats
	g_Player.randStats();
	//Reset selectstates
	b_contin = false;
	while (!b_contin) {
		//Update Player's stats with current race
		g_Player.configRaceStats(raceStat);

		//Update Scene
		g_Scene.characterScene(g_Input.getSelectStateY(), g_Player.raceStr, g_Player.clasStr, g_Player.stats, *raceStat);

		//Get g_Input
		keyPress = _getch();
		g_Input.upDownNav(keyPress, 3);

		switch (g_Input.getSelectStateY()) {
		case 0: //Race
			g_Input.leftRightNav(keyPress, 5);
			g_Input.raceInput(g_Input.selectState);
			break;

		case 1: //Class
			g_Bpinput.leftRightNav(keyPress, 3);
			g_Input.clasInput(g_Bpinput.selectState);
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
	//Delete unnecessary pointer
	delete(raceStat);
	//Reset selectstates
	g_Input.selectState.reset();
	g_Bpinput.selectState.reset();

	/* SHOP */
	//Change gold accourding to difficulty 
	g_Player.gold = round(g_Player.gold / g_Game.diffRate);
	b_contin = false;
	while (!b_contin) {
		//Update Scene
		g_Scene.shopScene(g_Input.getSelectStateY(), g_Player.gold);

		keyPress = _getch();
		g_Input.upDownNav(keyPress, 4);

		switch (g_Input.getSelectStateY()) {
		case 0: //Weapons Shop
			if (keyPress == SPAC) {
				g_Input.wepInput();
				b_contin = false;
			}
			break;

		case 1: //Armors Shop
			if (keyPress == SPAC) {
				g_Input.armInput();
				b_contin = false;
			}
			break;

		case 2: //Consumables Shop
			if (keyPress == SPAC) {
				g_Input.conInput();
				b_contin = false;
			}
			break;

		case 3: //Inventory
			if (keyPress == SPAC) {
				g_Input.inventoryInput();
				b_contin = false;
			}
			break;

		case 4: // Continue
			if (keyPress == SPAC) {
				b_contin = true;
			}
			break;
		}
	}
	//Reset selectstates
	g_Input.selectState.reset();

	/* Player Finalization */
	//Apply g_Player stats
	g_Player.levelUp();
	g_Player.applyRacePassive();
	//Apply Weight of items
	g_Player.applyCurrentWeight();
	
	/* GAME */
	//g_Game over condition
	b_contin = false;
	while (!b_contin) {
		// Battle- Actions, Enemy race/weapons/position, Player Position
		if (!g_Player.b_inBattle) { //Wandering Scene
			b_contin = g_Input.wanderInput();
		}
		else if(g_Player.b_inBattle){ //Battling Scene

		}
	}

	std::cout << "Thanks for playing! Press [Space] to continue";
	_getch();
}