#ifndef PLAYER_H
#define PLAYER_H

#include "DEFINITIONS.h"
#include "Character.h"
#include "Items.h"

class Player {
public:
	/* Game Settings */
	//Difficulty
	std::string diff = "Easy";
	float diffRate = 0.80f;
	// Seed
	unsigned int seed = NULL;
	//Turns;
	int turns = 0;
	int maxTurns = 1;

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
	int maxExp = 10;
	// Weight
	float weight = 0;
	float maxWeight = 1;
	// Gold (Pregame)
	int gold = 350; //Spent during pregame shop

	/* Player's Inventory */
	// Player Weapons
	std::vector<Items::Weapon> wep;
	// Player Armor
	std::vector<Items::Armor> arm;
	// Player Consumables
	std::vector<Items::Consumable> con;

	/* Character Settings */
	//Player's Character
	Character ch;

	/* Functions */
	void aquireWep(Items::Weapon wep);
	void aquireArm(Items::Armor arm);
	void aquireCon(Items::Consumable con);

	//Applies actual stats (e.g. health) from stats (e.g. fortitude)
	void applyStats();
	//Applies race passives to Player
	void applyRacePassive();
	//Apply weight
	void applyCurrentWeight();

private:
};
extern Player player;

#endif // !PLAYER_H
