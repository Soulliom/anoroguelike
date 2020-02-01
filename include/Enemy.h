#ifndef ENEMY_H
#define ENEMY_H

#include "DEFINITIONS.h"
#include "Character.h"
#include "Items.h"

class Enemy : public Character {
public:
	Enemy();

	//Set Position
	void setPosition();

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

	/* Enemy's Selected Items */
	//Selected Weapon
	Items::Weapon selectedWep;
	//Selected Armor
	Items::Armor selectedArm;

	//Take Damage
	virtual bool takeDamage(Items::Weapon t_wep);
	//Enemy turn
	void enemyTurn();

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
	
	/* Class turns */
	void warriorTurn();
	void rangerTurn();
	void magicianTurn();

};

#endif // ENEMY_H