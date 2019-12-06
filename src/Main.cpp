#include "../include/SceneManager.h"
#include "../include/InputManager.h"
#include "../include/Player.h"
#include "../include/DEFINITIONS.h"

/* TODO
 comment for clarity
 Seedfunction
 DiffFunction
 Virtual? Character class
 extern objects
 Game function
*/

/* Init */
SceneManager scene;
InputManager input;
Player player;

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
	input.setSelectState(0);
	//define continue, loop while continue button isnt pressed
	contin = false;
	while (!contin) {
		//Print Setting Scene
		scene.SettingsScene(input.getSelectState(), player.diff, player.seed);

		//Get input
		keyPress = _getch();
		input.WSNav(keyPress, 2);
		switch (input.getSelectState()) {
		case 0: //Difficulty
			if (keyPress == SPAC) {
				input.setSelectState(0);
				//Loop scene + input while not continued
				while (!contin) {
					//print difficulty scene
					scene.DiffScene(input.getSelectState(), player.diff);
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
				input.setSelectState(0);
				while (!contin) {
					scene.SeedScene(input.getSelectState(), player.seed);
					keyPress = _getch();
					contin = input.SeedInput(keyPress);
				}
				contin = false;
			}
			break;

		case 2: //Continue
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
}
