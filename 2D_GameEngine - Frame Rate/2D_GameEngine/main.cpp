//***
//don't forget to copy-paste SDL2.dll in the same folder as main.cpp
//the project simply creates a white window, but we use OOP in comparison with FirstSDLWindow project
/*
* As long as the game is running: 
1. handle any user input
2. update all objects eg positions etc.
3. render changes to the display
*/

#include "Game.h"

Game* game = nullptr;

//const char* argv[] -> the const generates some errors
int main(int argc, char* argv[]) {

	const int FPS = 60; //60 is the closest to our refresh rate of our monitors
	const int frameDelay = 1000 / FPS; //max time between frames - how long a frame is supposed to take
	Uint32 frameStart; //our game time, how long the game will run
	int frameTime; //

	game = new Game();
	game->initialize("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {
		frameStart = SDL_GetTicks(); //set to how many milliseconds since we initialized SDL

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	return 0;
}
