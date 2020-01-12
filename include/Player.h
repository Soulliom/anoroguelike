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
	// Hit Chances;
	float meleeHit = .10;
	float rangedHit = .10;
	float specialHit = .10;

	// Gold (Pregame)
	int gold = 350; //Spent during pregame shop
	//In battle
	bool b_inBattle = false;

	/* Player's Inventory */
	// Player Weapons
	std::vector<Items::Weapon> v_Wep;
	// Player Armor
	std::vector<Items::Armor> v_Arm;
	// Player Consumables
	std::vector<Items::Consumable> v_Con;

	/* Player's Selected Items */
	//Selected Weapon
	std::array<Items::Weapon, 2> selectedWep;
	//Selected Armor
	Items::Armor selectedArm;

	/* Functions */
	//Aquire Items
	void aquireWep(Items::Weapon t_wep);
	void aquireArm(Items::Armor t_arm);
	void aquireCon(Items::Consumable t_con);

	//Use Items
	void selectWep(Items::Weapon &t_wep);
	void selectArm(Items::Armor t_arm);
	void useConsume(Items::Consumable t_con, int t_state);

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
