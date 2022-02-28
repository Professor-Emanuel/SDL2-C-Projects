#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

/* NOT needed anymore, since we created GameObject class
SDL_Texture* playerTexture;
SDL_Rect srcRectangle, destRectangle;
*/

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr; //initialize with nullptr since we haven't started initializing SDL

Game::Game() {}
Game::~Game() {}

void Game::initialize(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {
	int flags = 0;
	if (fullScreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Success: Subsystem Initialised!..." << std::endl;

		//create the window
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		//check if the window was created successfully
		if (window) {
			std::cout << "Success: Window created!..." << std::endl;
		}

		//create the renderer
		renderer = SDL_CreateRenderer(window, -1, 0);

		//check if the renderer was created successfully
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Success: Renderer created!..." << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/player.png", 0, 0);
	enemy = new GameObject("assets/enemy.png", 50, 50);
	map = new Map();
}
void Game::handleEvents() {
	//create an event
	SDL_Event event;
	//hold that event
	SDL_PollEvent(&event);

	//find out what type of event it is and look out for the quit event
	switch (event.type) {
	//when we click the X on the window, we generate quit event
	case SDL_QUIT:
		isRunning = false;
		break;

	default :
		break;
	}

}
void Game::update() {
	player->Update();
	enemy->Update();
}
void Game::render() {
	//clear the renderer buffer
	SDL_RenderClear(renderer);

	map->DrawMap();
	player->Render();
	enemy->Render();

	//this is where we would add stuff to render
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Success: Game Cleaned!..." << std::endl;

}
