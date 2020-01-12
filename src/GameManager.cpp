#include "../include/GameManager.h"

/*randomly generate an item
void GameManager::itemGenerator(Player& t_Player) {
	int itemChoice = rand() % 10;
	
	if (itemChoice >= 7) { // Weapons
		t_Player.v_Wep  wepGenerator();
	}

	else if (itemChoice == 6 || itemChoice == 5) { // Consumables
		con = conGenerator();
	}

	else if (itemChoice == 4) { // Armors
		arm = armGenerator();
	}

	return this;
}*/

//ramdomly generates any weapon
Items::Weapon GameManager::wepGenerator() {
	//Generate random weapon 
	Items::Weapon randWep = g_Item.v_Weapons.at(rand() % g_Item.v_Weapons.size() - 1);
	
	//Randomize Weapon damage
	float multiAdd = ((g_Player.level / 2) * randWep.dmgMulti);
	int randAdd = rand() % static_cast<int>(multiAdd) + (g_Player.level / 2);

	randWep.dmg += randAdd; // 4 6

	//Randomize Weapon Enchantment
	int randEnchant = rand() % 10;

	if (randEnchant >= 9) {
		randWep.enchant = Items::e_Enchant::FLAME;
	}
	if (randEnchant == 7 || randEnchant == 8) {
		randWep.enchant = Items::e_Enchant::VAMP;
	}
	if (randEnchant == 5 || randEnchant == 6) {
		randWep.enchant = Items::e_Enchant::PENETRATE;
	}
	else {
		randWep.enchant = Items::e_Enchant::NONE;
	}

	return randWep;
}

//ramdomly generates any armor
Items::Armor GameManager::armGenerator() {
	int ran = rand() % 10;

	if (ran >= 6) {
		return g_Item.v_Armors.at(0);
	}

	else if (ran <= 5 && ran >= 5) {
		return g_Item.v_Armors.at(1);
	}

	else if (ran == 1) {
		return g_Item.v_Armors.at(2);
	}
}

//ramdomly generates any consumable
Items::Consumable GameManager::conGenerator() {
	int ran = rand() % 10;

	if (ran >= 5) {
		return g_Item.v_Consumes.at(0);
	}

	else if (ran >= 2 && ran <= 4) {
		return g_Item.v_Consumes.at(1);
	}

	else if (ran == 1) {
		return g_Item.v_Consumes.at(2);
	}
}