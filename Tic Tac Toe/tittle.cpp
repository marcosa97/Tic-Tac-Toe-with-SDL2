#include "title.h"

Title::Title(Graphics &graphics) {
	if (!titleScreen.loadFromFile(graphics, "images/title screen.png"))
		printf("Failed to load Title Screen!\n");
	nextStateID = STATE_NULL;
}

Title::~Title() {
	titleScreen.free();
}

void Title::handleEvents(SDL_Event &e) {
	//While there's events to handle
	while (SDL_PollEvent(&e))
	{
		//If the user has Xed out the window
		if (e.type == SDL_QUIT)
		{
			//Quit the program
			requestStateChange(STATE_EXIT);
		}
		//If the user pressed enter
		else if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_RETURN))
		{
			//Move to the title screen
			requestStateChange(STATE_PLAY);
		}
	}
}

void Title::logic() {
	//nothing happens. We only display an image in the intro
}

void Title::render(Graphics &graphics) {
	//render title screen
	titleScreen.render(graphics, 0, 0);
}