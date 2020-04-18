#include "Map.h"

int map[20][25];
int grid[20][25] = {

//	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24}

	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 	//A
	{4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4}, 	//B
	{4, 4, 4, 4, 3, 3, 3, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 0, 3, 3, 3, 4, 4, 4, 4}, 	//C
	{4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4}, 	//D
	{4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4}, 	//E
	{4, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 4, 4}, 	//F
	{4, 0, 0, 0, 0, 3, 0, 4, 4, 4, 4, 0, 0, 0, 4, 4, 4, 4, 0, 3, 0, 0, 0, 0, 4}, 	//G
	{0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0}, 	//H
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 	//I
	{0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0}, 	//J
	{0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, 	//K
	{0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0}, 	//L
	{0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0}, 	//M
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 	//N
	{0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0}, 	//O
	{0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0}, 	//P
	{0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0}, 	//Q
	{0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0}, 	//R
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 	//S
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//T
};

//node A1, B2, C3, D4;

Map::Map() {
	Trophy = TextureManager::LoadTexture("assets/Trophy.png");
	wall_brick = TextureManager::LoadTexture("assets/wall_brick.png");
	wall_double_damage = TextureManager::LoadTexture("assets/wall_double_damage.png");
	wall_stone = TextureManager::LoadTexture("assets/wall_stone.png");
	wall_unbreakable = TextureManager::LoadTexture("assets/wall_superhard.png");
	bush_trans = TextureManager::LoadTexture("assets/camo.png");

	src.h = src.w = 32;
	src.x = src.y = 0;
	Dest.x = Dest.y = 0;
	Dest.h = Dest.w = 32;

	LoadMap(grid);
	cout << "Map Loaded.\n";
}

void Map::LoadMap(int x[20][25]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 25; j++) {
			map[i][j] = x[i][j];
		}
	}

	/*
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 25; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/
}

void Map::DrawMap() {
	int type = 0;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 25; j++) {
			type = map[i][j];

			Dest.x = j * 32;
			Dest.y = i * 32;

			switch (type) {
				//case 0:	TextureManager::Draw(metal, srcRect, destRect);
				//	break;
			case 1: TextureManager::Draw(Trophy, src, Dest, 0, SDL_FLIP_NONE);
				break;

			case 2: TextureManager::Draw(wall_stone, src, Dest, 0, SDL_FLIP_NONE);
				break;

			case 3: TextureManager::Draw(wall_brick, src, Dest, 0, SDL_FLIP_NONE);
				break;

			case 4: TextureManager::Draw(wall_unbreakable, src, Dest, 0, SDL_FLIP_NONE);
				break;

			case 5: TextureManager::Draw(wall_double_damage, src, Dest, 0, SDL_FLIP_NONE);
				break;

			case 6: TextureManager::Draw(bush_trans, src, Dest, 0, SDL_FLIP_NONE);
				break;
			}
		}
	}
}

int Map::viewMap(int a, int b) { return map[a / 32][b / 32]; }

void Map::render_Grass() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 25; j++) {
			if (map[i][j] == 6) {
				Dest.x = j * 32;
				Dest.y = i * 32;

				TextureManager::Draw(bush_trans, src, Dest, 0, SDL_FLIP_NONE);
			}
		}
	}
}

void Map::modify_map(int r, int c, int value) {
	map[r][c] = value;
}