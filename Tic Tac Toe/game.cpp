#include "game.h"

Game::Game() {
	currentState = NULL;
	currentStateID = STATE_NULL;
	nextState = STATE_NULL;

	//graphics is initialized when declared
}

Game::~Game() {
	graphics.free();
	delete currentState;
}

bool Game::initSucceeded() {
	if (graphics.initSucceeded())
		return true;
	else
		return false;
}

//Main game loop
void Game::gameLoop() {
	currentStateID = STATE_INTRO;
	nextState = STATE_NULL; 
	currentState = new Intro(graphics); 

	//Event handler
	SDL_Event e;

	//While application is running
	while (currentStateID != STATE_EXIT)
	{		
		//Do state event handling
        currentState->handleEvents(e);

        //Do state logic
        currentState->logic();

        //Change state if needed
		nextState = currentState->getNextStateID();
		if(nextState != STATE_NULL)
            changeState();

        //Do state rendering
        currentState->render(graphics);
		
		//Update screen
		draw();
		
	}
}

//This function changes the state of the game if the variable "nextState"
//  is set to something other than STATE_NULL
void Game::changeState() {
	//If next state needs to be changed
	if (nextState != STATE_NULL) {
		//Delete current state
		if (nextState != STATE_EXIT) {
			delete currentState;
		}
		switch (nextState) {
		    case STATE_TITLE:
				currentState = new Title(graphics);
				break;
			case STATE_PLAY:
				currentState = new Play(graphics);
				break;
			case STATE_GAME_OVER:
				currentState = new GameOver(graphics);
				break;
		}
		//change current ID
		currentStateID = nextState;

		//NULL the next state ID
		nextState = STATE_NULL;
	}
}

//Updates the screen
void Game::draw() {
	//Clear screen
	SDL_SetRenderDrawColor(graphics.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(graphics.getRenderer());

	//Render background texture to screen
	currentState->render(graphics);

	//Update screen ->This is what displays what was drawn/rendered
	SDL_RenderPresent(graphics.getRenderer());
}


