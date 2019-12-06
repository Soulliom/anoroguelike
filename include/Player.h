#ifndef PLAYER_H
#define PLAYER_H

#include "DEFINITIONS.h"

class Player {
private:

public:
	std::string diff = "Normal";
	float diffRate = 1.00;

	// 8 number max
	unsigned int seed = NULL;
};

#endif // !PLAYER_H
