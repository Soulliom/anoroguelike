#ifndef ITEMS_H
#define ITEMS_H

#include "DEFINITIONS.h"

class Items {
private:
	/* Conditions */
	enum class e_type {
		melee,
		ranged,
		magic
	};

	enum class e_enchant {
		none,
		flame,
		penetrate,
		vamp
	};

	/* Weapons */
	void createWeapon(std::string name, float weight, std::uint8_t hands, std::uint8_t range, std::uint8_t knockb, std::uint8_t dmg, e_type type, std::uint8_t cost);

	/* Armor */
	void createArmor(std::string name, float weight, float proc, std::uint8_t cost);

	/* Consumables */
	void createConsume(std::string name, float weight, float amou, std::uint8_t cost);

	// Lesser/Medium/Large

public:
	Items();

	struct Weapon {
		std::string name = "";
		int range = 0; //based in feet
		float weight = 0; //based in pounds
		int hands = 0; //Upto 2 hands
		int knockb = 0;
		int dmg = 0;
		int enchant = 0;
		e_type type;
		std::uint8_t cost = 0;
		bool b_equipped = false;

		bool operator==(const Weapon& w) {
			if ((this->name == w.name) && (this->dmg == w.dmg) && (this->enchant == w.enchant) && (this->type == w.type)) {
				return true;
			}
			else{
				return false;
			}
		}
	};
	std::vector<Weapon> weapons;

	struct Armor {
		std::string name = "";
		float protection = 0; //How much less damage is taken
		float weight = 0;
		std::uint8_t cost = 0;

		bool operator==(const Armor& a) {
			if ((this->name == a.name) && (this->protection == a.protection)) {
				return true;
			}
			else {
				return false;
			}
		}
	};
	std::vector<Armor> armors;

	struct Consumable {
		std::string name = "";
		float amou = 0;
		float weight = 0;
		std::uint8_t cost = 0;
	};
	std::vector<Consumable> consumes;
};
extern Items g_Item;
#endif