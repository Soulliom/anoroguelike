#ifndef INPUT_M_H
#define INPUT_M_H

#include "DEFINITIONS.h"

//Saves SceneState and updates when different scenes are loaded
class InputManager {
public:
	//Text - What text will be displayed. Key - what key is needed to press, NULL for none
	void Pause(std::string text, const unsigned int key);

private:
};

#endif 