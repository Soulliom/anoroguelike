#include "../include/Character.h"

Character::Character() {
	
}

void Character::randStats() {
	//Skip
	bool skip = false;
	//Maximum number of points
	int max = 16;
	//Points given to a stat
	unsigned int min = rand() % (max / 2) + 1;
	//Randomized stat order
	unsigned int chs = 0;
	//Each past stat
	unsigned int rmb[5];

	int total = 0;

	while (max > 2) {
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
				min = (rand() % max / 2) + 1;
				max -= min;

				//Choose random stat
				switch (chs) {
				case 0:
					this->stats.strength += min;
					break;
				case 1:
					this->stats.fortitude += min;
					break;
				case 2:
					this->stats.agility += min;
					break;
				case 3:
					this->stats.wisdom += min;
					break;
				case 4:
					this->stats.perception += min;
					break;
				}
			}
				skip = false;
		}

		for (int i = 0; i < 4; i++) {
			rmb[i] = 0;
		}
	}
}

void Character::resetStats() {
	this->stats.strength = 0;
	this->stats.fortitude = 0;
	this->stats.agility = 0;
	this->stats.wisdom = 0;
	this->stats.perception = 0;
}

void Character::configRaceStats(Stats *raceStat) {
	switch(this->race){
		case Character::Elf:
			raceStat->strength = -1;
			raceStat->fortitude = 0;
			raceStat->agility = 0;
			raceStat->wisdom = 2;
			raceStat->perception = 1;
			break;

		case Character::Orc:
			raceStat->strength = 2;
			raceStat->fortitude = 1;
			raceStat->agility = 0;
			raceStat->wisdom = 0;
			raceStat->perception = -1;
			break;

		case Character::Human:
			raceStat->strength = 0;
			raceStat->fortitude = 1;
			raceStat->agility = 0;
			raceStat->wisdom = 1;
			raceStat->perception = 1;
			break;

		case Character::Goblin:
			raceStat->strength = 1;
			raceStat->fortitude = 0;
			raceStat->agility = 1;
			raceStat->wisdom = 0;
			raceStat->perception = 1;
			break;

		case Character::Dwarf:
			raceStat->strength = 1;
			raceStat->fortitude = 2;
			raceStat->agility = -1;
			raceStat->wisdom = 0;
			raceStat->perception = 0;
			break;

		case Character::Gnome:
			raceStat->fortitude = 0;
			raceStat->strength = 0;
			raceStat->agility = 2;
			raceStat->wisdom = -1;
			raceStat->perception = 1;
			break;
	}
}

void Character::combineRaceStats(Stats* raceStat) {
	this->stats.strength += raceStat->strength;
	this->stats.fortitude += raceStat->fortitude;
	this->stats.agility += raceStat->agility;
	this->stats.wisdom += raceStat->wisdom;
	this->stats.perception += raceStat->perception;
}