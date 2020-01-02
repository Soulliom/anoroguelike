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

void SceneManager::IsSelected(std::string text, int selectColor, int defaultColor, std::int8_t state, std::int8_t selectState) {
	if (state == selectState) {
		SetConsoleTextAttribute(textConsole, selectColor);
		std::cout << text;
		SetConsoleTextAttribute(textConsole, defaultColor);
	}

	else {
		SetConsoleTextAttribute(textConsole, defaultColor);
		std::cout << text;
	}
}

void SceneManager::TitleScene() {
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
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::SettingsScene(std::int8_t state, std::string diff, long seed) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                   Settings and Tutorials";
	std::cout << "\n                                        Hint: Navigate Menus with [WASD] and [Space]!";
	std::cout << "\n                                    Symbol Meaning: -Select-, <Scroll>, +Show+, *Continue*.";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  < Difficulty >: ", 14, 13, 0, state); std::cout << diff;
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Seed: ", 14, 13, 1, state); std::cout << seed;
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n "; IsSelected("  - Tutorial on Races, Classes, and Stats -  ", 14, 13, 2, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";	IsSelected("  - Tutorial on Combat, Weapons, and Actions -  ", 14, 13, 3, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Continue to Character Customization * ", 14, 13, 4, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::SeedScene(std::int8_t state, long long seed) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                     Seed Setting";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n   + Current Seed: "; std::cout << seed;
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Randomize Seed - ", 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Input Custom Seed - ", 14, 13, 1, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back * ", 14, 13, 2, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::CharTut1Scene() {
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
	std::cout << "\n       + Wisdom:     Special Hit Chance, Mana";
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

void SceneManager::CharTut2Scene() {
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

void SceneManager::CombatTut1Scene() {
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

void SceneManager::CombatTut2Scene() {
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

void SceneManager::CharacterScene(std::int8_t state, std::string race, std::string clas, Character::Stats stats, Character::Stats raceStats) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                Character Customization";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  < Race >: ", 14, 13, 0, state); std::cout << race;
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n "; IsSelected("  < Class >: ", 14, 13, 1, state); std::cout << clas;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Randomize Stats - ", 14, 13, 2, state); SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   + Stats:"; 
	std::cout << "\n        + Strength:   "; std::cout << stats.strength + raceStats.strength;
	std::cout << "\n        + Fortitude:  "; std::cout << stats.fortitude + raceStats.fortitude;
	std::cout << "\n        + Agility:    "; std::cout << stats.agility + raceStats.agility;
	std::cout << "\n        + Wisdom:     "; std::cout << stats.wisdom + raceStats.wisdom;
	std::cout << "\n        + Perception: "; std::cout << stats.perception + raceStats.perception;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Continue to Shop *", 14, 13, 3, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::ShopScene(std::int8_t state, int gold) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Pregame Shop";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   + Current Gold: " << gold;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Buy Weapons -", 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Buy Armor -", 14, 13, 1, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Buy Consumables -", 14, 13, 2, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Current Inventory -", 14, 13, 3, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Start Game *", 14, 13, 4, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::WeaponsScene(std::int8_t state) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Weapons Shop";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Melee Weapons -", 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Ranged Weapons -", 14, 13, 1, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Magic Weapons -", 14, 13, 2, state);
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 3, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::MeleeScene(std::int8_t state, std::vector<Items::Weapon> weapons) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Melee Section Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(0).name + " - " + std::to_string(weapons.at(0).cost), 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(1).name + " - " + std::to_string(weapons.at(1).cost), 14, 13, 1, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(2).name + " - " + std::to_string(weapons.at(2).cost), 14, 13, 2, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(3).name + " - " + std::to_string(weapons.at(3).cost), 14, 13, 3, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(4).name + " - " + std::to_string(weapons.at(4).cost), 14, 13, 4, state);
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 5, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::RangedScene(std::int8_t state, std::vector<Items::Weapon> weapons) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13); 
	std::cout << "\n                                                  Ranged Section Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(5).name + " - " + std::to_string(weapons.at(5).cost), 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(6).name + " - " + std::to_string(weapons.at(6).cost), 14, 13, 1, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(7).name + " - " + std::to_string(weapons.at(7).cost), 14, 13, 2, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 3, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::MagicScene(std::int8_t state, std::vector<Items::Weapon> weapons) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Magic Section Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(8).name + " : " + std::to_string(weapons.at(8).cost), 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(9).name + " : " + std::to_string(weapons.at(9).cost), 14, 13, 1, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(10).name + " : " + std::to_string(weapons.at(10).cost), 14, 13, 2, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + weapons.at(11).name + " : " +  std::to_string(weapons.at(11).cost), 14, 13, 3, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 4, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::ArmorsScene(std::int8_t state, std::vector<Items::Armor> armors) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                       Armors Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + armors.at(0).name + " - " + std::to_string(armors.at(0).cost), 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + armors.at(1).name + " - " + std::to_string(armors.at(1).cost), 14, 13, 1, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + armors.at(2).name + " - " + std::to_string(armors.at(2).cost), 14, 13, 2, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 3, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::ConsumeScene(std::int8_t state, std::vector<Items::Consumable> consume) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                   Consumables Shop";
	std::cout << "\n                              Press [Space] to see more information! Press [Enter] to Buy!";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + consume.at(0).name + " - " + std::to_string(consume.at(0).cost), 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + consume.at(1).name + " - " + std::to_string(consume.at(1).cost), 14, 13, 1, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - " + consume.at(2).name + " - " + std::to_string(consume.at(2).cost), 14, 13, 2, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 3, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::ViewWeapon(Items::Weapon weapon) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Weapon Inspection";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   - Weapon Name: " << weapon.name;
	std::cout << "\n ";
	std::cout << "\n   - Weapon Damage Type: " << static_cast<int>(weapon.type);
	std::cout << "\n ";
	std::cout << "\n   - Weapon Damage: " << weapon.dmg;
	std::cout << "\n ";
	std::cout << "\n   - Weapon Range: " << weapon.range << " feet";
	std::cout << "\n ";
	std::cout << "\n   - Weapon Knockback: " << weapon.knockb << " feet";
	std::cout << "\n ";
	std::cout << "\n   - Hands to use Weapon: " << weapon.hands;
	std::cout << "\n ";
	std::cout << "\n   - Weapon Weight: " << weapon.weight << " pounds";
	std::cout << "\n ";
	std::cout << "\n   - Weapon Enchantment: " << weapon.enchant;
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::ViewArmor(Items::Armor armor) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Armor Inspection";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   - Armor Name: " << armor.name;
	std::cout << "\n ";
	std::cout << "\n   - Armor Protection: " << armor.protection * 100 << " %";
	std::cout << "\n ";
	std::cout << "\n   - Armor Weight: " << armor.weight << " pounds";
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

