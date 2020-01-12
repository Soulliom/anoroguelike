#ifndef ENEMY_H
#define ENEMY_H

#include "DEFINITIONS.h"
#include "GameManager.h"
#include "Character.h"
#include "Items.h"
#include "Player.h"

class Enemy : public Character {
public:
	Enemy(std::string name);

	/* Enemy Settings */
	// Enemy Name
	std::string name;

	// Health
	float health = 0;
	int maxHealth = 1;
	// Speed
	int speed = 0;
	// Levels
	int level = 0;
	int maxLevel = 10;
	// Hit Chances;
	float meleeHit = .10;
	float rangedHit = .10;

	/* Enemy's Selected Items */
	//Selected Weapon
	Items::Weapon selectedWep;
	//Selected Armor
	Items::Armor selectedArm;

private:
	/* Functions */
	// Randomizes selectWep && selectArm 
	void randItems();
	//Randomize stats (e.g. fortitude) and applies them to actual stats (e.g. health), and race/class
	void setStats();
	//Randomizes race and applies them to passives to Enemy stats
	void randRace();
	//Selects Class, which dictates play style, based on Current Weapon.
	void whatsMyClass();
	//Randomizes Name
	void randName();
};

#endif // ENEMY_H