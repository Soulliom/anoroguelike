#ifndef GAME_M_H
#define GAME_M_H

#include "DEFINITIONS.h"
#include "Items.h"
#include "Enemy.h"

class GameManager {
public:
	/* GAME SETTINGS */
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
	//In battle
	bool b_inBattle = false;

	/* GAME */
	std::vector<Enemy> v_Enemy;
	std::vector<Items::Weapon> v_wepLoot;
	std::vector<Items::Armor> v_armLoot;
	std::vector<Items::Consumable> v_conLoot;
	std::vector<Character::Position> v_Block;
	Character::Position Exit;

	/* GAME SECTIONS */
	void init();
	void settings();
	void character();
	void shop();
	void game();

	/* GENERATORS */
	/* Item Generators */
	//randomly generates any weapon
	Items::Weapon wepGenerator();
	//randomly generates any armor
	Items::Armor armGenerator();
	//randomly generates any consumable
	Items::Consumable conGenerator();

	/* Room Generator */
	//Randomly generates a room full of enemies,
	void roomGenerator();

	void checkCollision();
private:
};

extern GameManager g_Game;
#endif 