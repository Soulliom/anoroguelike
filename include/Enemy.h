#ifndef ENEMY_H
#define ENEMY_H

#include "DEFINITIONS.h"
#include "Character.h"
#include "Items.h"

class Enemy : public Character {
public:
	Enemy();

	/* Enemy Settings */
	// Enemy Name
	std::string name;
	int num = -1;

	// Health
	int health = 0;
	// Speed
	int speed = 0;
	int maxSpeed = 1;
	// Levels
	int level = 0;
	const int MAXLEVEL = 10;
	// Hit Chances;
	float meleeHit = .0f;
	float rangedHit = .0f;
	float magicHit = .0f;

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
	//Set Position
	void setPosition();
};

#endif // ENEMY_H