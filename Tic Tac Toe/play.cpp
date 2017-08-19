#include "play.h"

//loads intro resources
Play::Play(Graphics& graphics) {
	//Load textures
	background.loadFromFile(graphics, "images/Tic Tac Toe grid.png");
	O.loadFromFile(graphics, "images/O.png");
	X.loadFromFile(graphics, "images/X.png");
	Message_TurnO.loadFromFile(graphics, "images/Player O's Turn.png");
	Message_TurnX.loadFromFile(graphics, "images/Player X's Turn.png");
	Message_WinnerO.loadFromFile(graphics, "images/Player O Wins.png");
	Message_WinnerX.loadFromFile(graphics, "images/Player X Wins.png");
	Message_Tie.loadFromFile(graphics, "images/tie.png");
	
	//Set up buttons
	setUpButtons(graphics);

	//Create tic tac toe board
	//  ->Implemented using an array of arrays, 3x3
	//Player X always goes first
	turn = PLAYER_X;
	playerMove.positionID = -1; //-1 so we don't draw X's or O's until the first turn is taken
	playerMove.coordinates = std::make_pair(0, 0);
	gameOver = false;
    nextStateID = STATE_NULL;
}

//frees resources
Play::~Play() {
	background.free();
	O.free();
	X.free();
	Message_TurnO.free();
	Message_TurnX.free();
	Message_WinnerO.free();
	Message_WinnerX.free();
	Message_Tie.free();
	//Buttons are freed by their destructor
}

//Sets up the 9 buttons for each position in the game board
// -sets up dimensions of the buttons
// -loads textures for each button
// -sets location for each button on the game board
void Play::setUpButtons(Graphics &graphics) {

	//Note: This button design makes it so that each button has its own sprite sheet and
	//      sprite clips, so the textures are going to be loaded 9 times 
	//        -> For more efficiency, I need to redesign the button class so that the 
	//           the texture that has the sprite sheet is not built into the button class, i.e.,
	//           the Texture object is not a member of the class. 
	for (int i = 0; i < TOTAL_POSITIONS; i++) {
		buttons[i].setDimensions(105, 110);
		buttons[i].loadTextureAndSprites(graphics, "images/Button spritesheet.png");
	}

	buttons[POS_1].setPosition(35, 53);
	buttons[POS_2].setPosition(145, 53);
	buttons[POS_3].setPosition(255, 53);
	buttons[POS_4].setPosition(35, 165);
	buttons[POS_5].setPosition(145, 165);
	buttons[POS_6].setPosition(255, 165);
	buttons[POS_7].setPosition(35, 278);
	buttons[POS_8].setPosition(145, 278);
	buttons[POS_9].setPosition(255, 278);
}

//Returns the ID of the button that was pressed, if a button was pressed, or 
// else it returns OUTSIDE_BOARD
int Play::whichButtonWasPressed() {
	//Note: POS_ID corresponds to the position ID's in the enumerations in board.h
	//      ->The position ID's also correspond to the indices for the buttons array 
	//           EX) buttons[POS_ID]
	for (int POS_ID = 0; POS_ID < TOTAL_POSITIONS; POS_ID++) {
		if (buttons[POS_ID].buttonWasPressed()) {
			return POS_ID; 
		}
	}

	//Program reaches this point if none of the 9 buttons were pressed
	return OUTSIDE_BOARD;
}

//Switches turns between PLAYER_X and PLAYER_O by changing "turn" value
void Play::switchTurns() {
	if (turn == PLAYER_X)
		turn = PLAYER_O;
	else if (turn == PLAYER_O)
		turn = PLAYER_X;
}

