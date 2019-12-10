#ifndef CHARACTER_H 
#define CHARACTER_H

#include "DEFINITIONS.h"

struct Stats {
	int strength = 0;   // Strength:   Melee Hit Chance, Carry Weight.
	int fortitude = 0;  // Fortitude:  Health, Better Block
	int agility = 0;    // Agility:    Speed, Stamina, Melee Dodge Chance
	int wisdom = 0;     // Wisdom:     Special Hit Chance, Stress Cap, Stress Relief
	int perception = 0; // Perception: Ranged Hit Chance, Ranged Dodge Chance
};

class Character {
public:
	Character();

	int race = NULL;//RaceEnum(Elf);
	int clas = NULL;//ClassEnum(Ranger);
	std::string raceStr = "None Chosen";//Elf
	std::string clasStr = "None Chosen";//Ranger

	/* Variables/Stats */
	enum RaceEnum {
		Elf,    // +2 Wis, +1 Per, -1 Str     |Passive| Extra stamina / carry less
		Orc,    // +2 Str, +1 Fort, -1 Per    |Passive| Extra melee dmg / less defense
		Human,  // +1 Per, +1 Wis, +1 Agl     |Passive| Less stress cap
		Goblin, // +1 Per, +1 Str             |Passive| Affected less by stress
		Dwarf,  // +2 Fort, +1 Str, -1 Agl    |Passive| Weight doesn't affect speed / move slower
		Gnome   // +2 Agl, +1 Per, -1 Wis     |Passive| Moves faster / carry less
	};

	enum ClassEnum {
		Warrior,  // |Weapon| Swords , shield      |Armor| Heavy  |Abilty| Roll Str, Extra run speed for x turns
		Ranger,   // |Weapon| bows, guns           |Armor| Medium |Abilty| Roll Perception, Extra x turns
		Magician, // |Weapon| wands, staffs, books |Armor| Robe   |Abilty| Roll Wisdom, choose: temp extra weapon range, temp extra damage
		Bandit    // |Weapon| daggers, throwables  |Armor| Light  |Abilty| Roll Dex, hidden for x turns
	};
};

//Character object
extern Character demoChar;

#endif  
