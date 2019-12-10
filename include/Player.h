#ifndef PLAYER_H
#define PLAYER_H

#include "DEFINITIONS.h"
#include "Character.h"

class Player : public Character {
private:


public:
	/* Game Settings */
	//Difficulty
	std::string diff = "Normal";
	float diffRate = 1.00;
	// Seed
	unsigned int seed = NULL;

	/* Character Settings */
	//Health
	float health = 0;
	int maxHealth = 1;
	//Stamina
	float stamina = 0;
	int maxStamina = 1;
	//Stress
	float stress = 0;
	int maxStress = 1;
	//Levels
	int level = 0;
	int maxLevel = 20;
	//Experience
	int exp = 0;
	int maxExp = 1;
	//Weight
	float weight = 0;
	float maxWeight = 1;
	//Gold //TODO: difficulty divides gold/shop before game
	int gold = 500; //can be spent in black market shops, has weight 
	//Turns;
	int turns;
	int maxTurns;
	//Stats
	Stats pStats;
};
extern Player player;

#endif // !PLAYER_H
