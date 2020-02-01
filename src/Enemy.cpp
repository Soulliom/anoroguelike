#include "../include/Enemy.h"

#include "../include/GameManager.h"
#include "../include/InputManager.h"
#include "../include/Player.h"
#include "../include/Map.h"

Enemy::Enemy() {
	//Randomize Enemy's Items
	randItems();
	//Set Enemy's Stats
	setStats();
	//Set Enemy Class
	whatsMyClass();
	//Set Enemy Name
	randName();
}

void Enemy::setPosition() {
	pos.x = rand() % (g_Map.border.width - 7) + 5;
	pos.y = rand() % (g_Map.border.height - 2) + 1;
	prevPos = pos;
}

bool Enemy::takeDamage(Items::Weapon t_wep) {
	int dmg = 0;

	switch (t_wep.enchant) {
	case Items::e_Enchant::NONE:
		dmg = t_wep.dmg / selectedArm.protection;
		break;

	case Items::e_Enchant::FLAME:
		dmg = t_wep.dmg / selectedArm.protection;
		dmg += (g_Player.level + 1) / 2;
		break;

	case Items::e_Enchant::PENETRATE:
		dmg = t_wep.dmg / (selectedArm.protection / 2);
		break;

	case Items::e_Enchant::VAMP:
		dmg = t_wep.dmg / selectedArm.protection;

		g_Player.health += rand() % 2 + 1;
		if (g_Player.health > g_Player.maxHealth) {
			g_Player.health = g_Player.maxHealth;
		}
		break;
	}

	health -= dmg + 1;
	if (g_Player.clas == Character::e_Class::MAGICIAN) {
		g_Player.stress -= 4;
	}
	else {
		g_Player.stress -= 2;
	}

	//Check if dead
	if (health <= 0) {
		if (g_Player.clas == Character::e_Class::MAGICIAN) {
			g_Player.stress -= 8;
		}
		else {
			g_Player.stress -= 4;
		}

		if (g_Player.stress < 0) {
			g_Player.stress = 0;
		}

		g_Player.exp += rand() % 4 + 1;

		g_Input.output(static_cast<std::string>("You managed to hit your target and ").append(name).append(" has fallen!"), 0);

		//LOOT
		int randItem = rand() % 10;
		if (randItem >= 5) { // Weapon 
			g_Player.aquireWep(g_Game.wepGenerator());
			g_Input.pause(static_cast<std::string>("You looted a Weapon from ").append(name).append("! Press [Space] to continue!"), 0, SPAC);
		}
		else if (randItem <= 2 || randItem >= 4) { // Consumables
			g_Player.aquireCon(g_Game.conGenerator());
			g_Input.pause(static_cast<std::string>("You looted a Consumable from ").append(name).append("! Press [Space] to continue!"), 0, SPAC);
		}
		else if (randItem == 0 || randItem == 1) { //Armor
			g_Player.aquireArm(g_Game.armGenerator());
			g_Input.pause(static_cast<std::string>("You looted an Armor from ").append(name).append("! Press [Space] to continue!"), 0, SPAC);
		}
		return true;
	}

	//Fix stress
	if (g_Player.stress < 0) {
		g_Player.stress = 0;
	}

	//Knockback
	if (pos.x >= g_Player.pos.x) {
		pos.x += t_wep.knockb;
	}
	else if (pos.x <= g_Player.pos.x) {
		pos.x -= t_wep.knockb;
	}

	g_Input.pause(static_cast<std::string>("You managed to hit your target and did: ").append(std::to_string(dmg + 1)).append(" damage!"), 0);
	return false;
}

void Enemy::enemyTurn() {
	switch (clas) {
		case e_Class::WARRIOR:
			warriorTurn();
			break;

		case e_Class::RANGER:
			rangerTurn();
			break;
		
		case e_Class::MAGICIAN:
			magicianTurn();
			break;
	}
}

/* PRIVATE */
// Randomizes selectWep && selectArm 
void Enemy::randItems() {
	selectedWep = g_Game.wepGenerator();
	selectedArm = g_Game.armGenerator();
}

