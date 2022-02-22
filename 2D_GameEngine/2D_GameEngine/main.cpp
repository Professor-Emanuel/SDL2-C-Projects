//***
//don't forget to copy-paste SDL2.dll in the same folder as main.cpp
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
	game = new Game();
	game->initialize("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}
