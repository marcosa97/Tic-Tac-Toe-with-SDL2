//This class wraps the SDL_Texture
#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

class Graphics;

class Texture {
private:
	//actual harware texture
	SDL_Texture* texture;

	//image dimensions
	int width;
	int height;

public:
	Texture();
	~Texture();
	bool loadFromFile(Graphics &graphics, char* fileName); //haven't used retrn bool value yet!
	void free(); //deallocates texture
	void render(Graphics &graphics, int x, int y); //renders texture at a given (x,y) point

	int getWidth();
	int getHeight();
	SDL_Texture* getSDLTexture();

};

#endif //TEXTURE_H
