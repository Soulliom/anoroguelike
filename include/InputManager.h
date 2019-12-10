
#ifndef INPUT_M_H
#define INPUT_M_H

#include "DEFINITIONS.h"
#include "Player.h"

//Saves SceneState and updates when different scenes are loaded
class InputManager {
private:
	//Current Selected Item
	struct selectStateStru {
		unsigned int x = 0;
		unsigned int y = 0;
	};
public:
	/* Pauses, Inputs, Navigations.*/
	//Text- What text will be displayed. Seconds- length of delay. Key- what key is needed to press to continue, NULL for none.
	void Pause(std::string text, const unsigned int seconds, const unsigned int key = NULL);
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

	// SelectState Obj
	selectStateStru selectState;

	/* Getters/Setters */
	//Set Select State
	void setSelectState(unsigned int x, unsigned int y);
	//Get Select State
	int getSelectStateX();
	int getSelectStateY();
};

#endif 