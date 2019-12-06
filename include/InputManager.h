#ifndef INPUT_M_H
#define INPUT_M_H

#include "DEFINITIONS.h"
#include "Player.h"

//Saves SceneState and updates when different scenes are loaded
class InputManager {
private:
	//Current Selected Item
	unsigned int selectState = 0;
public:

	/* Pauses, Inputs, Navigations.*/
	//Text- What text will be displayed. Seconds- length of delay. Key- what key is needed to press to continue, NULL for none.
	void Pause(std::string text, const unsigned int seconds, const unsigned int key);
	//cin String Input
	std::string StringInput(std::string text);
	//cin Int Input
	int IntInput(std::string text);
	//Up/Down Navigation
	void WSNav(unsigned int input, const unsigned int max);
	//Left/Right Navigation
	void ADNav(unsigned int input, const unsigned int max);
	//Up/Left/Down/Right Navigation (Patent Pending)
	void WASDNav();

	/* Inputs for Specific Scenes */
	//Difficulty Scene Input
	bool DiffInput(int temp);
	//Seed Scene Input
	bool SeedInput(int temp);

	/* Getters/Setters */
	//Set Select State
	void setSelectState(unsigned int state);
	//Get Select State
	int getSelectState();
};

#endif 