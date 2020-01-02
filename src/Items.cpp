#include "../include/Items.h"

Items::Items() {
	/* WEAPONS */
	//Player will have 2 slots, 2 hands per slot, can switch slots at beginning or end of turn.
	/* Melee */
	createWeapon("Rapier", 2, 1, 6, 0, 2, typeEnum::melee, 100);
	createWeapon("Claymore", 5, 2, 10, 3, 5, typeEnum::melee, 125);
	createWeapon("Dagger", .5, 1, 3, 0, 3, typeEnum::melee,80);
	createWeapon("Small Shield", 4, 1, 2, 2, 1, typeEnum::melee, 60);
	createWeapon("Large Shield", 8, 2, 3, 3, 3, typeEnum::melee, 100);

	/* Ranged */
	createWeapon("Recurve Bow", 4, 2, 40, 1, 3, typeEnum::ranged,150);
	createWeapon("Longbow", 2, 2, 50, 0, 2, typeEnum::ranged,100);
	createWeapon("Crossbow", 8, 2, 20, 3, 5, typeEnum::ranged, 175);

	/* Magic */
	createWeapon("Sapphire Staff", 4, 2, 30, 0, 4, typeEnum::magic, 125);
	createWeapon("Ruby Staff", 6, 1, 50, 0, 2, typeEnum::magic, 90);
	createWeapon("Book of Chaos", 3, 2, 15, 0, 5, typeEnum::magic, 150);
	createWeapon("Book of Creation", 2, 1, 40, 0, 3, typeEnum::magic, 100);

	/* ARMORS */
	createArmor("Light Armor", 10, .10f, 100);
	createArmor("Medium Armor", 25, .20f, 150);
	createArmor("Heavy Armor", 50, .40f, 200);

	/* CONSUMABLES*/
	createConsume("Lesser Health Pot", 1, 0.25, 75);
	createConsume("Health Pot", 3, 0.50, 100);
	createConsume("Large Health Pot", 8, 1.00, 150);
}

void Items::createWeapon(std::string name, float weight, std::uint8_t hands, std::uint8_t range, std::uint8_t knockb, std::uint8_t dmg, typeEnum type, std::uint8_t cost) {
	static int i;

	Weapon w;
	weapons.push_back(w);
	weapons.at(i).name = name;
	weapons.at(i).weight = weight;
	weapons.at(i).hands = hands;
	weapons.at(i).range = range;
	weapons.at(i).knockb = knockb;
	weapons.at(i).dmg = dmg;
	weapons.at(i).type = type;
	weapons.at(i).cost = cost;
	i++; 
}

void Items::createArmor(std::string name, float weight, float prot, std::uint8_t cost) {
	static unsigned int i;

	Armor r;
	armors.push_back(r);
	armors.at(i).name = name;
	armors.at(i).weight = weight;
	armors.at(i).protection = prot;
	armors.at(i).cost = cost;

	i++;
}
void Items::createConsume(std::string name, float weight, float amou, std::uint8_t cost) {
	static unsigned int i;

	Consumable c;
	consumes.push_back(c);
	consumes.at(i).name = name;
	consumes.at(i).weight = weight;
	consumes.at(i).amou = amou;
	consumes.at(i).cost = cost;
	i++;
}

//Choose random weapon from weaponMap, randomize stats, and return
//Items::randWeapon()