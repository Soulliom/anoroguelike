#ifndef ITEMS_H
#define ITEMS_H

#include "DEFINITIONS.h"

class Items {
public:
	Items();

	/* Conditions */
	const enum class e_Type {
		NONE,
		MELEE,
		RANGED,
		MAGIC
	};

	const enum class e_Enchant {
		NONE,
		FLAME,
		PENETRATE,
		VAMP
	};

	/* ITEMS */
	/* Weapons */
	struct Weapon {
		std::string name = "";
		int range = 0; //based in feet
		float weight = 0; //based in pounds
		int hands = 0; //Upto 2 hands
		int knockb = 0;
		int dmg = 0;
		float dmgMulti = 0;
		e_Enchant enchant = e_Enchant::NONE;
		e_Type type = e_Type::NONE;
		std::uint8_t cost = 0;
		bool b_equipped = false;
		int uses = 1;

		inline bool operator==(const Weapon& t_wep) {
			if ((name == t_wep.name) && (dmg == t_wep.dmg) && (enchant == t_wep.enchant) && (type == t_wep.type)) {
				return true;
			}
			else{
				return false;
			}
		}
	};
	std::vector<Weapon> v_Weapons;

	/* Armors */
	struct Armor {
		std::string name = "";
		float protection = 0; //How much less damage is taken
		float weight = 0;
		std::uint8_t cost = 0;

		inline bool operator==(const Armor& t_arm) {
			if ((name == t_arm.name) && (protection == t_arm.protection)) {
				return true;
			}
			else {
				return false;
			}
		}
	};
	std::vector<Armor> v_Armors;

	/* Consumables */
	struct Consumable {
		std::string name = "";
		float amou = 0;
		float weight = 0;
		std::uint8_t cost = 0;
	};
	std::vector<Consumable> v_Consumes;

private:
	/* Weapons */
	void createWeapon(std::string t_name, float t_weight, std::uint8_t t_hands, std::uint8_t t_range, std::uint8_t t_knockb, std::uint8_t t_dmg, float t_dmgMulti ,e_Type t_type, std::uint8_t t_cost);

	/* Armor */
	void createArmor(std::string t_name, float t_weight, float t_proc, std::uint8_t cost);

	/* Consumables */
	void createConsume(std::string t_name, float t_weight, float t_amou, std::uint8_t cost);
};
extern Items g_Item;
#endif