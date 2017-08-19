#include "game.h"
#include "gameState.h"

int main(int argc, char* argv[])
{
	Game game;

	if (!game.initSucceeded()) {
		printf("Game failed to initialize!\n");
		SDL_Delay(3000);
		return 0;
	}

	//Start game application
	game.gameLoop();

	return 0;
}