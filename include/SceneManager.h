#ifndef SCENE_M_H
#define SCENE_M_H

#include "DEFINITIONS.h"
#include "Items.h"
#include "Player.h"

//Contains different scenes
class SceneManager {
private:
	//If current g_Item is selected
	void isSelected(std::string t_text, int t_selectColor, int t_defaultColor, std::int8_t t_state, std::int8_t t_selectState);

public:
	//Console Init
	SceneManager();
	//Title Scene
	void titleScene();

	/* Settings Scenes */
	//Settings Scene
	void settingsScene(std::int8_t t_state, std::string t_diff, long t_seed);
	//Seed Setting Scene
	void seedScene(std::int8_t t_state, long long t_seed);
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
	void characterScene(std::int8_t t_state, std::string t_race, std::string t_clas, Character::Stats t_stats, Character::Stats t_raceStats);

	/* Shop Scenes */
	//Shop Scene
	void shopScene(std::int8_t t_state, int t_gold);
	//Weapons Shop Scene
	void weaponsScene(std::int8_t t_state);
	//Melee Shop Scene
	void meleeScene(std::int8_t t_state, std::vector<Items::Weapon> t_weapons);
	//Ranged Shop Scene
	void rangedScene(std::int8_t t_state, std::vector<Items::Weapon> t_weapons);
	//Magic Shop Scene
	void magicScene(std::int8_t t_state, std::vector<Items::Weapon> t_weapons);
	//Armor Scene
	void armorsScene(std::int8_t t_state, std::vector<Items::Armor> t_armors);
	//Consumtion Scene
	void consumeScene(std::int8_t t_state, std::vector<Items::Consumable> t_consume);

	/* View Items */
	void viewWeapon(Items::Weapon t_weapon);
	void viewArmor(Items::Armor t_armor);
	void viewConsume(Items::Consumable t_consume);
	void viewInventory(std::int8_t t_state);

	/* View Inventory */
	void viewWepInv(std::int8_t t_stateY, std::int8_t t_stateX);
	void viewArmInv(std::int8_t t_stateY, std::int8_t t_stateX);
	void viewConInv(std::int8_t t_stateY, std::int8_t t_stateX);

	/* Game Scenes */
	void wanderScene(std::int8_t t_state);
	void wanderActionScene(std::int8_t t_state);
	void otherScene(std::int8_t t_state);

	/* Extra Scenes */
	std::string typeOutput(Items::e_Type t_type);
	std::string enchantOutput(Items::e_Enchant t_enchant);

private:
	HWND consoleWindow = GetConsoleWindow();
	HANDLE textConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

extern SceneManager g_Scene;
#endif 