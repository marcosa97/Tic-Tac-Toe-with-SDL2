/*
* Core of the game
*/

#ifndef GAME_H
#define GAME_H

#include "graphics.h"
#include "texture.h"
#include "gameState.h"
#include "intro.h"
#include "title.h"
#include "play.h"
#include "gameOver.h"

class Game {
private:
	//bool success;
	Graphics graphics;

	//These handle game states 
	GameState* currentState;
	int currentStateID;
	int nextState;

public:
	Game();
	~Game();
	bool initSucceeded();

	//Game loop methods
	void gameLoop();
	void changeState();
	void draw();
};

#endif //GAME_H
