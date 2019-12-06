#ifndef SCENE_M_H
#define SCENE_M_H

#include "DEFINITIONS.h"

//Contains different scenes
class SceneManager {
private:
	//If current item is selected
	void IsSelected(std::string text, int selectColor, int defaultColor, int state, int selectState);
public:
	//Console Init
	SceneManager();
	//Title Scene
	void TitleScene();
	/* Settings Scenes*/
	//Settings Scene
	void SettingsScene(unsigned int state, std::string diff, long seed);
	//Difficulty Setting Scene
	void DiffScene(unsigned int state, std::string diff);
	//Seed Setting Scene
	void SeedScene(unsigned int state, long long seed);

	HWND consoleWindow = GetConsoleWindow();
	HANDLE textConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

#endif 