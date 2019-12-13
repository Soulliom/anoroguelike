#include "../include/DEFINITIONS.h"

#include "../include/SceneManager.h"
#include "../include/InputManager.h"
#include "../include/Character.h"
#include "../include/Player.h"

/* -------TODO--------
 Shop
 Apply Race Passives
 Combat Tutorial Scene
 //Vector enemies
*/

/* Init Class Objects*/
SceneManager scene; //Scenemanager (1)
InputManager input; //Main inputmanager (1)
InputManager bpinput; //Secondary input manager(1)
Player player; //Player (1)

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
		//Print Setting Scene
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

		//Print Scene
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
	//Delete pointer
	delete(raceStat);
	//Reset selectstates
	input.setSelectStateX(0);
	input.setSelectStateY(0);
	bpinput.setSelectStateY(0);
	bpinput.setSelectStateX(0);

	/* SHOP */
	contin = false;
}