#include "../include/SceneManager.h"
#include "../include/Character.h"

/* TEMPLATE SCENE
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
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
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
*/

SceneManager::SceneManager() {
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void SceneManager::IsSelected(std::string text, int selectColor, int defaultColor, int state, int selectState) {
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
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
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
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
}

void SceneManager::SettingsScene(unsigned int state, std::string diff, long seed) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                   Settings and Tutorials";
	std::cout << "\n                                     Hint: Navigate Menus with [WASD] and [Space]!";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Difficulty: ", 14, 13, 0, state); std::cout << diff;
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Seed: ", 14, 13, 1, state); std::cout << seed;
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n "; IsSelected("  * Tutorial on Races, Classes, and Stats *  ", 14, 13, 2, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";	IsSelected("  * Tutorial on Combat, Weapons, and Actions *  ", 14, 13, 3, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Continue - ", 14, 13, 4, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
}

void SceneManager::DiffScene(unsigned int state, std::string diff) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                  Difficulty Setting";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n     Current Difficulty: "; std::cout << diff;
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n "; IsSelected("  - Easy - ", 14, 13, 0, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Normal - ", 14, 13, 1, state);
	std::cout << "\n "; 
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Hard - ", 14, 13, 2, state);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Continue - ", 14, 13, 3, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
}

void SceneManager::SeedScene(unsigned int state, long long seed) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                     Seed Setting";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n     Current Seed: "; std::cout << seed;
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
	std::cout << "\n "; IsSelected("  - Continue - ", 14, 13, 2, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
}

void SceneManager::CharTut1Scene() {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                Character Tutorial 1 / 2";
	std::cout << "\n ";
	std::cout << "\n     - All Characters are made up of a race, a class, and stats";
	std::cout << "\n     - Stats: "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n          + Strength:   Melee Hit Chance, Carry Weight.";
	std::cout << "\n          + Fortitude:  Health, Better Block";
	std::cout << "\n          + Agility:    Speed, Stamina, Melee Dodge Chance";
	std::cout << "\n          + Wisdom:     Special Hit Chance, Stress Cap, Stress Relief";
	std::cout << "\n          + Perception: Ranged Hit Chance, Ranged Dodge Chance";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n     - Classes: "; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n          + Warrior:  |Equipment| -Swords, Shields. Heavy Armor.";
	std::cout << "\n                      |Ability| +In the beginning of combat, Roll Strength, Gain extra run speed for x turns.";
	std::cout << "\n          + Ranger:   |Equpment|  -Bows, Crossbows. Medium Armor.";
	std::cout << "\n                      |Ability| +In the beginning of combat, Roll Perception, Gain extra x turns.";
	std::cout << "\n          + Magician: |Equipment| -Wands, Staffs, Books. Robe.";
	std::cout << "\n                      |Ability| +In the beginning of combat, Roll Wisdom, choose temp buff: Weapon range, Damage.";
	std::cout << "\n          + Bandit:   |Equipment| -Daggers, Throwables. Light Armor.";
	std::cout << "\n                      |Ability| +In the beginning of combat, Roll Agility, Hidden for x turns.";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
}

void SceneManager::CharTut2Scene() {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                                Character Tutorial 2 / 2";
	std::cout << "\n ";
	std::cout << "\n     - Finally, all characters have a race. Depending on the race, they might have: ";
	std::cout << "\n     + Stat buffs / debuffs, Positive / Negative Passives";
	std::cout << "\n "; 
	std::cout << "\n     - Races:"; SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n         + Elf:    |Stats| +2 Wisdom, +1 Perception, -1 Strength";
	std::cout << "\n                   |Passive| (+)Extra Stamina, (-)Carry Less";
	std::cout << "\n         + Orc:    |Stats| +2 Strength, +1 Fortitude, -1 Perception";
	std::cout << "\n                   |Passive| (+)Extra Melee Damage, (-)Less Defense";
	std::cout << "\n         + Human:  |Stats| +1 Perception, +1 Wisdom, +1 Agility";
	std::cout << "\n                   |Passive| (-)Less stress cap";
	std::cout << "\n         + Goblin: |Stats| +1 Perception, +1 Strength";
	std::cout << "\n                   |Passive| (+)Affected Less by Stress"; 
	std::cout << "\n         + Dwarf:  |Stats| +2 Fortitude, +1 Strength, (-)1 Agility";
	std::cout << "\n                   |Passive| (+)Weight doesn't affect speed, (-)Move slower"; 
	std::cout << "\n         + Gnome:  |Stats| +2 Agility, +1 Perception, -1 Wisdom";
	std::cout << "\n                   |Passive| (+)Move faster, (-)Carry less";
	std::cout << "\n ";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
}

void SceneManager::CombatTut1Scene() {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
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
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
}

void SceneManager::CombatTut2Scene() {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
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
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
}

void SceneManager::CharacterScene(unsigned int state, std::string race, std::string clas, Stats stats) {
	system("CLS");
	SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 13);
	std::cout << "\n                                               Character Customization";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Race: ", 14, 13, 0, state); std::cout << race;
	std::cout << "\n ";
	std::cout << "\n "; 
	std::cout << "\n "; IsSelected("  - Class: ", 14, 13, 0, state); std::cout << clas;
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Randomize Stats - ", 14, 13, 0, state); SetConsoleTextAttribute(textConsole, 5);
	std::cout << "\n ";
	std::cout << "\n ";
	std::cout << "\n     -Stats:"; 
	std::cout << "\n         + Strength:   "; std::cout << stats.strength;
	std::cout << "\n         + Fortitude:  "; std::cout << stats.fortitude;
	std::cout << "\n         + Agility:    "; std::cout << stats.agility;
	std::cout << "\n         + Wisdom:     "; std::cout << stats.wisdom;
	std::cout << "\n         + Perception: "; std::cout << stats.perception;
	std::cout << "\n ";
	std::cout << "\n "; IsSelected("  - Continue: ", 14, 13, 0, state);
	std::cout << "\n "; SetConsoleTextAttribute(textConsole, 2);
	std::cout << "\n*----------------------------------------------------------------------------------------------------------------------*";
	std::cout << "\n ";
}