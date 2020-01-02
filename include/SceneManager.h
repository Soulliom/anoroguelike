#ifndef SCENE_M_H
#define SCENE_M_H

#include "DEFINITIONS.h"
#include "Character.h"
#include "Items.h"
#include "Player.h"

//Contains different scenes
class SceneManager {
private:
	//If current item is selected
	void IsSelected(std::string text, int selectColor, int defaultColor, std::int8_t state, std::int8_t selectState);
public:
	//Console Init
	SceneManager();
	//Title Scene
	void TitleScene();

	/* Settings Scenes */
	//Settings Scene
	void SettingsScene(std::int8_t state, std::string diff, long seed);
	//Seed Setting Scene
	void SeedScene(std::int8_t state, long long seed);
	//Character Tutorial 1
	void CharTut1Scene();
	//Character Tutorial 2
	void CharTut2Scene();
	//Combat Tutorial 1
	void CombatTut1Scene();
	//Combat Tutorial 2
	void CombatTut2Scene();

	/* Character Customization Scenes*/
	//Character Scene
	void CharacterScene(std::int8_t state, std::string race, std::string clas, Character::Stats stats, Character::Stats raceStats);

	/* Shop Scenes */
	//Shop Scene
	void ShopScene(std::int8_t state, int gold);
	//Weapons Shop Scene
	void WeaponsScene(std::int8_t state);
	//Melee Shop Scene
	void MeleeScene(std::int8_t state, std::vector<Items::Weapon> weapons);
	//Ranged Shop Scene
	void RangedScene(std::int8_t state, std::vector<Items::Weapon> weapons);
	//Magic Shop Scene
	void MagicScene(std::int8_t state, std::vector<Items::Weapon> weapons);
	//Armor Scene
	void ArmorsScene(std::int8_t state, std::vector<Items::Armor> armors);
	//Consumtion Scene
	void ConsumeScene(std::int8_t state, std::vector<Items::Consumable> consume);

	/* Items + Inventory */
	void ViewWeapon(Items::Weapon weapon);
	void ViewArmor(Items::Armor armor);
	void ViewConsume(Items::Consumable consume);
	void ViewInventory(std::int8_t state); //TODO: Check if weapon, armor, or consumables exist
	void ViewWepInv(std::int8_t stateY, std::int8_t stateX);
	void ViewArmInv(std::int8_t stateY, std::int8_t stateX);
	void ViewConInv(std::int8_t stateY, std::int8_t stateX);

private:
	HWND consoleWindow = GetConsoleWindow();
	HANDLE textConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

extern SceneManager scene;
#endif 