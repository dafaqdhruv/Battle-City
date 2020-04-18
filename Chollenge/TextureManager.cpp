#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename) {
	SDL_Surface* tempsurf = IMG_Load(filename);
	SDL_Texture* out = SDL_CreateTextureFromSurface(Game::Renderer, tempsurf);
	SDL_FreeSurface(tempsurf);
	return out;
}

void TextureManager::Draw(SDL_Texture* Tex, SDL_Rect src, SDL_Rect dest, double angle = 0, SDL_RendererFlip fliptype = SDL_FLIP_NONE) {
	//SDL_RenderCopy(Game::Renderer, Tex, &src, &dest);

	SDL_RenderCopyEx(Game::Renderer, Tex, &src, &dest, angle, NULL, fliptype);
}