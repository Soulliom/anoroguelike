#include "../include/SceneManager.h"
#include "../include/InputManager.h"
#include "../include/DEFINITIONS.h"

int main(){
	/* Init */
	SceneManager scene;
	InputManager input;

	/* Title */
	scene.Title();
	input.Pause("Press the [Space] key to Continue.", SPAC); 

	/* Settings */
}
