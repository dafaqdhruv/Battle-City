#pragma once
#include "GameObject.h"
#define _max_missile_count 5

class Tank : public GameObject {

public:
	Tank(const char* filename, int x, int y, const char* obj_type_name, int bit_size);
	~Tank() {};

	//bool flag;
	double temp_angle;
	SDL_RendererFlip temp_flip2;
	void render_missiles();
	int miss_num() { return missile_count; }
	void miss_shoot() { missile_count++; }
	void miss_poof() {  missile_count--; }


private:
	vector <GameObject*> missiles;
	int missile_count;
};