//#pragma once

#ifndef Game_h
#define Game_h

#include "SDL.h"
#include <stdio.h>
#include <iostream>

class Game {
public:
	Game();
	~Game();

	void initialize(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }

private:
	int count = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif; /* Game_h */