//Once the game is over, this function renders and displays a message
// saying who won
void Play::declareWinner(Graphics &graphics) {
	//If a tie
	if (board.boardIsFull() && !board.won()) {
		Message_Tie.render(graphics, 420, 10);
	}
	//If player O won
	else if (turn == PLAYER_O) {
		Message_WinnerO.render(graphics, 420, 10);
	}
	//If player X won
	else if (turn == PLAYER_X) {
		Message_WinnerX.render(graphics, 420, 10);
	}

	SDL_RenderPresent(graphics.getRenderer());
	SDL_Delay(1000); //show message for 1 seconds
}

//Handles mouse input while the user plays a game
void Play::handleEvents(SDL_Event &e) {

	//While there's events to handle
	while (SDL_PollEvent(&e))
	{
		 //handle button events
		for (int i = 0; i < TOTAL_POSITIONS; i++) {
			buttons[i].handleEvent(e);
		}

		//If the user has Xed out the window
		if (e.type == SDL_QUIT)
		{
			//Quit the program
			requestStateChange(STATE_EXIT);
		}

		//If mouse was clicked
		else if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			//Check which button was pressed
			switch (whichButtonWasPressed()) {
			    case OUTSIDE_BOARD:
					break; //Ignore input
			    case POS_1:
					playerMove = board.getPositionsOnBoard()[0]; break;
				case POS_2:
					playerMove = board.getPositionsOnBoard()[1]; break;
				case POS_3:
					playerMove = board.getPositionsOnBoard()[2]; break;
				case POS_4:
					playerMove = board.getPositionsOnBoard()[3]; break;
				case POS_5:
					playerMove = board.getPositionsOnBoard()[4]; break;
				case POS_6:
					playerMove = board.getPositionsOnBoard()[5]; break;
				case POS_7:
					playerMove = board.getPositionsOnBoard()[6]; break;
				case POS_8:
					playerMove = board.getPositionsOnBoard()[7]; break;
				case POS_9:
					playerMove = board.getPositionsOnBoard()[8]; break;
			} //switch
		} //else
	} //while
}

//Handles logic when the game is being played:
void Play::logic() {
	
	if (gameOver) {
		requestStateChange(STATE_GAME_OVER);
	}
	else {
		//Only listen for valid input (position is not taken already)
		if (board.isValidMove(playerMove.positionID)) {
			board.makeMove(playerMove.positionID, turn);

			//If game is over, request new state
			if (board.isGameOver())
				gameOver = true;
			else
				switchTurns();
		}  //if
	}// else

}

//Renders current state of the game after logic has been handled
void Play::render(Graphics &graphics) {
	background.render(graphics, 0, 0);

	//Note: This rendering method renders every X and O on the board
	//      every time instead of just rendering the new move because
	//      in the main game loop, the renderer gets cleared every cycle (screen is cleared)
	//Update: To fix this, I can make the draw() function in game.cpp be a part of gameState.h
	//      and have inherited classes rewrite it to suit their needs

	
    //Render each position on the board that is already taken
	//For each position on the board
	for (int i = 0; i < 9; i++) {
		if (board.getGameBoard()[i] == PLAYER_X) {
			X.render(graphics, board.getPositionsOnBoard()[i].coordinates.first,  // = x position
				               board.getPositionsOnBoard()[i].coordinates.second);// = y position
		} //if gameBoard[i] is taken up by "X", display X
		else if (board.getGameBoard()[i] == PLAYER_O) {
			O.render(graphics, board.getPositionsOnBoard()[i].coordinates.first,   // = x position
				               board.getPositionsOnBoard()[i].coordinates.second); // = y position
		} //else if gameBoard[i] is taken up by "O", display O
	}

	//Render buttons
	for (int i = 0; i < TOTAL_POSITIONS; i++) {
		buttons[i].render(graphics);
	}

	//If game is not over indicate whose turn it is 
	if (gameOver) {
		declareWinner(graphics);
	} //If the game is over
	else {
		//Indicate whose turn it is
		if (turn == PLAYER_X)
			Message_TurnX.render(graphics, 400, 15);
		else if (turn == PLAYER_O)
			Message_TurnO.render(graphics, 400, 15);
	}

}