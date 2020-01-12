#include "../include/Player.h"
#include "../include/DEFINITIONS.h"

Player::Player() {
	//Selected Weapon
	selectedWep[0] = g_Item.v_Weapons[12];
	selectedWep[1] = g_Item.v_Weapons[12];

	//Selected Armor
	selectedArm = g_Item.v_Armors[3];
}

void Player::aquireWep(Items::Weapon t_wep) {
	if (t_wep.type == Items::e_Type::MELEE && (clas != e_Class::WARRIOR && clas != e_Class::BANDIT)) {
		t_wep.dmg /= 2;
	}
	if (t_wep.type == Items::e_Type::RANGED && (clas != e_Class::RANGER && clas != e_Class::BANDIT)) {
		t_wep.dmg /= 2;
	}
	if (t_wep.type == Items::e_Type::MAGIC && clas != e_Class::MAGICIAN) {
		t_wep.dmg /= 2;
	}

	v_Wep.push_back(t_wep);
}

void Player::aquireArm(Items::Armor t_arm) {
	v_Arm.push_back(t_arm);
}

void Player::aquireCon(Items::Consumable t_con) {
	v_Con.push_back(t_con);
}

void Player::levelUp() {
	//Give option to upgrade stat
	//Dont allow if stat > 10

	//Health
	maxHealth = stats.fortitude * 2;
	health = maxHealth;
	//Mana
	maxMana = stats.wisdom * 3;
	mana = maxMana;
	//Weight
	maxWeight = stats.strength * 20;
	//Stress
	maxStress = stats.perception * 10;
	maxStress += 10;
	//Speed
	maxSpeed = stats.agility;
	speed = maxSpeed / (maxWeight / weight); // <-- make function
	//Exp
	level++;
	maxExp *= 2;
	exp = 0;
	// Hit Chances;
	meleeHit *= stats.strength;
	rangedHit *= stats.perception;
	specialHit *= stats.wisdom;
}

void Player::applyRacePassive() {
	//Apply race passive
	switch (race) {
	case e_Race::ELF:	// Elf | Extra Mana / carry less				 
		maxMana = round(maxMana * 1.2f);
		mana = maxMana;
		maxWeight = round(maxWeight * 0.8f);
		break;

	case e_Race::ORC:	// Orc | NONE
		break;	

	case e_Race::HUMAN:	// Human | NONE				 
		break;

	case e_Race::GOBLIN: // Less Mana
		maxMana = round(maxMana * 0.8f);
		mana = maxMana;
		break;

	case e_Race::DWARF: // Dwarf | Weight doesn't affect speed / move slower
		maxWeight = 0;
		break;

	case e_Race::GNOME: // Gnome | Moves faster / carry less
		maxSpeed = round(maxSpeed * 1.2f);
		maxWeight = round(maxWeight * 0.8f);
		break;
	}
}

void Player::applyCurrentWeight() {
	if (race == e_Race::DWARF) {
		weight = 0;
	}
	else {
		weight = 0;
		for (auto w : v_Wep) {
			weight += w.weight;
		}
		for (auto a : v_Arm) {
			weight += a.weight;
		}
		for (auto c : v_Con) {
			weight += c.weight;
		}
	}

	if (weight > maxWeight) {
		speed = maxSpeed / 2;
	}
	else {
		speed = maxSpeed;
	}
}

void Player::selectWep(Items::Weapon &t_wep) {
	if (t_wep.b_equipped == false) {
		if (t_wep.hands == 2) {
			selectedWep[0] = t_wep;
			selectedWep[1] = g_Item.v_Weapons[12]; // Replace weapon with empty

			for (auto& w : v_Wep) {
				w.b_equipped = false;
			}
			t_wep.b_equipped = true;
		}

		else if (t_wep.hands == 1) {
			//Prompt which hand (1st or second) 
			std::cout << "\nWhich hand would you like to equip this weapon to? [1] OR [2]\n";

			bool b_contin = false;
			while (!b_contin) {
				int keyPress = _getch();
				
				if (keyPress == 49) { //49 = 1 ASCII
					selectedWep[0] = t_wep;

					if (selectedWep[0].hands == 2) {
						selectedWep[0] = g_Item.v_Weapons.at(12);
					}

					for (auto& w : v_Wep) {
						if (!(w == selectedWep[1])) {
							w.b_equipped = false;
						}
					}

					t_wep.b_equipped = true;
					b_contin = true;
				}
				else if (keyPress == 50) { // 59 = 2 ASCII
					selectedWep[1] = t_wep;

					if (selectedWep[0].hands == 2) {
						selectedWep[0] = g_Item.v_Weapons.at(12);
					}

					for (auto& w : v_Wep) {
						if (!(w == selectedWep[0])) {
							w.b_equipped = false;
						}
					}

					t_wep.b_equipped = true;
					b_contin = true;
				}
			}
		}

		g_Input.pause("You've equipped a weapon! Press [Space] to continue", 0, SPAC);
	}
	else {
		g_Input.pause("You've already equipped this weapon! Press [Space] to continue", 0, SPAC);
	}
}

void Player::selectArm(Items::Armor t_arm) {
	selectedArm = t_arm;
	g_Input.pause("You've equipped an armor! Press [Space] to continue", 0, SPAC);
}

void Player::useConsume(Items::Consumable t_con, int t_state) {
	g_Input.pause("You used a potion! Press [Space] to continue", 0, SPAC);
	health += t_con.amou;
	if (health > maxHealth) {
		health = maxHealth;
	}
	v_Con.erase(v_Con.begin() + t_state);
}