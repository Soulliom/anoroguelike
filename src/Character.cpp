#include "../include/Character.h"

void Character::randStats(int t_extra) {
	
	//Add 2 to each stat
	stats.strength = 1;
	stats.fortitude = 1;
	stats.agility = 1;
	stats.wisdom = 1;
	stats.perception = 2;

	//Skip
	bool skip = false;
	//Maximum number of points
	int max = 10 + t_extra;
	//Points given to a stat
	unsigned int min = rand() % (max / 3) + 2;
	//Randomized stat order
	unsigned int chs = 0;
	//Each past stat
	std::array<unsigned int, 5> rmb;

	int total = 0;

	while (max > 0) {
		//Runs loop for amount of stats
		for (int i = 0; i < 5; i++) {
			//Chooses random stat to start first
			chs = rand() % 5;
			//Remembers stat order
			rmb[i] = chs;
			//Checks if chs is repeated stat
			for (int x = 0; x < i; x++) {
				if (rmb[x] == chs) {
					//Skip stat
					skip = true;
					//Go back
					i--;
				}
			}

			if (!skip && max > 0) {
				//Randomize stat
				min = (rand() % max / 3) + 1;
				max -= min;

				//Choose random stat
				switch (chs) {
				case 0:
					stats.strength += min;
					break;
				case 1:
					stats.fortitude += min;
					break;
				case 2:
					stats.agility += min;
					break;
				case 3:
					stats.wisdom += min;
					break;
				case 4:
					stats.perception += min;
					break;
				}
			}
				skip = false;
		}

		for (int i = 0; i < 4; i++) {
			//Reset stats
			rmb[i] = 0;
		}
	}
}

void Character::resetStats() {
	stats.strength = 0;
	stats.fortitude = 0;
	stats.agility = 0;
	stats.wisdom = 0;
	stats.perception = 0;
}

void Character::configRaceStats(Stats& t_raceStat) {
	switch(race){
	case Character::e_Race::ELF:
		t_raceStat.strength = -1;
		t_raceStat.fortitude = 0;
		t_raceStat.agility = 0;
		t_raceStat.wisdom = 2;
		t_raceStat.perception = 1;
		break;

	case Character::e_Race::ORC:
		t_raceStat.strength = 2;
		t_raceStat.fortitude = 1;
		t_raceStat.agility = 0;
		t_raceStat.wisdom = 0;
		t_raceStat.perception = -2;
		break;

	case Character::e_Race::HUMAN:
		t_raceStat.strength = 0;
		t_raceStat.fortitude = 1;
		t_raceStat.agility = 0;
		t_raceStat.wisdom = 1;
		t_raceStat.perception = 1;
		break;

	case Character::e_Race::GOBLIN:
		t_raceStat.strength = 1;
		t_raceStat.fortitude = 0;
		t_raceStat.agility = 1;
		t_raceStat.wisdom = 0;
		t_raceStat.perception = 1;
		break;

	case Character::e_Race::DWARF:
		t_raceStat.strength = 1;
		t_raceStat.fortitude = 1;
		t_raceStat.agility = -1;
		t_raceStat.wisdom = 0;
		t_raceStat.perception = 0;
		break;

	case Character::e_Race::GNOME:
		t_raceStat.fortitude = 0;
		t_raceStat.strength = 0;
		t_raceStat.agility = 2;
		t_raceStat.wisdom = -1;
		t_raceStat.perception = 1;
		break;
	}
}

void Character::combineRaceStats(Stats& t_raceStat) {
	stats.strength += t_raceStat.strength;
	stats.fortitude += t_raceStat.fortitude;
	stats.agility += t_raceStat.agility;
	stats.wisdom += t_raceStat.wisdom;
	stats.perception += t_raceStat.perception;
}
