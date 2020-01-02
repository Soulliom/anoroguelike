#include "../include/DEFINITIONS.h"

#include "../include/SceneManager.h"
#include "../include/InputManager.h"
#include "../include/Character.h"
#include "../include/Player.h"
#include "../include/Items.h"

/*-------TODO--------
 Main Screen (3rd)
 Class bonus check in each battle
 Item selection, equiped, slots, hands (2nd)
 Combat Tutorial Scene (4th)
 Vector enemies
 Balance Scenes (1st)
*/

/* Init Class Objects */
SceneManager scene; //Scenemanager (extern)
InputManager input; //Main input manager
InputManager bpinput; //Secondary input manager
Player player; //Player (extern)
Items item; //Items (extern)

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

	//Reset select state
	input.setSelectStateX(0);
	input.setSelectStateY(0);

	/* SETTINGS */
	//define continue, loop while continue button isnt pressed
	contin = false;
	while (!contin) {
		//Update Scene
		scene.SettingsScene(input.getSelectStateY(), player.diff, player.seed);

		//Get input
		keyPress = _getch();
		input.WSNav(keyPress, 4);

		switch (input.getSelectStateY()) {
		case 0: //Difficulty
			input.ADNav(keyPress, 2);
			input.DiffInput(input.selectState);
			break;

		case 1: //Seed -- Look above for comments
			if (keyPress == SPAC) {
				input.setSelectStateX(0);
				while (!contin) {
					input.WSNav(keyPress, 2);

					scene.SeedScene(input.getSelectStateY(), player.seed);
					keyPress = _getch();
					contin = input.SeedInput(keyPress);
				}
				contin = false;
			}
			break;

		case 2: //Tut on Character
			if (keyPress == SPAC) {
				input.setSelectStateX(0);
				scene.CharTut1Scene();
				input.Pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				scene.CharTut2Scene();
				input.Pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 3: //Tut on Combat
			if (keyPress == SPAC) {
				input.setSelectStateX(0);
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
		scene.CharacterScene(input.getSelectStateY(),
			player.ch.raceStr, player.ch.clasStr, player.ch.stats, *raceStat);

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
			//Weapons has 3 sections, Melee, Ranged, and Magic
			if (keyPress == SPAC) {
				input.setSelectStateY(0);
				while (!contin) {
					scene.WeaponsScene(input.getSelectStateY());

					keyPress = _getch();
					input.WSNav(keyPress, 3);
					switch (input.getSelectStateY()) {
					case 0: //Melee Shop
						if (keyPress == SPAC) {
							input.setSelectStateY(0);
							input.MeleeInput(keyPress);
							input.setSelectStateY(0);
						}
						break;

					case 1: //Ranged Shop
						if (keyPress == SPAC) {
							input.setSelectStateY(0);
							input.RangedInput(keyPress);
							input.setSelectStateY(0);
						}
						break;

					case 2: //Magic Shop
						if (keyPress == SPAC) {
							input.setSelectStateY(0);
							input.MagicInput(keyPress);
							input.setSelectStateY(0);
						}
						break;

					case 3: //Continue
						if (keyPress == SPAC) {
							contin = true;
						}
					}
				}
				//Reset input and contin
				input.setSelectStateY(0);
				contin = false;
			}
			break;

		case 1: //Armors Shop
			if (keyPress == SPAC) {
				input.setSelectStateY(0);

				input.ArmInput(keyPress);

				//Reset input and contin
				input.setSelectStateY(0);
				contin = false;
			}
			break;

		case 2: //Consumables Shop
			if (keyPress == SPAC) {
				input.setSelectStateY(0);

				input.ConInput(keyPress);

				//Reset input and contin
				input.setSelectStateY(0);
				contin = false;
			}
			break;

		case 3: //Inventory
			if (keyPress == SPAC) {
				input.setSelectStateY(0);

				while (!contin) {
					scene.ViewInventory(input.getSelectStateY());

					keyPress = _getch();
					input.WSNav(keyPress, 3);

					switch (input.getSelectStateY()) {
					case 0: // Weapons Inventory
						if (keyPress == SPAC) {
							input.setSelectStateY(0);
							while (!contin) {
								contin = input.WepInvInput(keyPress);
							}
							//Reset input and contin
							input.setSelectStateY(0);
							input.setSelectStateX(0);
							contin = false;
						}
						break;

					case 1: // Armor
						if (keyPress == SPAC) {
							input.setSelectStateY(0);
							while (!contin) {
								contin = input.ArmInvInput(keyPress);
							}
							//Reset input and contin
							input.setSelectStateY(0);
							input.setSelectStateX(0);
							contin = false;
						}
						break;

					case 2: // Consumables
						if (keyPress == SPAC) {
							input.setSelectStateY(0);
							while (!contin) {
								contin = input.ConInvInput(keyPress);
							}
							//Reset input and contin
							input.setSelectStateY(0);
							input.setSelectStateX(0);
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
				input.setSelectStateY(0);
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

	//Apply player stats
	player.applyStats();
	player.applyRacePassive();
	//Apply Weight of items
	player.applyCurrentWeight();

	//Reset selectstates
	input.setSelectStateX(0);
	input.setSelectStateY(0);

	contin = false;
	while (!contin) {
		// 2 main scenes, Wander, Battle.
		// Wander- stats, moving, inventory.
		// Battle- Actions, Enemy race/weapons/position, Player Position
	}

}