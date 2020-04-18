#pragma once
#include "Tank.h"
#include "Game.h"


class Bot : public Tank {
public:
	Bot(const char* filename, int x, int y, const char* obj_type_name, int bit_size);
	~Bot();

	void spawn() {};
	void Bot_update();
	void die() {};
	void move_to(int x, int y);

private :
	vector<int> route;
};
