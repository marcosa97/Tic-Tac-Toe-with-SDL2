//This class handles the game over screen for the game
#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "gameState.h"
#include "texture.h"

class GameOver : public GameState {
private:
	Texture gameOverScreen;
public:
	GameOver(Graphics &graphics);
	~GameOver();

	//Main loop functions
	void handleEvents(SDL_Event &e);
	void logic();
	void render(Graphics &graphics);
};

#endif //GAME_OVER_H