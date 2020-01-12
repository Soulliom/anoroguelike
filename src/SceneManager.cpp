#include "../include/SceneManager.h"

/* TEMPLATE SCENE
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
*/

SceneManager::SceneManager() {
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void SceneManager::isSelected(std::string t_text, int t_selectColor, int t_defaultColor, std::int8_t t_state, std::int8_t t_selectState) {
	if (t_state == t_selectState) {
		SetConsoleTextAttribute(textConsole, t_selectColor);
		std::cout << t_text;
		SetConsoleTextAttribute(textConsole, t_defaultColor);
	}

	else {
		SetConsoleTextAttribute(textConsole, t_defaultColor);
		std::cout << t_text;
	}
}

void SceneManager::titleScene() {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n ";
	std::cout << "\n                                   anoroguelikeCMD (Another Rogue-Like Command Prompt)";
	std::cout << "\n                                              Created by Soulliom (George)";
	std::cout << "\n "; 
	std::cout << "\n                 NOTE: This CMD version is a prototype, Hopefully to be recreated and improved with SFML";
	std::cout << "\n ";
	std::cout << "\n ";  SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n                                                         Intro:";
	std::cout << "\n         Many races live upon Earth, the current light of day is similar to the ones during the Medieval Times.";
	std::cout << "\n ";
	std::cout << "\n                         Rumors of great treasure lies beneath the sacred tombs of the elders.";
	std::cout << "\n                         Many seek this ancient treasure, but those who find it, never return.";
	std::cout << "\n ";
	std::cout << "\n                          You are one of many adventurers attempting to raid the sacred tombs.";
	std::cout << "\n  You have lived in poverty the entirety of your life. But have been preparing for this raid for the past few years.";
	std::cout << "\n                After many years, this is your final desperate attempt to situate your financial status."; 
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                            But do you have what it takes?";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::settingsScene(std::int8_t t_state, std::string t_diff, long t_seed) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                   Settings and Tutorials";
	std::cout << "\n                                        Hint: Navigate Menus with [WASD] and [Space]!";
	std::cout << "\n                                    Symbol Meaning: -Select-, <Scroll>, +Show+, *Continue*.";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  < Difficulty >: ", 14, 13, 0, t_state); std::cout << t_diff;
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Seed: ", 14, 13, 1, t_state); std::cout << t_seed;
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Tutorial on Races, Classes, and Stats -  ", 14, 13, 2, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";	isSelected("  - Tutorial on Combat, Weapons, and Actions -  ", 14, 13, 3, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Continue to Character Customization * ", 14, 13, 4, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::seedScene(std::int8_t t_state, long long t_seed) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                     Seed Setting";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n   + Current Seed: "; std::cout << t_seed;
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Randomize Seed - ", 14, 13, 0, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Input Custom Seed - ", 14, 13, 1, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back * ", 14, 13, 2, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::charTut1Scene() {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                Character Tutorial 1 / 2";
	std::cout << "\n ";
	std::cout << "\n   + All Characters are made up of a race, a class, and stats";
	std::cout << "\n   + Stats: "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n       + Strength:   Melee Hit Chance, Carry Weight.";
	std::cout << "\n       + Fortitude:  Health, Better Block";
	std::cout << "\n       + Agility:    Speed, Dodge Chance";
	std::cout << "\n       + Wisdom:     Skills Hit Chance, Mana";
	std::cout << "\n       + Perception: Ranged Hit Chance, Stress Cap";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n   + Classes: "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n       + Warrior:  |Equipment| -Swords, Shields.";
	std::cout << "\n                   |Ability| +In the beginning of combat, Roll Strength, Gain extra run speed for x turns.";
	std::cout << "\n       + Ranger:   |Equpment|  -Bows, Crossbows.";
	std::cout << "\n                   |Ability| +In the beginning of combat, Roll Perception, Gain extra x turns.";
	std::cout << "\n       + Magician: |Equipment| -Staffs, Books.";
	std::cout << "\n                   |Ability| +In the beginning of combat, Roll Wisdom, choose temp buff: Weapon range, Damage.";
	std::cout << "\n       + Bandit:   |Equipment| -Daggers, Throwables.";
	std::cout << "\n                   |Ability| +In the beginning of combat, Roll Agility, Hidden for x turns.";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::charTut2Scene() {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                Character Tutorial 2 / 2";
	std::cout << "\n ";
	std::cout << "\n   + Finally, all characters have a race. Depending on the race, they might have: ";
	std::cout << "\n   ^ Stat buffs / debuffs, Positive / Negative Passives";
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n   + Races:"; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n       + Elf:    |Stats| +2 Wisdom, +1 Perception, -1 Strength";
	std::cout << "\n                 |Passive| (+)Extra Mana, (-)Carry Less";
	std::cout << "\n       + Orc:    |Stats| +2 Strength, +1 Fortitude, -2 Perception"; 
	std::cout << "\n                 |Passive| (NONE)";
	std::cout << "\n       + Human:  |Stats| +1 Perception, +1 Wisdom, +1 Fortitude";
	std::cout << "\n                 |Passive| (NONE)";
	std::cout << "\n       + Goblin: |Stats| +1 Perception, +1 Strength, +1 Agility";
	std::cout << "\n                 |Passive| (-)Less Mana"; 
	std::cout << "\n       + Dwarf:  |Stats| +2 Fortitude, +1 Strength, -1 Agility";
	std::cout << "\n                 |Passive| (+)Weight doesn't affect speed, (-)Move slower"; 
	std::cout << "\n       + Gnome:  |Stats| +2 Agility, +1 Perception, -1 Wisdom";
	std::cout << "\n                 |Passive| (+)Move faster, (-)Carry less";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::combatTut1Scene() {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::combatTut2Scene() {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::characterScene(std::int8_t t_state, std::string t_race, std::string t_clas, Character::Stats t_stats, Character::Stats t_raceStats) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                Character Customization";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  < Race >: ", 14, 13, 0, t_state); std::cout << t_race;
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n "; isSelected("  < Class >: ", 14, 13, 1, t_state); std::cout << t_clas;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Randomize Stats - ", 14, 13, 2, t_state); SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   + Stats:"; 
	std::cout << "\n        + Strength:   "; std::cout << t_stats.strength << " + " << t_raceStats.strength;
	std::cout << "\n        + Fortitude:  "; std::cout << t_stats.fortitude << " + " << t_raceStats.fortitude;
	std::cout << "\n        + Agility:    "; std::cout << t_stats.agility << " + " << t_raceStats.agility;
	std::cout << "\n        + Wisdom:     "; std::cout << t_stats.wisdom << " + " << t_raceStats.wisdom;
	std::cout << "\n        + Perception: "; std::cout << t_stats.perception << " + " << t_raceStats.perception;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Continue to Shop *", 14, 13, 3, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::shopScene(std::int8_t t_state, int t_gold) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Pregame Shop";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   + Current Gold: " << t_gold;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Weapons Shop -", 14, 13, 0, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Armor Shop -", 14, 13, 1, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Consumables Shop -", 14, 13, 2, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Inventory -", 14, 13, 3, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Start Game *", 14, 13, 4, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::weaponsScene(std::int8_t t_state) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Weapons Shop";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Melee Weapons -", 14, 13, 0, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Ranged Weapons -", 14, 13, 1, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Magic Weapons -", 14, 13, 2, t_state);
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 3, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::meleeScene(std::int8_t t_state, std::vector<Items::Weapon> t_weapons) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Melee Section Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(0).name + " - " + std::to_string(t_weapons.at(0).cost), 14, 13, 0, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(1).name + " - " + std::to_string(t_weapons.at(1).cost), 14, 13, 1, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(2).name + " - " + std::to_string(t_weapons.at(2).cost), 14, 13, 2, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(3).name + " - " + std::to_string(t_weapons.at(3).cost), 14, 13, 3, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(4).name + " - " + std::to_string(t_weapons.at(4).cost), 14, 13, 4, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 5, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::rangedScene(std::int8_t t_state, std::vector<Items::Weapon> t_weapons) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13); 
	std::cout << "\n                                                  Ranged Section Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(5).name + " - " + std::to_string(t_weapons.at(5).cost), 14, 13, 0, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(6).name + " - " + std::to_string(t_weapons.at(6).cost), 14, 13, 1, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(7).name + " - " + std::to_string(t_weapons.at(7).cost), 14, 13, 2, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 3, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::magicScene(std::int8_t t_state, std::vector<Items::Weapon> t_weapons) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Magic Section Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(8).name + " : " + std::to_string(t_weapons.at(8).cost), 14, 13, 0, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(9).name + " : " + std::to_string(t_weapons.at(9).cost), 14, 13, 1, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(10).name + " : " + std::to_string(t_weapons.at(10).cost), 14, 13, 2, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_weapons.at(11).name + " : " +  std::to_string(t_weapons.at(11).cost), 14, 13, 3, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 4, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::armorsScene(std::int8_t t_state, std::vector<Items::Armor> t_armors) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                       Armors Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_armors.at(0).name + " - " + std::to_string(t_armors.at(0).cost), 14, 13, 0, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_armors.at(1).name + " - " + std::to_string(t_armors.at(1).cost), 14, 13, 1, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_armors.at(2).name + " - " + std::to_string(t_armors.at(2).cost), 14, 13, 2, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 3, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::consumeScene(std::int8_t t_state, std::vector<Items::Consumable> t_consume) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                   Consumables Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_consume.at(0).name + " - " + std::to_string(t_consume.at(0).cost), 14, 13, 0, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_consume.at(1).name + " - " + std::to_string(t_consume.at(1).cost), 14, 13, 1, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - " + t_consume.at(2).name + " - " + std::to_string(t_consume.at(2).cost), 14, 13, 2, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 3, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::viewWeapon(Items::Weapon t_weapon) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Weapon Inspection";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   + Weapon Name: " << t_weapon.name;
	std::cout << "\n ";
	std::cout << "\n   + Weapon Damage Type: " << typeOutput(t_weapon.type);
	std::cout << "\n ";
	std::cout << "\n   + Weapon Damage: " << t_weapon.dmg;
	std::cout << "\n ";
	std::cout << "\n   + Weapon Range: " << t_weapon.range << " feet";
	std::cout << "\n ";
	std::cout << "\n   + Weapon Knockback: " << t_weapon.knockb << " feet";
	std::cout << "\n ";
	std::cout << "\n   + Hands to use Weapon: " << t_weapon.hands;
	std::cout << "\n ";
	std::cout << "\n   + Weapon Weight: " << t_weapon.weight << " pounds";
	std::cout << "\n ";
	std::cout << "\n   + Weapon Enchantment: " << enchantOutput(t_weapon.enchant);
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::viewArmor(Items::Armor t_armor) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Armor Inspection";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   + Armor Name: " << t_armor.name;
	std::cout << "\n ";
	std::cout << "\n   + Armor Protection: " << t_armor.protection * 100 << " %";
	std::cout << "\n ";
	std::cout << "\n   + Armor Weight: " << t_armor.weight << " pounds";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::viewConsume(Items::Consumable t_consume) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Consumable Inspection";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   + Consumable Name: " << t_consume.name;
	std::cout << "\n ";
	std::cout << "\n   + Consumable Healing: " << t_consume.amou * 100 << " %";
	std::cout << "\n ";
	std::cout << "\n   + Consumable Weight: " << t_consume.weight << " pounds";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::viewInventory(std::int8_t t_state) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                     Your Inventory";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Weapons Inventory -", 14, 13, 0, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Armor Inventory -", 14, 13, 1, t_state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Consumables Inventory -", 14, 13, 2, t_state);
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 3, t_state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}


