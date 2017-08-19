//This class implements the mouse button to click on

//Note: This button design makes it so that each button has its own sprite sheet (stored
//      in a Texture object from texture.h) and its own 
//      sprite clips array, so the textures are going to be loaded as many times as there are buttons
//        -> For more efficiency, I need to redesign the button class so that the 
//           the texture that has the sprite sheet is not built into the button class, i.e.,
//           the Texture object is not a member of the class. 
#ifndef BUTTON_H
#define BUTTON_H

#include "texture.h"
#include "graphics.h" //Needed for render(graphics)

//Note: The sprite sheet has to be formatted vertically, meaning that 
//        the sprites are on top of each other only
//        Ex/ [ sprite 1 ]
//            [ sprite 2 ]
//            [ sprite 3 ]
//      The order that the sprites should be in in the sprite sheet is below
enum ButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT, //0     //Mouse is outside the button
	BUTTON_SPRITE_MOUSE_OVER_MOTION, //Mouse is over the button
	BUTTON_SPRITE_MOUSE_DOWN,        //Button has been pressed on
	BUTTON_SPRITE_TOTAL,             //Total number of sprites
};

class Button {
private:
	Texture buttonSpriteSheet;
	SDL_Rect spriteClips[BUTTON_SPRITE_TOTAL];
	SDL_Point position;  //Position is the top left point of the button
	int currentSpriteID; //Currently used sprite -> tells us what sprite to render
	int buttonWidth;
	int buttonHeight;
public:
	Button();
	~Button();
	bool buttonWasPressed();

	//Functions for setting up button properties
	//sets top left position
	void setPosition(int x, int y);
	void setDimensions(int width, int height);
	void loadTextureAndSprites(Graphics &graphics, char* fileName);

	//Handles mouse event
	void handleEvent(SDL_Event &e);
	bool mouseInButton();

	void render(Graphics &grahpics); //take as parameters the position to render at
};

#endif //BUTTON_H