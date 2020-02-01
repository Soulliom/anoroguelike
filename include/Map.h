#ifndef MAP_H
#define MAP_H

#include "DEFINITIONS.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

class Map {
private:
	const struct MapSize {
		int width = 56; //112
		int height = 12;
	};

public:
	/* Functions */
	//Display map NOTE: use dots to represent empty space
	void displayMap(Player t_Player, Character::Position t_Exit, std::vector<Enemy*> t_v_Enemy, std::vector<Character::Position> t_v_Block);

	/* MapSize */
	MapSize border;
};

extern Map g_Map;

#endif // !MAP_H