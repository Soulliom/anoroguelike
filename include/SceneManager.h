#ifndef SCENE_M_H
#define SCENE_M_H

#include "DEFINITIONS.h"

//Contains different scenes
class SceneManager {
public:
	//Console Init
	SceneManager();
	//Title Scene
	void Title();

	HWND consoleWindow = GetConsoleWindow();
	HANDLE textConsole = GetStdHandle(STD_OUTPUT_HANDLE);
private:
};

#endif 