void SceneManager::ViewConsume(Items::Consumable consume) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Consumable Inspection";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n   - Consumable Name: " << consume.name;
	std::cout << "\n ";
	std::cout << "\n   - Consumable Healing: " << consume.amou * 100 << " %";
	std::cout << "\n ";
	std::cout << "\n   - Consumable Weight: " << consume.weight << " pounds";
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

void SceneManager::ViewInventory(std::int8_t state) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Player Inventory";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - View Weapons -", 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - View Armor -", 14, 13, 1, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - View Consumables -", 14, 13, 2, state);
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 3, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}


void SceneManager::ViewWepInv(std::int8_t stateY, std::int8_t stateX) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Weapon Inventory";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected(" < Weapon Inventory >: ", 14, 13, 0, stateY); std::cout << stateX + 1 << " / " << player.wep.size();
 	std::cout << "\n "; 
	std::cout << "\n ";  
	std::cout << "\n "; IsSelected(" - Inspect Weapon : ", 14, 13, 1, stateY); std::cout << player.wep.at(stateX).name;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected(" - Delete Weapon - ", 14, 13, 2, stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 3, stateY);
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::ViewArmInv(std::int8_t stateY, std::int8_t stateX) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Weapon Inventory";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected(" < Armor Inventory >: ", 14, 13, 0, stateY); std::cout << stateX + 1 << " / " << player.arm.size();
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected(" - Inspect Armor : ", 14, 13, 1, stateY); std::cout << player.arm.at(stateX).name;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected(" - Delete Armor - ", 14, 13, 2, stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 3, stateY);
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}

void SceneManager::ViewConInv(std::int8_t stateY, std::int8_t stateX) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                    Weapon Inventory";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected(" < Consumable Inventory >: ", 14, 13, 0, stateY); std::cout << stateX + 1 << " / " << player.con.size();
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected(" - Inspect Consumable : ", 14, 13, 1, stateY); std::cout << player.con.at(stateX).name;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected(" - Delete Consumable - ", 14, 13, 2, stateY);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  * Back *", 14, 13, 3, stateY);
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*";
	std::cout << "\n ";
	Sleep(SLP);
}