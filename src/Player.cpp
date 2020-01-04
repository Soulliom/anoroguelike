#include "../include/Player.h"
#include "../include/DEFINITIONS.h"

Player::Player() {
	//Selected Weapon
	selectedWep[0] = item.weapons[12];
	selectedWep[1] = item.weapons[12];

	//Selected Armor
	selectedArm = item.armors[3];
}

void Player::aquireWep(Items::Weapon wep) {
	this->wep.push_back(wep);
}

void Player::aquireArm(Items::Armor arm) {
	this->arm.push_back(arm);
}

void Player::aquireCon(Items::Consumable con) {
	this->con.push_back(con);
}

void Player::applyStats() {
	//Health
	this->maxHealth = this->ch.stats.fortitude * 2;
	this->health = this->maxHealth;
	//Mana
	this->maxMana = this->ch.stats.wisdom * 3;
	this->mana = this->maxMana;
	//Weight
	this->maxWeight = this->ch.stats.strength * 20;
	//Stress
	this->maxStress = this->ch.stats.perception * 10;
	this->maxStress += 10;
	//Speed
	this->maxSpeed = this->ch.stats.agility;
	this->speed = this->maxSpeed / (this->maxWeight / this->weight); // <-- make function
	//Exp
	this->level++;
	this->maxExp *= 2;
	this->exp = 0;
}

void Player::applyRacePassive() {
	//Apply race passive
	switch (this->ch.race) {
	case 0:	// Elf | Extra Mana / carry less				 
		this->maxMana *= 1.2f;
		this->mana = this->maxMana;
		this->maxWeight *= 0.8f;
		break;
	case 1:	// Orc 
		break;				 
	case 2:	// Human | NONE				 
		break;
	case 3: // Less Mana
		this->maxMana *= 0.8f;
		this->mana = this->maxMana;
		break;
	case 4: // Dwarf | Weight doesn't affect speed / move slower
		this->maxWeight = 0;
		break;
	case 5: // Gnome | Moves faster / carry less
		this->maxSpeed *= 1.2f;
		this->maxWeight *= 0.8f;
		break;
	}
}

void Player::applyCurrentWeight() {
	this->weight = 0;
	for (auto w : this->wep) {
		this->weight += w.weight;
	}
	for (auto a : this->arm) {
		this->weight += a.weight;
	}
	for (auto c : this->con) {
		this->weight += c.weight;
	}
}

void Player::selectWep(Items::Weapon &wep) {
	if (wep.equipped == false) {
		if (wep.hands == 2) {
			this->selectedWep[0] = wep;
			this->selectedWep[1] = item.weapons[12]; // Replace weapon with empty

			for (auto& w : this->wep) {
				w.equipped = false;
			}
			wep.equipped = true;
		}

		else if (wep.hands == 1) {
			//Prompt which hand (1st or second) 
			std::cout << "\nWhich hand would you like to equip this weapon to? [1] OR [2]\n";

			bool contin = false;
			while (!contin) {
				int keyPress = _getch();
				
				if (keyPress == 49) { //49 = 1 ASCII
					this->selectedWep[0] = wep;

					if (selectedWep[0].hands == 2) {
						selectedWep[0] = item.weapons.at(12);
					}

					for (auto& w : this->wep) {
						if (!(w == selectedWep[1])) {
							w.equipped = false;
						}
					}

					wep.equipped = true;
					contin = true;
				}
				else if (keyPress == 50) { // 59 = 2 ASCII
					this->selectedWep[1] = wep;

					if (selectedWep[0].hands == 2) {
						selectedWep[0] = item.weapons.at(12);
					}

					for (auto& w : this->wep) {
						if (!(w == selectedWep[0])) {
							w.equipped = false;
						}
					}

					wep.equipped = true;
					contin = true;
				}
			}
		}

		input.Pause("You've equipped a weapon! Press [Space] to continue", 0, SPAC);
	}
	else {
		input.Pause("You've already equipped this weapon! Press [Space] to continue", 0, SPAC);
	}
}

void Player::selectArm(Items::Armor arm) {
	this->selectedArm = arm;
	input.Pause("You've equipped an armor! Press [Space] to continue", 0, SPAC);
}

void Player::useConsume(Items::Consumable con, int state) {
	input.Pause("You used a potion! Press [Space] to continue", 0, SPAC);
	this->health += con.amou;
	if (this->health > this->maxHealth) {
		this->health == this->maxHealth;
	}
	this->con.erase(this->con.begin() + state);
}