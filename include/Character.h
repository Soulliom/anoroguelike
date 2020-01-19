#ifndef CHARACTER_H 
#define CHARACTER_H

#include "DEFINITIONS.h"

class Character {
public:
	/* Variables/Stats */
	//Stats
	struct Stats {
		int strength = 0;   // Strength:   Melee Hit Chance, Carry Weight.
		int fortitude = 0;  // Fortitude:  Health, Better Block
		int agility = 0;    // Agility:    Speed, Dodge Chance
		int wisdom = 0;     // Wisdom:     Special Hit Chance, Mana
		int perception = 0; // Perception: Ranged Hit Chance, Stress Cap
	};

	struct Position {
		int x = 0;
		int y = 0;

		bool operator==(Position t_pos) {
			if (this->x == t_pos.x && this->y == t_pos.y) {
				return true;
			}
			else {
				return false;
			}
		}

		void operator=(Position t_pos) {
			this->x = t_pos.x;
			this->y = t_pos.y;
		}
	};

	//Race
	enum class e_Race {
		ELF,    // +2 Wis, +1 Per, -1 Str  |Passive| Extra Mana / carry less
		ORC,    // +2 Str, +1 Fort, -2 Per |Passive| NONE
		HUMAN,  // +1 Per, +1 Wis, +1 Fort |Passive| NONE
		GOBLIN, // +1 Per, +1 Str, +1 Agl  |Passive| Less Mana
		DWARF,  // +2 Fort, +1 Str, -1 Agl |Passive| Weight doesn't affect speed / move slower
		GNOME   // +2 Agl, +1 Per, -1 Wis  |Passive| Moves faster / carry less
	};

	//Class
	enum class e_Class {
		WARRIOR,  // |Weapon| Swords , shield      |Armor| Heavy  |Abilty| Roll Str, Extra run speed for x turns
		RANGER,   // |Weapon| bows, guns           |Armor| Medium |Abilty| Roll Perception, Extra x turns
		MAGICIAN, // |Weapon|  staffs, books       |Armor| Robe   |Abilty| Roll Wisdom, choose: temp extra weapon range, temp extra damage
		BANDIT    // |Weapon| daggers, throwables  |Armor| Light  |Abilty| Roll Dex, hidden for x turns
	};

	//Stats
	Stats stats;

	//Position
	Position pos;
	Position prevPos;

	//Character's Race
	e_Race race = e_Race::ELF;
	//Character's Class
	e_Class clas = e_Class::WARRIOR;
	//Display race string
	std::string raceStr = "Elf";
	//Display class string
	std::string clasStr = "Warrior";

	/* Functions */
	//Randomize Stats
	void randStats(int t_extra = 0);
	//Clear Stats
	void resetStats();
	//Config Race Stats with Object stats
	void configRaceStats(Stats& t_raceStat);
	//Combine Race Stats with Object stats
	void combineRaceStats(Stats& t_raceStat);
	//Position set
	virtual void setPosition() = 0;
};

#endif  
