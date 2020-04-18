#include "Bot.h"
#include <stdlib.h>
#include <time.h>


int temp_x = 0;
int temp_y = 0;

Bot::Bot(const char* filename, int x, int y, const char* obj_type_name, int bit_size) : Tank(filename, x, y, obj_type_name, bit_size) {

	srand(time(0));
	while (Map::viewMap(temp_y, temp_x) != 1 && GameObject::x() < 800 && GameObject::y() < 600) {
		if (temp_x < 800)	temp_x += 16;
		else {
			temp_x = 0;
			temp_y += 16;
		}
	}

	cout << "X is : " << temp_x << "\n";
	cout << "Y is : " << temp_y << "\n";

	route.emplace_back(rand() % 2);
	route.emplace_back(rand() % 5);
	route.emplace_back(rand() % 5);
	route.emplace_back(rand() % 4);

};
Bot::~Bot() {};

void Bot::move_to(int a, int b) {

	a *= 32;
	b *= 32;

	int flag_side = 0;
	int flag_down = 0;

	if (Map::viewMap(GameObject::y() + 65, GameObject::x() + 25) != 0 || Map::viewMap(GameObject::y() + 65, GameObject::x() + 50) != 0)	flag_down = 1;
	if (Map::viewMap(GameObject::y() + 32, GameObject::x() - 10) != 0 || Map::viewMap(GameObject::y() + 32, GameObject::x() + 65) != 0)	flag_side = 1;

	if (GameObject::x() < a-16) {
		rotate(90);
		change_fliptype(SDL_FLIP_NONE);
		GameObject::move_side(1);
		//cout << "Moving right \n";
		//cout << x() << '\n';
	}	
	else if(GameObject::x() > a+16){
		rotate(90);
		change_fliptype(SDL_FLIP_VERTICAL);
		GameObject::move_side(-1);
		//cout << "Moving left \n";
		//cout << x() << '\n';

	}

	if (GameObject::y() < b) {
		GameObject::move_up(1);
		//cout << "Moving down \n";
		//cout << x() << '\n';
	}

	if ((GameObject::x() <= a + 32 && GameObject::x() >= a - 32) && (GameObject::x() <= a + 32 && GameObject::x() >= a - 32)) {

		if (route.size()) {
			cout << "FOUND NEW NODE YAY\n";
			rotate(-1);
			change_fliptype(SDL_FLIP_NONE);
			route.erase(route.begin());
			miss_shoot();
		}
	}

	if (Map::viewMap(GameObject::y() + 70, GameObject::x() + 35) != 0 /*&& Map::viewMap(GameObject::y() + 96, GameObject::x()+65) != 6)*/) {

		/*temp_angle = 0;
		temp_flip2 = SDL_FLIP_NONE;*/
		//miss_shoot();

		if (flag_down) {

			rotate(0);
			change_fliptype(SDL_FLIP_VERTICAL);
		}
		//render_missiles();

		//cout << "Object detected!" << GameObject::y() << "\t" << GameObject::x() <<"\t"<< Map::viewMap(GameObject::y() + 70, GameObject::x() + 35)<<"\n";
	}
}

void Bot::Bot_update() {


	// node 0 is either		:	8C or 16C
	// node 1 is either		:	2G or 6G or 12G or 18G or 22G
	// node 2 is either		:	0J or 5I or 12J or 19I or 24J
	// node 3 is either		:	4T or 8O or 16O or 20T
	// default node 4 is	:	12T

	switch (route.size()) {
	case 4:
		switch (route[0]) {
		case 0: move_to(8,1);
			break;
		case 1: move_to(16,1);
			 break;
		}
		break;
	case 3:
		switch (route[0]) {
		case 0: move_to(2,5);
			break;
		case 1: move_to(6, 5);
			break;
		case 2: move_to(12, 5);
			break;
		case 3: move_to(18, 5);
			break;
		case 4: move_to(22, 5);
			break;
		}
		break;
	case 2:
		switch (route[0]) {
		case 0: move_to(0, 9);
			break;
		case 1: move_to(5, 8);
			break;
		case 2: move_to(12, 9);
			break;
		case 3: move_to(19, 8);
			break;
		case 4: move_to(24, 9);
			break;
		}
		break;
	case 1:
		switch (route[0]) {
		case 0: move_to(4, 19);
			break;
		case 1: move_to(8,14);
			break;
		case 2: move_to(16, 14);
			break;
		case 3: move_to(20,19);
			break;
		}
		break;
	case 0:
		move_to(temp_x/32,temp_y/32);
	}
	render_missiles();
}