#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* rend) {
	//create a surface
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, tempSurface);

	//clear surface
	SDL_FreeSurface(tempSurface);
	return tex;
}