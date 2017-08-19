#include "texture.h"
#include "graphics.h"

Texture::Texture() {
	//Initialize
	texture = NULL;
	width = 0;
	height = 0;
}

Texture::~Texture() {
	free();
}

bool Texture::loadFromFile(Graphics &graphics, char* fileName) {
	bool success = true;
	//Get rid of preexisting texture if there is one
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(fileName);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", fileName, IMG_GetError());
		success = false;
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", fileName, SDL_GetError());
			success = false;
		}
		else
		{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	texture = newTexture;
	return success;
}

void Texture::free() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

// @int x, y - (x,y) area to render to on screen
void Texture::render(Graphics &graphics, int x, int y) {
	//Set rendering space and render to screen
	SDL_Rect areaToRender = { x, y, width, height };
	graphics.renderTexture(texture, &areaToRender);
}

int Texture::getWidth() {
	return width;
}

int Texture::getHeight() {
	return height;
}

SDL_Texture* Texture::getSDLTexture() {
	return texture;
}
