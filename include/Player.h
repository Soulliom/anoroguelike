#ifndef PLAYER_H
#define PLAYER_H

#include "DEFINITIONS.h"
#include "Character.h"
#include "Items.h"

class Player : public Character{
public:
	Player();

	/* Player Settings */
	// Health
	float health = 0.f;
	int maxHealth = 1;
	// Speed
	int speed = 0;
	int maxSpeed = 1;
	// Stress
	float stress = 0.f;
	int maxStress = 1;
	// Levels
	int level = 0;
	const int MAXLEVEL = 10;
	// Experience
	int exp = 0;
	int maxExp = 2;
	// Weight
	float weight = 0.f;
	int maxWeight = 1;
	// Hit Chances;
	float meleeHit = .9f;
	float rangedHit = .9f;
	float magicHit = .9f;

	// Gold (Pregame)
	int gold = 350; //Spent during pregame shop

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
	//Apply weight by from g_Player's inventory
	void applyCurrentWeight();
	//Set Position
	void setPosition();

private:
};
extern Player g_Player;

#endif // !PLAYER_H
