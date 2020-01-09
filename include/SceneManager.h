#ifndef SCENE_M_H
#define SCENE_M_H

#include "DEFINITIONS.h"
#include "Items.h"
#include "Player.h"

//Contains different scenes
class SceneManager {
private:
	//If current g_Item is selected
	void isSelected(std::string text, int selectColor, int defaultColor, std::int8_t state, std::int8_t selectState);
public:
	//Console Init
	SceneManager();
	//Title Scene
	void titleScene();

	/* Settings Scenes */
	//Settings Scene
	void settingsScene(std::int8_t state, std::string diff, long seed);
	//Seed Setting Scene
	void seedScene(std::int8_t state, long long seed);
	//Character Tutorial 1
	void charTut1Scene();
	//Character Tutorial 2
	void charTut2Scene();
	//Combat Tutorial 1
	void combatTut1Scene();
	//Combat Tutorial 2
	void combatTut2Scene();

	/* Character Customization Scenes*/
	//Character Scene
	void characterScene(std::int8_t state, std::string race, std::string clas, Character::Stats stats, Character::Stats raceStats);

	/* Shop Scenes */
	//Shop Scene
	void shopScene(std::int8_t state, int gold);
	//Weapons Shop Scene
	void weaponsScene(std::int8_t state);
	//Melee Shop Scene
	void meleeScene(std::int8_t state, std::vector<Items::Weapon> weapons);
	//Ranged Shop Scene
	void rangedScene(std::int8_t state, std::vector<Items::Weapon> weapons);
	//Magic Shop Scene
	void magicScene(std::int8_t state, std::vector<Items::Weapon> weapons);
	//Armor Scene
	void armorsScene(std::int8_t state, std::vector<Items::Armor> armors);
	//Consumtion Scene
	void consumeScene(std::int8_t state, std::vector<Items::Consumable> consume);

	/* Items + Inventory */
	void viewWeapon(Items::Weapon weapon);
	void viewArmor(Items::Armor armor);
	void viewConsume(Items::Consumable consume);
	void viewInventory(std::int8_t state); //TODO: Check if weapon, armor, or consumables exist
	void viewWepInv(std::int8_t stateY, std::int8_t stateX);
	void viewArmInv(std::int8_t stateY, std::int8_t stateX);
	void viewConInv(std::int8_t stateY, std::int8_t stateX);

	/* Game Scenes */
	void wanderScene(std::int8_t stateX);
	void wanderActionScene(std::int8_t stateX);
	void otherScene(std::int8_t stateY);

private:
	HWND consoleWindow = GetConsoleWindow();
	HANDLE textConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

extern SceneManager g_Scene;
#endif 