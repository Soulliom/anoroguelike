#ifndef INPUT_M_H
#define INPUT_M_H

#include "DEFINITIONS.h"
#include "Items.h"

//Saves SceneState and updates when different scenes are loaded
class InputManager {
private:
	//Current Selected Item
	struct selectStateStruct {
		std::int8_t x = 0;
		std::int8_t y = 0;
	};
public:
	/* Pauses, Inputs, Navigations.*/
	//Text- What text will be displayed. Seconds- length of delay. Key- what key is needed to press to continue, NULL for none.
	void Pause(std::string text, const unsigned int seconds, const unsigned int key = NULL);
	//cin String Input
	std::string StringInput(std::string text);
	//cin Int Input
	int IntInput(std::string text);
	//Up/Down Navigation
	void WSNav(unsigned int input, const int max);
	//Left/Right Navigation
	void ADNav(unsigned int input, const int max);
	//Up/Left/Down/Right Navigation (Patent Pending)

	/* Inputs for Specific Scenes */
	// Returns contin
	bool SeedInput(int keyPress);
	// WEAPONS
	// Melee Input
	void MeleeInput(int keyPress);
	// Ranged Input
	void RangedInput(int KeyPress);
	// Magic Input
	void MagicInput(int KeyPress);
	// Inspect Wep / Returns contin
	bool ViewWepInput(int keyPress, Items::Weapon wep);
	// Buy Wep / Returns contin
	bool BuyWepInput(int keyPress, Items::Weapon wep);
	// Wep Inventory
	bool WepInvInput(int keyPress);
	// ARMORS 
	// Armor Shop
	void ArmInput(int keyPress);
	bool ViewArmInput(int keyPress, Items::Armor arm);
	bool BuyArmInput(int keyPress, Items::Armor arm);
	bool ArmInvInput(int keyPress);
	// CONSUMABLES
	// Consumable Shop
	
	void ConInput(int keyPress);
	bool ViewConInput(int keyPress, Items::Consumable con);
	bool BuyConInput(int keyPress, Items::Consumable con);
	bool ConInvInput(int keyPress); 

	/* Inputs for Options in Scenes */
	//Difficulty Input
	void DiffInput(selectStateStruct selectState);
	//Race Character Customization Input
	void RaceInput(selectStateStruct selectState);
	//Class Character Customization Input
	void ClasInput(selectStateStruct selectState);

	// SelectState Obj
	selectStateStruct selectState;

	/* Getters/Setters */
	//Set Select State
	void setSelectStateX(unsigned int x);
	void setSelectStateY(unsigned int y);
	//Get Select State
	int getSelectStateX();
	int getSelectStateY();
};

#endif 