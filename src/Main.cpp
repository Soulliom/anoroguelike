#include "../include/DEFINITIONS.h"

#include "../include/SceneManager.h"
#include "../include/InputManager.h"
#include "../include/Character.h"
#include "../include/Player.h"
#include "../include/Items.h"

/*-------TODO--------
 1/2 dmg from other class weapons
 Battle Scene
 Class bonus check in each battle
 Combat Tutorial Scene 
 Vector enemies
 Balance Scenes 
 if weight > maxweight -50% speed
*/

/* Init Class Objects */
SceneManager scene; //Scenemanager (extern)
InputManager input; //Main input manager (extern)
InputManager bpinput; //Secondary input manager
Items item; //Items (extern)
Player player; //Player (extern)

int main() {
	/* INIT */
	bool contin = false;
	unsigned int keyPress = 0;
	//Randomize seed
	srand(time(NULL));
	player.seed = rand() % 99998888 + 1111;
	//Print title scene
	scene.TitleScene();
	input.Pause("Press [Space] to Continue.", 1, SPAC);

	/* SETTINGS */
	//define continue, loop while continue button isnt pressed
	contin = false;
	while (!contin) {
		//Update Scene
		scene.SettingsScene(input.getSelectStateY(), player.diff, player.seed);

		//Get input
		keyPress = _getch();
		//Check if input was for navigation
		input.WSNav(keyPress, 4);

		//Use input otherwise
		switch (input.getSelectStateY()) {
		case 0: //Difficulty
			input.ADNav(keyPress, 2);
			input.DiffInput(input.selectState);
			break;

		case 1: //Seed -- Look above for comments
			if (keyPress == SPAC) {
				input.SeedInput();
			}
			break;

		case 2: //Tut on Character
			if (keyPress == SPAC) {
				scene.CharTut1Scene();
				input.Pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				scene.CharTut2Scene();
				input.Pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 3: //Tut on Combat
			if (keyPress == SPAC) {
				scene.CombatTut1Scene();
				input.Pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				scene.CombatTut2Scene();
				input.Pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 4: //Continue
			if (keyPress == SPAC) {
				contin = true;
				//Init seed
				if (player.seed == 0) {
					//if 0 randomize seed
					srand(time(NULL));
				}
				else {
					//if seed is present, use seed
					srand(player.seed);
				}
			}
			break;
		}
	};
	//Reset selectstates
	input.setSelectStateY(0);
	input.setSelectStateX(0);

	/* CHARACTER CUSTOMIZATION */
	//Temporary raceStats which show stats upon choosing a race and applies them when continue = true.
	Character::Stats* raceStat = new Character::Stats;
	//Randomize character stats
	player.ch.randStats();
	//Reset selectstates
	contin = false;
	while (!contin) {
		//Update Player's stats with current race
		player.ch.configRaceStats(raceStat);

		//Update Scene
		scene.CharacterScene(input.getSelectStateY(), player.ch.raceStr, player.ch.clasStr, player.ch.stats, *raceStat);

		//Get input
		keyPress = _getch();
		input.WSNav(keyPress, 3);

		switch (input.getSelectStateY()) {
		case 0: //Race
			input.ADNav(keyPress, 5);
			input.RaceInput(input.selectState);
			break;

		case 1: //Class
			bpinput.ADNav(keyPress, 3);
			input.ClasInput(bpinput.selectState);
			break;

		case 2: //Reset Stats + Rand Stats
			if (keyPress == SPAC) {
				player.ch.resetStats();
				player.ch.randStats();
			}
			break;

		case 3: //Continue
			if (keyPress == SPAC) {
				player.ch.combineRaceStats(raceStat);
				contin = true;
			}
			break;
		}
	}
	//Delete unnecessary pointer
	delete(raceStat);
	//Reset selectstates
	input.setSelectStateX(0);
	input.setSelectStateY(0);
	bpinput.setSelectStateY(0);
	bpinput.setSelectStateX(0);

	/* SHOP */
	//Change gold accourding to difficulty
	player.gold = player.gold / player.diffRate;
	contin = false;
	while (!contin) {
		//Update Scene
		scene.ShopScene(input.getSelectStateY(), player.gold);

		keyPress = _getch();
		input.WSNav(keyPress, 4);

		switch (input.getSelectStateY()) {
		case 0: //Weapons Shop
			if (keyPress == SPAC) {
				input.WepInput();
				contin = false;
			}
			break;

		case 1: //Armors Shop
			if (keyPress == SPAC) {
				input.ArmInput();
				contin = false;
			}
			break;

		case 2: //Consumables Shop
			if (keyPress == SPAC) {
				input.ConInput();
				contin = false;
			}
			break;

		case 3: //Inventory
			if (keyPress == SPAC) {
				input.InventoryInput();
				contin = false;
			}
			break;

		case 4: // Continue
			if (keyPress == SPAC) {
				contin = true;
			}
			break;
		}
	}
	//Reset selectstates
	input.setSelectStateX(0);
	input.setSelectStateY(0);

	/* Player Finalization */
	//Apply player stats
	player.applyStats();
	player.applyRacePassive();
	//Apply Weight of items
	player.applyCurrentWeight();
	
	/* GAME */
	contin = false;
	while (!contin) {
		// Battle- Actions, Enemy race/weapons/position, Player Position
		if (!player.inBattle) { //Wandering Scene
			scene.WanderScene(input.getSelectStateX());

			keyPress = _getch();
			input.ADNav(keyPress, 2);
			switch (input.getSelectStateX()) {
			case 0: // Actions (move forward)
				break;
			case 1: // Inventory (Prompts inventory)
				if (keyPress == SPAC) {
					input.InventoryInput();
				}
				break;
			case 2: // Other (Game Exit, Tutorials)
				break;
			}
		}
		else if(player.inBattle){ //Battling Scene

		}
	}
}