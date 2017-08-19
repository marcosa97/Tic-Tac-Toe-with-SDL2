//This class handles the game state when the game is being played

#ifndef PLAY_H
#define PLAY_H

#include "gameState.h"
#include "texture.h"
#include "board.h"
#include "graphics.h" //Needed for declareWinner(graphics)
#include "button.h"

class Play : public GameState {
private:
	//Images/Assets
	Texture background;
	Texture X;
	Texture O;
	Texture Message_TurnX;
	Texture Message_TurnO;
	Texture Message_WinnerX;
	Texture Message_WinnerO;
	Texture Message_Tie;

    //Buttons: There are 9 positions on the game board, so 9 corresponding buttons
	Button buttons[TOTAL_POSITIONS]; 

	//Game status info
	Board board; //board is represented using a 3x3 char array
	PositionCoordinates playerMove; //contains Position ID
    char turn;
	bool gameOver;

	void setUpButtons(Graphics &graphics);
public:
	Play(Graphics &graphics);   //loads resources for gameplay
	~Play();  //frees resources
	int whichButtonWasPressed(); //returns ID of one of the 9 buttons (positions) on the game board if
	                        // a button was pressed
	void switchTurns();
	void declareWinner(Graphics &graphics);

	//Main loop functions
	void handleEvents(SDL_Event &e);
	void logic();
	void render(Graphics &graphics);
};

#endif //PLAY_H