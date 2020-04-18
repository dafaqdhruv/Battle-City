// Chollenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
// simple object buster game in one night as a challenge using SDL2
// made by Dhruv on 17/1/2020

#include <iostream>
#include "Game.h"

#undef main

Game* game = nullptr;

int main()
{
	Uint32 timestamp = 0;
	int time_taken = 0;
	int FPS = 100;
	int delay = 1000 / FPS;

	game = new Game();
	game->Init("Chollenge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);

	cout << game->isRunning() << "  Game Init Successful!\n";

	while (game->isRunning()) {
		timestamp = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();

		time_taken = SDL_GetTicks() - timestamp;
		if (delay > time_taken)
			SDL_Delay(delay - time_taken);
	}

	game->clean();
	return 0;
}