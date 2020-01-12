#ifndef GAME_M_H
#define GAME_M_H

#include "DEFINITIONS.h"
#include "Player.h"
#include "Items.h"

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

	/* GENERATORS */
	/* Item Generators */
	//randomly generates any weapon
	Items::Weapon wepGenerator();
	//randomly generates any armor
	Items::Armor armGenerator();
	//randomly generates any consumable
	Items::Consumable conGenerator();


private:
};

extern GameManager g_Game;
#endif 