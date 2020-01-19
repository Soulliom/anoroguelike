#include "../include/Enemy.h"

#include "../include/GameManager.h"
#include "../include/Player.h"
#include "../include/Map.h"

Enemy::Enemy() {
	//Randomize Enemy's Items
	randItems();
	//Randomize Enemy's Stats
	randStats();
	//Set Enemy's Stats
	setStats();
	//Set Enemy Class
	whatsMyClass();
	//Set Enemy Name
	randName();
	//Set Enemy Position
}

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
	randStats(level);
	configRaceStats(stats);
	setPosition();
	
	//Health
	health = (stats.fortitude + 1) * 3;
	//Speed
	maxSpeed = (abs(stats.agility) + 1) * 1.5f;
	speed = maxSpeed;
	// Hit Chances;
	meleeHit = stats.strength * .8f;
	rangedHit = stats.perception * .8f;
	magicHit = stats.wisdom * .8f;

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

void Enemy::setPosition() {
	pos.x = rand() % (g_Map.border.width - 7) + 5;
	pos.y = rand() % (g_Map.border.height - 2) + 1;	
	prevPos = pos;
}