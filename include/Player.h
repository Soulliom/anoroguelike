#ifndef PLAYER_H
#define PLAYER_H

#include "DEFINITIONS.h"
#include "Character.h"

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
	//Health
	float health = 0;
	int maxHealth = 1;
	//Mana
	float mana = 0;
	int maxMana = 1;
	//Speed
	int speed = 0;
	int maxSpeed = 15;
	//Stress
	float stress = 0;
	int maxStress = 1;
	//Levels
	int level = 0;
	const int MAXLEVEL = 20;
	//Experience
	int exp = 0;
	int maxExp = 1;
	//Weight
	float weight = 0;
	float maxWeight = 1;
	//Gold //TODO: difficulty divides gold/shop before game
	int gold = 500; //Spent during pregame shop

	/* Character Settings */
	//Player's Character
	Character ch;

	/* Functions */

private:
};
extern Player player;

#endif // !PLAYER_H
