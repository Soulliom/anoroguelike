#ifndef PLAYER_H
#define PLAYER_H

#include "DEFINITIONS.h"
#include "InputManager.h"
#include "Character.h"
#include "Items.h"

class Player : public Character{
public:
	Player();

	/* Player Settings */
	// Health
	float health = 0;
	int maxHealth = 1;
	// Mana
	float mana = 0;
	int maxMana = 1;
	// Speed
	int speed = 0;
	int maxSpeed = 15;
	// Stress
	float stress = 0;
	int maxStress = 1;
	// Levels
	int level = 0;
	int maxLevel = 10;
	// Experience
	int exp = 0;
	int maxExp = 2;
	// Weight
	float weight = 0;
	float maxWeight = 1;
	// Gold (Pregame)
	int gold = 350; //Spent during pregame shop
	//In battle
	bool b_inBattle = false;

	/* Player's Inventory */
	// Player Weapons
	std::vector<Items::Weapon> wep;
	// Player Armor
	std::vector<Items::Armor> arm;
	// Player Consumables
	std::vector<Items::Consumable> con;

	/* Player's Selected Items */
	//Selected Weapon
	std::array<Items::Weapon, 2> selectedWep;
	//Selected Armor
	Items::Armor selectedArm;

	/* Functions */
	//Aquire Items
	void aquireWep(Items::Weapon wep);
	void aquireArm(Items::Armor arm);
	void aquireCon(Items::Consumable con);

	//Use Items
	void selectWep(Items::Weapon &wep);
	void selectArm(Items::Armor arm);
	void useConsume(Items::Consumable con, int state);

	//Applies actual stats (e.g. health) from stats (e.g. fortitude)
	void levelUp();
	//Applies race passives to Player
	void applyRacePassive();
	//Apply weight by from g_Player's inventory
	void applyCurrentWeight();

private:
};
extern Player g_Player;

#endif // !PLAYER_H
