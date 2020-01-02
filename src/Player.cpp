#include "../include/Player.h"
#include "../include/DEFINITIONS.h"

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
	this->maxMana = this->ch.stats.wisdom * 2;
	this->mana = this->maxMana;
	//Weight
	this->maxWeight = this->ch.stats.strength * 10;
	//setWeight();
	//Stress
	this->maxStress = this->ch.stats.perception * 10;
	//Speed
	this->maxSpeed = this->ch.stats.agility;
	this->speed = this->maxSpeed / (this->maxWeight / this->weight);
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
		break;		 //NONE
	case 1:	// Orc | Extra melee dmg / Less health
		this->maxHealth /= 1.5f;
		this->ch.stats.strength += 1;
		applyStats();
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