#include "../include/Player.h"

#include "../include/InputManager.h"
#include "../include/Map.h"

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
	
	if (race == Character::e_Race::ORC && t_wep.type == Items::e_Type::MELEE) {
		t_wep.dmg *= 1.2f;
	}

	if (race == Character::e_Race::ELF && t_wep.type == Items::e_Type::MAGIC) {
		t_wep.dmg *= 1.2f;
	}

	v_Wep.push_back(t_wep);
}

void Player::aquireArm(Items::Armor t_arm) {
	if (race == Character::e_Race::GNOME) {
		t_arm.protection *= 1.2f;
	}
	v_Arm.push_back(t_arm);
}

void Player::aquireCon(Items::Consumable t_con) {
	v_Con.push_back(t_con);
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
			selectedWep[0].uses = 0;
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
					selectedWep[0].uses = 0;
					b_contin = true;
				}
				else if (keyPress == 50) { // 50 = 2 ASCII
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
					selectedWep[1].uses = 0;
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
		health = static_cast<float>(maxHealth);
	}
	v_Con.erase(v_Con.begin() + t_state);
}

void Player::levelUp() {
	if (level < MAXLEVEL && exp >= maxExp) {
		if (level >= 1) {
			g_Input.levelUp(g_Player.stats);
		}

		//Health
		maxHealth = stats.fortitude * 3;
		health = static_cast<float>(maxHealth);

		//Weight
		if (race == e_Race::DWARF) { //Dwarf
			weight = 0;
		}
		else { //Other
			maxWeight = stats.strength * 5;
		}
		if (race == e_Race::ELF || race == e_Race::GNOME) { //Gnome/Elf
			maxWeight = static_cast<int>(maxWeight * 0.8f);
		}

		//Stress
		maxStress = stats.perception * 10;
		maxStress += 10;
		//Speed
		maxSpeed = (stats.agility) * 2;
		speed = maxSpeed;
		//Exp
		level++;
		maxExp = 4 * level;
		exp = 0;
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
		maxSpeed = stats.agility;
		speed = maxSpeed;
	}
	else {
		maxSpeed = stats.agility * 2;
		speed = maxSpeed;
	}
}

void Player::setPosition() {
	pos.x = 0;
	pos.y = rand() % (g_Map.border.height - 2) + 1;
	prevPos = pos;
}

bool Player::takeDamage(Items::Weapon t_wep) {
	int dmg = 0;
	 
	if (selectedArm.protection != 0) {
		switch (t_wep.enchant) {
		case Items::e_Enchant::NONE:
			dmg = t_wep.dmg / selectedArm.protection;

			break;

		case Items::e_Enchant::FLAME:
			dmg = t_wep.dmg / selectedArm.protection;
			dmg += (g_Player.level + 1) / 3;
			break;

		case Items::e_Enchant::PENETRATE:
			dmg = t_wep.dmg / (selectedArm.protection / 2);
			break;

		case Items::e_Enchant::VAMP:
			dmg = t_wep.dmg / selectedArm.protection;
			break;
		}

		health -= ++dmg * block;
	}

	else {
		switch (t_wep.enchant) {
		case Items::e_Enchant::FLAME:
			dmg = t_wep.dmg - 1;
			dmg += (g_Player.level + 1) / 3;
			break;

		default:
			dmg = t_wep.dmg;
			break;
		}

		health -= --dmg * block;
	}

	g_Player.stress += 4;

	//Knockback
	if (pos.x >= g_Player.pos.x) {
		g_Player.pos.x -= t_wep.knockb;
	}
	else if (pos.x <= g_Player.pos.x) {
		g_Player.pos.x += t_wep.knockb;
	}

	g_Input.pause(static_cast<std::string>("You were hit for: ").append(std::to_string(dmg)).append(" damage!"), 0);

	//Check if dead
	if (health <= 0) {
		g_Input.pause("You have fallen. In your final moments, you watch as your killers loot you and disappear into the darkness.", 0);
		return true;
	}

	return false;
}
