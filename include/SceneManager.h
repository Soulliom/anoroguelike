#ifndef SCENE_M_H
#define SCENE_M_H

#include "DEFINITIONS.h"
#include "Items.h"
#include "Character.h"

//Contains different scenes
class SceneManager {
public:
	//If current g_Item is selected
	void isSelected(std::string t_text, int t_selectColor, int t_defaultColor, int t_state, int t_selectState);

	//Console Init
	SceneManager();
	//Title Scene
	void title();

	/* Settings Scenes */
	//Settings Scene
	void settings(int t_state, std::string t_diff, long t_seed);
	//Seed Setting Scene
	void seed(int t_state, long long t_seed);
	//Character Tutorial 1
	void charTut1();
	//Character Tutorial 2
	void charTut2();
	//Combat Tutorial 1
	void combatTut1();
	//Combat Tutorial 2
	void combatTut2();

	/* Character Customization Scenes*/
	//Character Scene
	void character(int t_state, std::string t_race, std::string t_clas, Character::Stats t_stats, Character::Stats t_raceStats);

	/* Shop Scenes */
	//Shop Scene
	void shop(int t_state, int t_gold);
	//Weapons Shop Scene
	void weapons(int t_state);
	//Melee Shop Scene
	void melee(int t_state, std::vector<Items::Weapon> t_weapons);
	//Ranged Shop Scene
	void ranged(int t_state, std::vector<Items::Weapon> t_weapons);
	//Magic Shop Scene
	void magic(int t_state, std::vector<Items::Weapon> t_weapons);
	//Armor Scene
	void armors(int t_state, std::vector<Items::Armor> t_armors);
	//Consumtion Scene
	void consume(int t_state, std::vector<Items::Consumable> t_consume);

	/* View Items */
	void viewWeapon(Items::Weapon t_weapon);
	void viewArmor(Items::Armor t_armor);
	void viewConsume(Items::Consumable t_consume);
	void viewInventory(int t_state);

	/* View Inventory */
	void viewWepInv(int t_stateY, int t_stateX);
	void viewArmInv(int t_stateY, int t_stateX);
	void viewConInv(int t_stateY, int t_stateX);

	/* Game Scenes */
	//Wander
	void wander(int t_stateX);
	void action(int t_stateX);
	void other(int t_stateY);
	//Battle
	void battleMap(int t_stateX);
	void battleEnemy(int t_stateX);
	void battlePlayer(int t_stateX);
	void battleAction(int t_stateY);
	void playerAttack(Items::Weapon t_selectedWep, int& t_stateY);
	//Level up
	void levelUp(Character::Stats t_stats, int t_stateY);

	/* Extra Scenes */
	std::string typeOutput(Items::e_Type t_type);
	std::string enchantOutput(Items::e_Enchant t_enchant);

	//Line of Text
	void enemyOutput();

private:
	HWND consoleWindow = GetConsoleWindow();
	HANDLE textConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

extern SceneManager g_Scene;
#endif 