#include "../include/Items.h"

Items::Items() {
	/* WEAPONS */
	//Player will have 2 slots, 2 hands per slot, can switch slots at beginning or end of turn.
	/* Melee */
	createWeapon("Rapier", 2, 1, 2, 0, 2, 1.3f, e_Type::MELEE, 100);
	createWeapon("Claymore", 6, 2, 3, 1, 4, 1.2f, e_Type::MELEE, 125);
	createWeapon("Dagger", 1, 1, 1, 0, 3, 1.4f, e_Type::MELEE, 80);
	createWeapon("Small Shield", 4, 1, 1, 2, 1, 1.2f, e_Type::MELEE, 60);
	createWeapon("Large Shield", 8, 2, 2, 3, 3, 1.3f, e_Type::MELEE, 100);

	/* Ranged */
	createWeapon("Recurve Bow", 4, 2, 4, 0, 3, 1.3f, e_Type::RANGED, 150);
	createWeapon("Longbow", 2, 2, 5, 0, 2, 1.4f, e_Type::RANGED, 100);
	createWeapon("Crossbow", 8, 2, 2, 1, 5, 1.2f, e_Type::RANGED, 175);

	/* Magic */
	createWeapon("Sapphire Staff", 4, 2, 4, 0, 4, 1.2f, e_Type::MAGIC, 125);
	createWeapon("Ruby Staff", 6, 1, 5, 0, 3, 1.4f, e_Type::MAGIC, 90);
	createWeapon("Book of Chaos", 3, 2, 3, 0, 5, 1.2f, e_Type::MAGIC, 150);
	createWeapon("Book of Creation", 2, 1, 6, 0, 1, 1.4f, e_Type::MAGIC, 100);

	/* Empty Weapon */
	createWeapon("Empty", 0, 0, 0, 0, 0, 0, e_Type::MELEE, 0);

	/* ARMORS */
	createArmor("Light Armor", 10, 1.10f, 100);
	createArmor("Medium Armor", 20, 1.20f, 150);
	createArmor("Heavy Armor", 40, 1.40f, 200);

	/* Empty Armor*/
	createArmor("No Armor", 0, 0, 0);

	/* CONSUMABLES*/
	createConsume("Lesser Health Pot", 1, 1.25, 75);
	createConsume("Health Pot", 3, 1.50, 100);
	createConsume("Large Health Pot", 8, 2.00, 150);
}

void Items::createWeapon(std::string t_name, float t_weight, std::uint8_t t_hands, std::uint8_t t_range, std::uint8_t t_knockb, std::uint8_t t_dmg, float t_dmgMulti, e_Type t_type, std::uint8_t t_cost) {
	static int i;

	Weapon w;
	w.name = t_name;
	w.weight = t_weight;
	w.hands = t_hands;
	w.range = t_range;
	w.knockb = t_knockb;
	w.dmg = t_dmg;
	w.dmgMulti = t_dmgMulti;
	w.type = t_type;
	w.cost = t_cost;
	w.enchant = e_Enchant::NONE;
	v_Weapons.push_back(w);
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
