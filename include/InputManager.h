#ifndef INPUT_M_H
#define INPUT_M_H

#include "DEFINITIONS.h"
#include "Items.h"
#include "Character.h"

//Saves SceneState and updates when different scenes are loaded
class InputManager {
private:
	//Current Selected Item
	struct SelectState {
		int x = 0;
		int y = 0;
	};

	// SelectState Obj
	SelectState selectState;

public:
	/* Getters/Setters */
	int getSelectStateX();
	int getSelectStateY();
	SelectState getSelectState();
	void resetSelectState();
	
	//GameState
	enum class e_gameState {
		ACTION,
		INSPECT,
		PLAYER,
		ENEMY,
		MAP
	};
	  
	e_gameState bState = e_gameState::INSPECT;

	/* Pauses, Inputs, Navigations.*/
	//Text- What text will be displayed. Seconds- length of delay. Key- what key is needed to press to continue, NULL for none.
	void pause(std::string t_text, const unsigned int t_seconds, const unsigned int t_key = NULL);
	//Output only text, is dependent on an input
	void output(std::string t_text, const unsigned int t_seconds);
	//cin String Input
	std::string stringInput(std::string t_text);
	//cin Int Input
	int intInput(std::string t_text);
	//Up/Down Navigation
	void upDownNav(unsigned int t_input, const int max);
	//Left/Right Navigation
	void leftRightNav(unsigned int t_input, const int max);

	/* Inputs for Specific Scenes */
	// Returns b_contin
	void seedInput();
	/* SHOP */
	// WEAPONS
	void weapons();
	void melee();
	void ranged();
	void magic();
	bool viewWeapons(Items::Weapon t_wep);
	bool buyWeapons(Items::Weapon t_wep);
	void wepInv();
	// ARMORS 
	void armors();
	bool viewArmors(Items::Armor t_arm);
	bool buyArmors(Items::Armor t_arm);
	void armInv();
	// CONSUMABLES
	void consume();
	bool viewCon(Items::Consumable t_con);
	bool buyCon(Items::Consumable t_con);
	void conInv();

	// Player's Inventory
	void inventory();

	//Game Scenes
	//Wandering
	bool wander();
	bool other();
	//Battling
	bool battle();
	void battleAction();
	void playerAttack(Items::Weapon& t_wep);
	//Level up input
	void levelUp(Character::Stats& t_stats);

	/* Inputs for Options in Scenes */
	//Difficulty Input (Settings)
	void diffInput(SelectState t_selectState);
	//Race Character Customization Input 
	void raceInput(SelectState t_selectState);
	//Class Character Customization Input
	void clasInput(SelectState t_selectState);

	/* Keypress Inputs */
	// Movement
	void moveInput();
};

//Main g_Input
extern InputManager g_Input;
//Backup g_Input
extern InputManager g_Bpinput;
#endif 