#include "../include/Enemy.h"

Enemy::Enemy(std::string name) {
	//Randomize Enemy's Items
	randItems();
	//Randomize Enemy's Stats
	randStats();
	//Set Enemy Class
	whatsMyClass();
	//Set Enemy Name

	//Set Enemy Position
}

// Randomizes selectWep && selectArm 
void Enemy::randItems() {
	selectedWep = g_Game.wepGenerator();
	selectedArm = g_Game.armGenerator();
}

//Randomize stats (e.g. fortitude) and applies them to actual stats (e.g. health), and race/class
void Enemy::setStats() {
	randRace();
	randStats(g_Player.level);
	configRaceStats(&stats);

	//Health
	maxHealth = stats.fortitude * 2;
	health = maxHealth;
	//Speed
	speed = stats.agility;
	// Hit Chances;
	meleeHit *= stats.strength;
	rangedHit *= stats.perception;
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
	}

	else if (selectedWep.type == Items::e_Type::RANGED) {
		clas = e_Class::RANGER;
	}

	else if (selectedWep.type == Items::e_Type::MAGIC) {
		clas = e_Class::MAGICIAN;
	}
}

void Enemy::randName() {
	std::array<std::string, 48> nameBank{
	"Naenelis", "Keavalur", "Qixidor", "Morzeiros", "Lular", "Morris", "Zylbella", "Inara", //Elf
	"Gorge", "Dominick", "Zachary", "Nikkolas", "Argreg", "Davy", "Elaine", "Celestine", //Human
	"Brukk", "Ratok", "Martal", "Bogvob", "Rhokk", "Zakk", "Enka", "Ranga", // Orc
	"Halfteeth", "Jugruk", "Dalk", "Krirk", "Redeye", "Cradrurk", "Jabrena", "Qundok", //Goblin
	"Gryren", "Hjolkum", "Balbrek", "Ermmus", "Vonron", "Bengran", "Arlen", "Gwinris", //Dwarf
	"Loxif", "Algrim", "Xoxif", "Zanmop", "Fargim", "Kelkur", "Eilipine", "Ariphina" //Gnome
	};

	name = nameBank.at(rand() % nameBank.size);
}