#ifndef CHARACTER_H 
#define CHARACTER_H

#include "DEFINITIONS.h"

class Character {
public:
	/* Variables/Stats */
	struct Stats {
		int strength = 0;   // Strength:   Melee Hit Chance, Carry Weight.
		int fortitude = 0;  // Fortitude:  Health, Better Block
		int agility = 0;    // Agility:    Speed, Dodge Chance
		int wisdom = 0;     // Wisdom:     Special Hit Chance, Stress Cap
		int perception = 0; // Perception: Ranged Hit Chance, Mana
	}stats;

	const enum RaceEnum {
		Elf,    // +2 Wis, +1 Per, -1 Str  |Passive| Extra Mana / carry less
		Orc,    // +2 Str, +1 Fort, -2 Per |Passive| NONE
		Human,  // +1 Per, +1 Wis, +1 Fort |Passive| NONE
		Goblin, // +1 Per, +1 Str, +1 Agl  |Passive| Less Mana
		Dwarf,  // +2 Fort, +1 Str, -1 Agl |Passive| Weight doesn't affect speed / move slower
		Gnome   // +2 Agl, +1 Per, -1 Wis  |Passive| Moves faster / carry less
	};

	const enum ClassEnum {
		Warrior,  // |Weapon| Swords , shield      |Armor| Heavy  |Abilty| Roll Str, Extra run speed for x turns
		Ranger,   // |Weapon| bows, guns           |Armor| Medium |Abilty| Roll Perception, Extra x turns
		Magician, // |Weapon|  staffs, books       |Armor| Robe   |Abilty| Roll Wisdom, choose: temp extra weapon range, temp extra damage
		Bandit    // |Weapon| daggers, throwables  |Armor| Light  |Abilty| Roll Dex, hidden for x turns
	};

	int race = RaceEnum(Elf);
	int clas = ClassEnum(Warrior);
	//Display race string
	std::string raceStr = "Elf";
	//Display class string
	std::string clasStr = "Warrior";

	/* Functions */
	Character();
	//Randomize Stats
	void randStats();
	//Clear Stats
	void resetStats();
	//Config Race Stats with Object stats
	void configRaceStats(Stats* raceStat);
	//Combine Race Stats with Object stats
	void combineRaceStats(Stats* raceStat);
};

#endif  
