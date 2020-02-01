#include "../include/DEFINITIONS.h"

#include "../include/SceneManager.h"
#include "../include/InputManager.h"
#include "../include/Items.h"
#include "../include/Character.h"
#include "../include/Player.h"
#include "../include/Map.h"
#include "../include/GameManager.h"

/*-------TODO--------

 */

GameManager g_Game;
SceneManager g_Scene;
InputManager g_Input;
InputManager g_Bpinput;
Items g_Item;
Player g_Player;
Map g_Map;

int main() {
	/* INIT */
	g_Game.init();

	/* SETTINGS */
	g_Game.settings();

	/* CHARACTER CUSTOMIZATION */
	g_Game.character();

	/* SHOP */
	g_Game.shop();

	/* GAME */
	g_Game.game();

	g_Input.pause("Thanks for playing! Press [Space] to Continue.", 1, SPAC);
}