//Randomize stats (e.g. fortitude) and applies them to actual stats (e.g. health), and race/class
void Enemy::setStats() {
	//Randomize if sub or add 1 to g_Player level
	level = abs(((rand() % 1) == 1) ? rand() % 1 + g_Player.level : rand() % 1 - g_Player.level);
	
	randRace();
	randStats(level - 6);
	configRaceStats(stats);
	
	//Health
	health = (stats.fortitude + 1) * 2;
	//Speed
	maxSpeed = (abs(stats.agility) + 2);
	speed = maxSpeed;
}

void Enemy::randRace() {
	int randChoice = rand() % 5;

	switch (randChoice) {
	case 0:
		race = e_Race::ELF;
		raceStr = "Elf";
		break;

	case 1:
		race = e_Race::ORC;
		raceStr = "Orc";
		break;

	case 2:
		race = e_Race::HUMAN;
		raceStr = "Human";
		break;

	case 3:
		race = e_Race::GOBLIN;
		raceStr = "Goblin";
		break;

	case 4:
		race = e_Race::DWARF;
		raceStr = "Dwarf";
		break;

	case 5:
		race = e_Race::GNOME;
		raceStr = "Gnome";
		break;
	}
}

void Enemy::whatsMyClass() {
	if (selectedWep.type == Items::e_Type::MELEE) {
		clas = e_Class::WARRIOR;
		clasStr = "Warrior";
	}

	else if (selectedWep.type == Items::e_Type::RANGED) {
		clas = e_Class::RANGER;
		clasStr = "Ranger";
	}

	else if (selectedWep.type == Items::e_Type::MAGIC) {
		clas = e_Class::MAGICIAN;
		clasStr = "Magician";
	}
}

void Enemy::randName() {
	std::array<std::string, 48> nameBank{
	"Naenelis", "Keavalur", "Qixidor", "Morzeiros", "Lular", "Morris", "Zylbella", "Inara", //Elf
	"Gorge", "Norroni", "Zachary", "Nikkolas", "Argreg", "Davy", "Elaine", "Celestine", //Human
	"Brukk", "Ratok", "Martal", "Bogvob", "Rhokk", "Zakk", "Enka", "Ranga", // Orc
	"Halfteeth", "Jugruk", "Dalk", "Krirk", "Redeye", "Cradrurk", "Jabrena", "Qundok", //Goblin
	"Gryren", "Hjolkum", "Balbrek", "Ermmus", "Vonron", "Bengran", "Arlen", "Gwinris", //Dwarf
	"Loxif", "Algrim", "Xoxif", "Zanmop", "Fargim", "Kelkur", "Eilipine", "Ariphina" //Gnome
	};

	name = nameBank.at(rand() % nameBank.size());
}

void Enemy::warriorTurn() { // Agressive Rush if wep distance
	prevPos = pos;

	//Attack
	if (((selectedWep.range + pos.x >= g_Player.pos.x) && (pos.x - selectedWep.range <= g_Player.pos.x)) // Attack
		&& ((selectedWep.range + pos.y >= g_Player.pos.y) && (pos.y - selectedWep.range <= g_Player.pos.y))){
		float hitChance = .0f;
		int randChance = rand() % 10 + 1;

		hitChance = g_Player.stats.strength + 1;

		if (hitChance > randChance) {
			g_Player.takeDamage(selectedWep);
		}
		else {
			g_Input.pause("An enemy tried to attack you and missed!", 0);
		}
	}

	//Move
	else {
		speed = maxSpeed;
		while (speed > 0) {
			// rand 50 / 50 move updown leftright
			int randMove = rand() % 2;

			if ((pos.x >= g_Player.pos.x) && (randMove == 0)) {
				pos.x--;
				speed--;
			}

			else if ((pos.x <= g_Player.pos.x) && (randMove == 0)) {
				pos.x++;
				speed--;
			}

			if ((pos.y >= g_Player.pos.y) && (randMove == 1)) {
				pos.y--;
				speed--;
			}

			else if ((pos.y <= g_Player.pos.y) && (randMove == 1)) {
				pos.y++;
				speed--;
			}

			if (((selectedWep.range + pos.x >= g_Player.pos.x) && (pos.x - selectedWep.range <= g_Player.pos.x)) // Attack
				&& ((selectedWep.range + pos.y >= g_Player.pos.y) && (pos.y - selectedWep.range <= g_Player.pos.y))) {
				//ATTACK
				float hitChance = .0f;
				int randChance = rand() % 10 + 1;

				hitChance = g_Player.stats.strength;

				if (hitChance > randChance) {
					g_Player.takeDamage(selectedWep);
				}
				else {
					g_Input.pause("An enemy tried to attack you and missed!", 0);
				}
				speed = 0;
			}

			g_Game.checkEnemyCollision(*this);
		}
	}
}

