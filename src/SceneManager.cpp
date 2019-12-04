#include "../include/SceneManager.h"
/* TEMPLATE SCENE
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

void SceneManager::Title() {
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