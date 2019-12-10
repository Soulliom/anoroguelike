#include "../include/SceneManager.h"
#include "../include/InputManager.h"
#include "../include/Character.h"
#include "../include/Player.h"
#include "../include/DEFINITIONS.h"

/* TODO
 Combat Scene
 Character Scene // Randomize stufs
 //Race -> Class -> Stats (All one scene)
*/

/* Init Class Objects*/
SceneManager scene;
InputManager input;
Player player;
Character demoChar;

int main() {
	srand(time(NULL));

	/* Init */
	bool contin = false;
	int keyPress;

	//Print title scene
	scene.TitleScene();
	input.Pause("Press [Space] to Continue.", 1, SPAC); 

	/* Settings */
	//Randomize seed
	player.seed = rand() % 99999999 + 1111;
	//Reset select state
	input.setSelectState(0, 0);
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
			if (keyPress == SPAC) {
				input.setSelectState(0, 0);
				//Loop scene + input while not continued
				while (!contin) {
					//print difficulty scene
					scene.DiffScene(input.getSelectStateY(), player.diff);
					//Get input
					keyPress = _getch();
					//return true to continue, return false to keep looping - input
					contin = input.DiffInput(keyPress);
				}
				contin = false;
			}
			break;

		case 1: //Seed -- Look above for comments
			if (keyPress == SPAC) {
				input.setSelectState(0, 0);
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
				input.setSelectState(0, 0);
				scene.CharTut1Scene();
				input.Pause("Press [Space] to cotinue to the next Page.", 2, SPAC);
				scene.CharTut2Scene();
				input.Pause("Press [Space] to Continue.", 2, SPAC);
			}
			break;

		case 3: //Tut on Combat
			if (keyPress == SPAC) {
				input.setSelectState(0, 0);
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

	/* Character Customization*/
	contin = false;
	while (!contin) {
		scene.CharacterScene(input.getSelectStateY(), player.raceStr, player.clasStr, player.pStats);
		//...
	}
}
