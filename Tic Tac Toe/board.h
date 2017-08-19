//This class will be used to represent the Tic Tac Toe game board in a 3x3 array
#ifndef BOARD_H
#define BOARD_H

#include <utility>
#include "SDL.h"

#define EMPTY_SPACE '*'
#define PLAYER_X 'x'
#define PLAYER_O 'o'


/*
Note: The 3x3 game board is represented using a 1D char array.
This is the mapping the game board uses:
    
   1|2|3
   -----
   4|5|6
   -----
   7|8|9

Note: Each position on the board has a unique ID (POS_1, POS_2, etc) and those ID's are used
      to identify input and handle logic
*/
enum BoardPositionIDs {
	POS_1, //0
	POS_2,
	POS_3,
	POS_4,
	POS_5,
	POS_6,
	POS_7,
	POS_8,
	POS_9,
	TOTAL_POSITIONS = 9,
	OUTSIDE_BOARD = -1, //Any position outside the game board
};

//Position coordinates (x,y) are where each position on the game board
// is located on "Tic Tac Toe grid.png" (the background picture)
struct PositionCoordinates {
	int positionID;
	std::pair <int, int> coordinates; //<x,y>
	PositionCoordinates(); //initializes everything to 0
};


class Board {
private:
	char gameBoard[9]; //contains current board status
	PositionCoordinates positionsOnBoard[9];

public:
	Board();
	~Board();
	bool isGameOver();
	PositionCoordinates* getPositionsOnBoard();
	char* getGameBoard();

	//Functions for checking if game is over
	bool won();
	bool allEqual(char A, char B, char C); //checks if the three chars, A, B, C, are equal 
	bool rowWin();
	bool columnWin();

	bool diagonalWin();
	bool leftDiagonalWin();
	bool rightDiagonalWin();

	bool boardIsFull();

	//Functions for making a move
	bool isValidMove(int move); //validate move
	void makeMove(int move, char turn); //apply move to board

};

#endif //BOARD_H