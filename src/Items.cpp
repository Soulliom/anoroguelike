#include "../include/Items.h"

Items::Items() {
	/* WEAPONS */
	//Player will have 2 slots, 2 hands per slot, can switch slots at beginning or end of turn.
	/* Melee */
	createWeapon("Rapier", 2, 1, 6, 0, 2, 1.4, e_Type::MELEE, 100);
	createWeapon("Claymore", 5, 2, 10, 3, 5, 1.3, e_Type::MELEE, 125);
	createWeapon("Dagger", .5, 1, 3, 0, 3, 1.2, e_Type::MELEE, 80);
	createWeapon("Small Shield", 4, 1, 2, 2, 1, 1.2, e_Type::MELEE, 60);
	createWeapon("Large Shield", 8, 2, 3, 3, 3, 1.4, e_Type::MELEE, 100);

	/* Ranged */
	createWeapon("Recurve Bow", 4, 2, 40, 1, 3, 1.4, e_Type::RANGED, 150);
	createWeapon("Longbow", 2, 2, 50, 0, 2, 1.4, e_Type::RANGED, 100);
	createWeapon("Crossbow", 8, 2, 20, 3, 5, 1.2, e_Type::RANGED, 175);

	/* Magic */
	createWeapon("Sapphire Staff", 4, 2, 25, 0, 4, 1.5, e_Type::MAGIC, 125);
	createWeapon("Ruby Staff", 6, 1, 50, 0, 2, 1.4, e_Type::MAGIC, 90);
	createWeapon("Book of Chaos", 3, 2, 15, 0, 5, 1.4, e_Type::MAGIC, 150);
	createWeapon("Book of Creation", 2, 1, 30, 0, 3, 1.3, e_Type::MAGIC, 100);

	/* Empty Weapon */
	createWeapon("Empty", 0, 0, 0, 0, 0, 0, e_Type::MELEE, 0);

	/* ARMORS */
	createArmor("Light Armor", 10, .20f, 100);
	createArmor("Medium Armor", 20, .40f, 150);
	createArmor("Heavy Armor", 50, .60f, 200);

	/* Empty Armor*/
	createArmor("No Armor", 0, 0, 0);

	/* CONSUMABLES*/
	createConsume("Lesser Health Pot", 1, 0.25, 75);
	createConsume("Health Pot", 3, 0.50, 100);
	createConsume("Large Health Pot", 8, 1.00, 150);
}

void Items::createWeapon(std::string t_name, float t_weight, std::uint8_t t_hands, std::uint8_t t_range, std::uint8_t t_knockb, std::uint8_t t_dmg, float t_dmgMulti, e_Type t_type, std::uint8_t t_cost) {
	static int i;

	Weapon w;
	v_Weapons.push_back(w);
	v_Weapons.at(i).name = t_name;
	v_Weapons.at(i).weight = t_weight;
	v_Weapons.at(i).hands = t_hands;
	v_Weapons.at(i).range = t_range;
	v_Weapons.at(i).knockb = t_knockb;
	v_Weapons.at(i).dmg = t_dmg;
	v_Weapons.at(i).dmgMulti = t_dmgMulti;
	v_Weapons.at(i).type = t_type;
	v_Weapons.at(i).cost = t_cost;
	v_Weapons.at(i).enchant = e_Enchant::NONE;
	i++; 
}

void Items::createArmor(std::string t_name, float t_weight, float t_prot, std::uint8_t t_cost) {
	static unsigned int i;

	Armor r;
	v_Armors.push_back(r);
	v_Armors.at(i).name = t_name;
	v_Armors.at(i).weight = t_weight;
	v_Armors.at(i).protection = t_prot;
	v_Armors.at(i).cost = t_cost;

	i++;
}
void Items::createConsume(std::string t_name, float t_weight, float t_amou, std::uint8_t t_cost) {
	static unsigned int i;

	Consumable c;
	v_Consumes.push_back(c);
	v_Consumes.at(i).name = t_name;
	v_Consumes.at(i).weight = t_weight;
	v_Consumes.at(i).amou = t_amou;
	v_Consumes.at(i).cost = t_cost;
	i++;
}
