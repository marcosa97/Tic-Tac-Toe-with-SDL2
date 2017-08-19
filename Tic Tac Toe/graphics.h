#ifndef GRAPHICS_H
#define GRAPHICS_H

//2nd and 3rd tutorial from Lazy Foo's tutorials
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
//#include "texture.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

//forward declaration
class Texture;

class Graphics {
private:
	bool initSuccess; //indicates whether initialization was successful or not
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Graphics();
	~Graphics();//Frees media and shuts down SDL
	bool init(); //initializes SDL
	bool initSucceeded();
	void free(); //frees resources 
				 //void drawScenery(Texture &t1, Texture &t2); //draw to window
	SDL_Renderer* getRenderer() const;

	/* void renderTexture()
	* Draws a texture to a certain part of the screen
	*  @texture - what we are drawing from
	*  @sourceRectangle - the part from source that we want to draw
	*  @destinationRectangle - where we are drawing to
	*/
	void renderTexture(SDL_Texture* texture, SDL_Rect* destination); //calls SDL_RenderCopy

};

#endif //GRAHIPCS_H
