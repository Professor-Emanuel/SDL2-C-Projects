#pragma once
#include "Game.h"

class GameObject {
public:
	GameObject(const char* textureSheet, SDL_Renderer* rend, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objectTexture;
	SDL_Rect srcRectangle, destRectangle;
	SDL_Renderer* renderer;

};