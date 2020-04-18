#pragma once
#ifndef Map_h
#include"Game.h"
#include "TextureManager.h"

//struct node {
//	int x, y;
//};

class Map {
public:
	Map();
	~Map() {};

	void LoadMap(int x[20][25]);
	void DrawMap();
	void render_Grass();
	static void modify_map(int r, int c, int value);
	static int viewMap(int a, int b);

private:

	SDL_Rect src, Dest;
	SDL_Texture* Trophy = nullptr;
	SDL_Texture* wall_brick = nullptr;
	SDL_Texture* wall_stone = nullptr;
	SDL_Texture* wall_double_damage = nullptr;
	SDL_Texture* wall_unbreakable = nullptr;
	SDL_Texture* bush_trans = nullptr;
};

#endif // !Map_h
