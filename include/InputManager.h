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
	void pause(std::string t_text, const unsigned int t_seconds, const unsigned int t_key = NULL);
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
	// WEAPONS
	void wepInput();
	void meleeInput();
	void rangedInput();
	void magicInput();
	bool viewWepInput(Items::Weapon t_wep);
	bool buyWepInput(Items::Weapon t_wep);
	void wepInvInput();
	// ARMORS 
	void armInput();
	bool viewArmInput(Items::Armor t_arm);
	bool buyArmInput(Items::Armor t_arm);
	void armInvInput();
	// CONSUMABLES
	void conInput();
	bool viewConInput(Items::Consumable t_con);
	bool buyConInput(Items::Consumable t_con);
	void conInvInput(); 

	// Player's Inventory
	void inventoryInput();

	//Game Scenes
	//Wandering
	int wanderInput();
	void wanderActionInput();
	int otherInput();

	/* Inputs for Options in Scenes */
	//Difficulty Input (Settings)
	void diffInput(SelectState t_selectState);
	//Race Character Customization Input 
	void raceInput(SelectState t_selectState);
	//Class Character Customization Input
	void clasInput(SelectState t_selectState);

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