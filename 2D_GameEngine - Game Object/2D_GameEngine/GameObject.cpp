#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* rend, int x, int y) {
	renderer = rend;
	objectTexture = TextureManager::LoadTexture(textureSheet, rend);
	xpos = x;
	ypos = y;
}
GameObject::~GameObject() {

}

void GameObject::Update() {
	
	xpos++;
	ypos++;
	srcRectangle.h = 32;
	srcRectangle.w = 32;
	srcRectangle.x = 0;
	srcRectangle.y = 0;

	destRectangle.x = xpos;
	destRectangle.y = ypos;
	destRectangle.w = srcRectangle.w * 2;
	destRectangle.h = srcRectangle.h * 2;
}
void GameObject::Render() {
	SDL_RenderCopy(renderer, objectTexture, &srcRectangle, &destRectangle);
}