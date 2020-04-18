#pragma once
#ifndef Game_h
#define Game_h

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
//#include "Bot.h"

using namespace std;

class Game {
public:
	Game();
	~Game();

	void Init(const char* Title, int xpos, int ypos, int height, int width, bool fullscreen);
	void handle_events();
	void update();
	void render();
	void clean();

	bool isRunning() { return running; }

	static SDL_Renderer* Renderer;

private:

	bool running;
	SDL_Window* Window;
};

#endif //!game.h