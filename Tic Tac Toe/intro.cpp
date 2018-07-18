#include "intro.h"

Intro::Intro(Graphics &graphics) {
	if (!introImage.loadFromFile(graphics, "images/intro.png"))
		printf("Failed to initialize Intro!\n");
	nextStateID = STATE_NULL;
}

Intro::~Intro() {
	introImage.free();
}

void Intro::handleEvents(SDL_Event &e) {
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
			requestStateChange(STATE_TITLE);
		}
	}
}

void Intro::logic() {
	//nothing happens. We only display an image in the intro

        //Wait for 2 seconds before showing title screen
        if ( SDL_GetTicks() >= 2000 ) {
                requestStateChange(STATE_TITLE);
        }
}

void Intro::render(Graphics &graphics) {
	//Show image
	introImage.render(graphics, 0, 0);
}