void SceneManager::viewWepInv(std::int8_t t_stateY, std::int8_t t_stateX) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Weapon Inventory";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" < Weapon Inventory >: ", 14, 13, 0, t_stateY); std::cout << t_stateX + 1 << " / " << g_Player.v_Wep.size();
 	std::cout << "\n "; 
	std::cout << "\n ";  
	std::cout << "\n "; isSelected(" - Inspect Weapon : ", 14, 13, 1, t_stateY); std::cout << g_Player.v_Wep.at(t_stateX).name;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" - Equip Weapon - ", 14, 13, 2, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" - Delete Weapon - ", 14, 13, 3, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 4, t_stateY);
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::viewArmInv(std::int8_t t_stateY, std::int8_t t_stateX) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                      Armor Inventory";
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" < Armor Inventory >: ", 14, 13, 0, t_stateY); std::cout << t_stateX + 1 << " / " << g_Player.v_Arm.size();
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" - Inspect Armor : ", 14, 13, 1, t_stateY); std::cout << g_Player.v_Arm.at(t_stateX).name;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" - Wear Armor - ", 14, 13, 2, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" - Delete Armor - ", 14, 13, 3, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 4, t_stateY);
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::viewConInv(std::int8_t t_stateY, std::int8_t t_stateX) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Consumable Inventory";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" < Consumable Inventory >: ", 14, 13, 0, t_stateY); std::cout << t_stateX + 1 << " / " << g_Player.v_Con.size();
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" - Inspect Consumable : ", 14, 13, 1, t_stateY); std::cout << g_Player.v_Con.at(t_stateX).name;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" - Use Consumable - ", 14, 13, 2, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected(" - Delete Consumable - ", 14, 13, 3, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *", 14, 13, 4, t_stateY);
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::wanderScene(std::int8_t t_stateX) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";  SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ( Wandering Mode )                                    Player Stats                                  ( Wandering Mode )"; 
	std::cout << "\n                                  + Strength: " << g_Player.stats.strength;
	std::cout << "\n                                                                       + Wisdom: " << g_Player.stats.wisdom;
	std::cout << "\n                                  + Fortitiude: " << g_Player.stats.fortitude;
	std::cout << "\n                                                                       + Perception: " << g_Player.stats.perception;
	std::cout << "\n                                  + Agility: " << g_Player.stats.agility; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n             *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";  SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n                                                      Player Details";
	std::cout << "\n                                  + Health: " << g_Player.health << " / " << g_Player.maxHealth;  
	std::cout << "\n                                                                       + Mana: " << g_Player.mana << " / " << g_Player.maxMana;
	std::cout << "\n                                  + Level: " << g_Player.level;
	std::cout << "\n                                                                       + Weight: " << g_Player.weight << " / " << g_Player.maxWeight;
	std::cout << "\n                                  + Exp: " << g_Player.exp << " / " << g_Player.maxExp;
	std::cout << "\n                                                                       + Stress: " << g_Player.stress << " / " << g_Player.maxStress; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n             *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n                                                         Options";  SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n ";
	std::cout << "\n "; isSelected("                          *~~~~~~~~~*               ", 14, 13, 0, t_stateX); isSelected(" *~~~~~~~~~~~*               ", 14, 13, 1, t_stateX); isSelected(" *~~~~~~~* ", 14, 13, 2, t_stateX);
	std::cout << "\n "; isSelected("                          - Actions -               ", 14, 13, 0, t_stateX); isSelected(" - Inventory -               ", 14, 13, 1, t_stateX); isSelected(" - Other - ", 14, 13, 2, t_stateX);
	std::cout << "\n "; isSelected("                          *~~~~~~~~~*               ", 14, 13, 0, t_stateX); isSelected(" *~~~~~~~~~~~*               ", 14, 13, 1, t_stateX); isSelected(" *~~~~~~~* ", 14, 13, 2, t_stateX);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::wanderActionScene(std::int8_t t_stateY) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                      Wandering Actions";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Loot Nearby -  ", 14, 13, 0, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Onwards -  ", 14, 13, 1, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Back *  ", 14, 13, 2, t_stateY);
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::otherScene(std::int8_t t_stateY) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                          Other";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Tutorial on Races, Classes, and Stats -  ", 14, 13, 0, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  - Tutorial on Combat, Weapons, and Actions -  ", 14, 13, 1, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Exit Game * ", 14, 13, 2, t_stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; isSelected("  * Continue Game * ", 14, 13, 3, t_stateY);
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

/* Extra Scenes*/
std::string SceneManager::typeOutput(Items::e_Type t_type) {
	switch (t_type) {
	case Items::e_Type::NONE:
		return "None";
		break;

	case Items::e_Type::MELEE:
		return "Melee";
		break;

	case Items::e_Type::RANGED:
		return "Ranged";
		break;

	case Items::e_Type::MAGIC:
		return "Magical";
		break;
	}
	return "ERROR";
}

std::string SceneManager::enchantOutput(Items::e_Enchant t_enchant) {
	switch (t_enchant) {
	case Items::e_Enchant::NONE:
		return "None";
		break;

	case Items::e_Enchant::FLAME:
		return "Flame";
		break;

	case Items::e_Enchant::PENETRATE:
		return "Penetration";
		break;

	case Items::e_Enchant::VAMP:
		return "Vampire";
		break;
	}
	return "ERROR";
}