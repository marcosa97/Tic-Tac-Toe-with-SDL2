#include "board.h"

PositionCoordinates::PositionCoordinates() {
	positionID = 0;
	coordinates = std::make_pair(0, 0);
}

Board::Board() {
	for (int i = 0; i < 9; i++) {
		gameBoard[i] = EMPTY_SPACE; //initialize to something
		positionsOnBoard[i].positionID = i; //Luckily, i also corresponds to POS_1, POS_2, ..., POS_9
	}

	positionsOnBoard[0].coordinates = std::make_pair(50, 75);
	positionsOnBoard[1].coordinates = std::make_pair(160, 75);
	positionsOnBoard[2].coordinates = std::make_pair(270, 75);
	positionsOnBoard[3].coordinates = std::make_pair(50, 185);
	positionsOnBoard[4].coordinates = std::make_pair(160, 185);
	positionsOnBoard[5].coordinates = std::make_pair(270, 185);
	positionsOnBoard[6].coordinates = std::make_pair(50, 295);
	positionsOnBoard[7].coordinates = std::make_pair(160, 295);
	positionsOnBoard[8].coordinates = std::make_pair(270, 295);

}

Board::~Board() {

}

//Returns true if someone won or there was a tie
bool Board::isGameOver() {
	//if there was a win or the board got full (tie)
	if (won() || boardIsFull())
		return true;
	else
		return false;
}

//gets pointer to the array containing positions on board
PositionCoordinates* Board::getPositionsOnBoard() {
	return positionsOnBoard;
}

//gets pointer to the array containing current board status
char* Board::getGameBoard() {
	return gameBoard;
}

//============== Functions for checking if game is over ========

bool Board::won() {
	//determine if the conditions are met for a row, column, or diagonal win
	if (rowWin() || columnWin() || diagonalWin())
		return true;
	else
		return false;
}

//This function checks if the three given chars are equal
// and not empty (EMPTY_SPACE) , i.e., chars meet criteria for a tic tac toe win
bool Board::allEqual(char A, char B, char C) {
	if ((A != EMPTY_SPACE) && (A == B) && (B == C))
		return true;
	else
		return false;
}

//Check if there is a win in a row
// @Returns: true if there is a row win, false otherwise
bool Board::rowWin() {
	if (allEqual(gameBoard[0], gameBoard[1], gameBoard[2]))
		return true;

	if (allEqual(gameBoard[3], gameBoard[4], gameBoard[5]))
		return true;

	if (allEqual(gameBoard[6], gameBoard[7], gameBoard[8]))
		return true;
	
	return false;
}

//Check if there is a win in a column
// @Returns: true if there is a column win, false otherwise
bool Board::columnWin() {
	if (allEqual(gameBoard[0], gameBoard[3], gameBoard[6]))
		return true;

	if (allEqual(gameBoard[1], gameBoard[4], gameBoard[7]))
		return true;

	if (allEqual(gameBoard[2], gameBoard[5], gameBoard[8]))
		return true;
	return false; //placeholder
}

//Checks if there is a win in a diagonal
// @returns: true if there is, false otherwise
bool Board::diagonalWin() {
	if (leftDiagonalWin() || rightDiagonalWin())
		return true; 
	else
		return false;
}

//Check if there is a win from the bottom left corner to the upper right
// @returns: true if there is a win from the bottom left corner to the upper right
bool Board::leftDiagonalWin() {
	if (allEqual(gameBoard[6], gameBoard[4], gameBoard[2]))
		return true; 
	else
		return false;
}

//check if there is a win from the bottom right corner to the upper left
// @returns: true if there is a win from the bottom right corner to the upper left
bool Board::rightDiagonalWin() {
	if (allEqual(gameBoard[8], gameBoard[4], gameBoard[0]))
		return true;
	else
		return false;
}

//Note: If there is no win, this function is called after win()
//      to see if the board is full, i.e., there was a tie.
//      THIS FUNCTION MUST BE CALLED ONLY AFTER win() 
bool Board::boardIsFull() {
	for (int i = 0; i < 9; i++) {
		if (gameBoard[i] == EMPTY_SPACE)
			return false;
	}

	return true;
}

//=================== Functions for making a move ========================

//Validate move
bool Board::isValidMove(int move) {
	if(gameBoard[move] == EMPTY_SPACE)
	    return true; //placeholder
	else {
		//tell user that the position is already taken 
		return false;
	}
}

//apply move to board
void Board::makeMove(int move, char turn) {
	gameBoard[move] = turn;
} 