#ifndef GAME_M_H
#define GAME_M_H

#include "DEFINITIONS.h"
#include "Player.h"

class GameManager {
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

	//Is Player turn
	bool b_isPlayerTurn = false;

	//Loot nearby
	bool b_isLoot = false;
private:
};

extern GameManager g_Game;
#endif 