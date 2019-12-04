#ifndef INPUT_M_H
#define INPUT_M_H

#include "DEFINITIONS.h"

//Saves SceneState and updates when different scenes are loaded
class InputManager {
public:
	//Text- What text will be displayed. Seconds- length of delay. Key- what key is needed to press to continue, NULL for none.
	void Pause(std::string text, const unsigned int seconds, const unsigned int key);

private:
};

#endif 