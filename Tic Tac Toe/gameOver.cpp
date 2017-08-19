#include "gameOver.h"

GameOver::GameOver(Graphics &graphics) {
	if (!gameOverScreen.loadFromFile(graphics, "images/Game Over.png"))
		printf("Failed to load Title Screen!\n");
	nextStateID = STATE_NULL;
}

GameOver::~GameOver() {
	gameOverScreen.free();
}

void GameOver::handleEvents(SDL_Event &e) {
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
			//Play again
			requestStateChange(STATE_PLAY);
		}
		//If the user doesn't want to play again
		else if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_BACKSPACE))
		{
			//Move to the title screen
			requestStateChange(STATE_TITLE);
		}
	}
}

void GameOver::logic() {
	//nothing happens. We only display an image in the intro
}

void GameOver::render(Graphics &graphics) {
	//Show image
    gameOverScreen.render(graphics, 0, 0);
}