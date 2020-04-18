#pragma once
#ifndef TextureManager_h
#define TextureManager_h
#include "Game.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, double angle, SDL_RendererFlip fliptype);
};
#endif // !TextureManager_h
