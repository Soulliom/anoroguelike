#include "../include/DEFINITIONS.h"

#include "../include/SceneManager.h"
#include "../include/InputManager.h"
#include "../include/Items.h"
#include "../include/Character.h"
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Map.h"
#include "../include/GameManager.h"

/*-------TODO--------
 Cripple shop; 2 items, 2 armors, 1 consumable randomly generated.
 loot generator (4th)
 Class bonus check in beginning of battle
 Combat Tutorial Scene 
 Attack Rolls (Hit Chance)
 selectState, enemy selection weapons
 (Melee weps +15% block, ranged 5% Block, Magic 10% Block, Sheilds 20% block and 25% Block)
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