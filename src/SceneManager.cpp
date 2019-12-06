#include "../include/SceneManager.h"
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
	std::cout << "\n                                                        Settings";
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
	std::cout << "\n ";
	std::cout << "\n     Current Seed: "; std::cout << seed;
	std::cout << "\n ";
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