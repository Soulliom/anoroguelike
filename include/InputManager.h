#ifndef INPUT_M_H
#define INPUT_M_H

#include "DEFINITIONS.h"
#include "Items.h"

//Saves SceneState and updates when different scenes are loaded
class InputManager {
private:
	//Current Selected Item
	struct SelectState {
		std::int8_t x = 0;
		std::int8_t y = 0;

		void reset();
	};
public:
	/* Pauses, Inputs, Navigations.*/
	//Text- What text will be displayed. Seconds- length of delay. Key- what key is needed to press to continue, NULL for none.
	void pause(std::string text, const unsigned int seconds, const unsigned int key = NULL);
	//cin String Input
	std::string stringInput(std::string text);
	//cin Int Input
	int intInput(std::string text);
	//Up/Down Navigation
	void upDownNav(unsigned int g_Input, const int max);
	//Left/Right Navigation
	void leftRightNav(unsigned int g_Input, const int max);
	//Up/Left/Down/Right Navigation (Patent Pending)

	/* Inputs for Specific Scenes */
	// Returns b_contin
	void seedInput();
	// WEAPONS
	void wepInput();
	void meleeInput();
	void rangedInput();
	void magicInput();
	bool viewWepInput(Items::Weapon wep);
	bool buyWepInput(Items::Weapon wep);
	void wepInvInput();
	// ARMORS 
	void armInput();
	bool viewArmInput(Items::Armor arm);
	bool buyArmInput(Items::Armor arm);
	void armInvInput();
	// CONSUMABLES
	void conInput();
	bool viewConInput(Items::Consumable con);
	bool buyConInput(Items::Consumable con);
	void conInvInput(); 

	// Player's Inventory
	void inventoryInput();

	//g_Game Scenes
	//Wandering
	int wanderInput();
	void wanderActionInput();
	int otherInput();

	/* Inputs for Options in Scenes */
	//Difficulty Input (Settings)
	void diffInput(SelectState selectState);
	//Race Character Customization Input 
	void raceInput(SelectState selectState);
	//Class Character Customization Input
	void clasInput(SelectState selectState);

	// SelectState Obj
	SelectState selectState;

	/* Getters/Setters */
	//Get Select State
	int getSelectStateX();
	int getSelectStateY();
};

//Main g_Input
extern InputManager g_Input;
//Backup g_Input
extern InputManager g_Bpinput;
#endif 