void Enemy::rangerTurn() { // wander, if in range shoot, if too close run
	//Run away
	if (((2 + pos.x >= g_Player.pos.x) && (pos.x - 2 <= g_Player.pos.x))
		&& ((2 + pos.y >= g_Player.pos.y) && (pos.y - 2 <= g_Player.pos.y))) {

		speed = maxSpeed;
		while (speed / 2 > 0) {
			// rand 50 / 50 move updown leftright
			int randMove = rand() % 2;

			if ((pos.x >= g_Player.pos.x) && (randMove == 0)) {
				pos.x++;
				speed--;
			}

			else if ((pos.x <= g_Player.pos.x) && (randMove == 0)) {
				pos.x--;
				speed--;
			}

			if ((pos.y >= g_Player.pos.y) && (randMove == 1)) {
				pos.y++;
				speed--;
			}

			else if ((pos.y <= g_Player.pos.y) && (randMove == 1)) {
				pos.y--;
				speed--;
			}

			g_Game.checkEnemyCollision(*this);
		}
	}

	//Attack
	else if (((selectedWep.range + pos.x >= g_Player.pos.x) && (pos.x - selectedWep.range <= g_Player.pos.x)) // Attack
		&& ((selectedWep.range + pos.y >= g_Player.pos.y) && (pos.y - selectedWep.range <= g_Player.pos.y))) {
		float hitChance = .0f;
		int randChance = rand() % 10 + 1;

		hitChance = g_Player.stats.perception;

		if (hitChance > randChance) {
			g_Player.takeDamage(selectedWep);
		}
		else {
			g_Input.pause("An enemy tried to attack you and missed!", 0);
		}
	}

	else{ // Wander
		for (speed = maxSpeed; speed > 0; speed--){
			switch (rand() % 4) {
			case 0:
				pos.x++;
				break;

			case 1:
				pos.x--;
				break;

			case 2:
				pos.y++;
				break;

			case 3:
				pos.y--;
				break;
			}
			g_Game.checkEnemyCollision(*this);
		}
	}  
}

void Enemy::magicianTurn() { // Wander and Attack 
	//Attack
	if (((selectedWep.range + pos.x >= g_Player.pos.x) && (pos.x - selectedWep.range <= g_Player.pos.x)) // Attack
	&& ((selectedWep.range + pos.y >= g_Player.pos.y) && (pos.y - selectedWep.range <= g_Player.pos.y))) {
		float hitChance = .0f;
		int randChance = rand() % 10 + 1;

		hitChance = g_Player.stats.wisdom;

		if (hitChance > randChance) {
			g_Player.takeDamage(selectedWep);
		}
		else {
			g_Input.pause("An enemy tried to attack you and missed!", 0);
		}
	}

	else { // Wander
		for (speed = maxSpeed; speed > 0; speed--) {
			switch (rand() % 4) {
			case 0:
				pos.x++;
				break;

			case 1:
				pos.x--;
				break;

			case 2:
				pos.y++;
				break;

			case 3:
				pos.y--;
				break;
			}
			g_Game.checkEnemyCollision(*this);
		}
	}
}