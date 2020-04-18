#include <sstream>
#include "Game.h"
//#include "gameobject.h"
//#include "map.h"
//#include "texturemanager.h"
#include "Tank.h"
#include "bot.h"

//int flag = 0;
Map* map = nullptr;
Bot* Bot1 = nullptr;
Bot* Bot2 = nullptr;
Tank* Player = nullptr;
//GameObject* Trophy = nullptr;
GameObject* missile = nullptr;
GameObject* missile2 = nullptr;

SDL_Renderer* Game::Renderer = nullptr;

void fire_missile(GameObject* Player);

Game::Game() { running = true; Window = nullptr; Renderer = nullptr; }
Game::~Game() {}

void Game::Init(const char* Title, int xpos, int ypos, int width, int height, bool fullscreen) {
	//cout << "yo\n";
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "SubSystems Initialized\n";
		Uint32 full = 0;
		if (fullscreen) full = SDL_WINDOW_FULLSCREEN;

		Window = SDL_CreateWindow(Title, xpos, ypos, width, height, full);
		if (Window)	cout << "Window Created! \n";
		Renderer = SDL_CreateRenderer(Window, -1, 0);
		if (Renderer) {
			SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
			cout << "Renderer Created! \n";
		}
		running = true;

		map = new Map();
		Bot1 = new Bot("assets/enemy.png", 0, 0, "ENEMY", 64);
		Bot2 = new Bot("assets/enemy.png", 550, 0, "ENEMY", 64);
		Player = new Tank("assets/Tank.png", 384, 320, "PLAYER", 64);
		//Trophy = new GameObject("assets/trophy.png", 384, 608, "TROPHY",32);
		//missile2 = new GameObject("assets/misile.png", 384, 500, "MISSILE", 32);
	}
	else running = false;
}

void Game::update() {
	Player->limit();
	Player->copy();
	Bot1->limit();
	Bot1->copy();
	Bot2->limit();
	Bot2->copy();
	Bot1->Bot_update();
	Bot2->Bot_update();
}

void Game::render() {
	SDL_RenderClear(Renderer);
	map->DrawMap();

	Player->render_missiles();
	Player->render();
	//->render();
	Bot1->render();
	Bot2->render();
	//missile2->render();
	map->render_Grass();
	SDL_RenderPresent(Renderer);
}

void Game::handle_events() {
	SDL_Event event;
	SDL_PollEvent(&event);
	SDL_RendererFlip fliptype = SDL_FLIP_NONE;

	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_ESCAPE]) {
		running = false;
	}
	if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) {
		Player->move_up(-2);
		Player->rotate(0);
		Player->change_fliptype(SDL_FLIP_NONE);
	}
	if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]) {
		Player->move_up(2);
		Player->rotate(0);
		Player->change_fliptype(SDL_FLIP_VERTICAL);
	}
	if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) {
		Player->move_side(-2);
		Player->rotate(90);
		Player->change_fliptype(SDL_FLIP_VERTICAL);
	}
	if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) {
		Player->move_side(2);
		Player->rotate(90);
		Player->change_fliptype(SDL_FLIP_NONE);
	}
	//if (state[SDL_SCANCODE_SPACE])
	//	fire_missile(Player);

	std::stringstream ss;

	switch (event.type) {
	case SDL_QUIT:	running = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.scancode) {
		case SDL_SCANCODE_SPACE:
			if (Player->miss_num() < _max_missile_count) {
				Player->miss_shoot();
			}
			break;
		}
	case SDL_MOUSEMOTION:
		int mouseX = event.motion.x;
		int mouseY = event.motion.y;

		ss << "X: " << mouseX << " Y: " << mouseY;

		SDL_SetWindowTitle(Window, ss.str().c_str());
		break;
	/*default:
		break;	*///		switch(event.key.keysym.scancode){
	}
}

void Game::clean() {
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
	cout << "Everything Cleaned. Thank you!\n";
}

/*
void fire_missile(GameObject* Player) {
	cout << Player->x() << "\t" << Player->y()<<endl;
	missile = new GameObject("assets/misile.png", Player->x() + 32, Player->y() + 32, "MISSILE", 32);
	cout << missile->x() << "\t" << missile->y()<<endl;
	missile->render();
	while (Map::viewMap(missile->x() / 32, missile->y() / 32) == 0) {
		missile->move_up(5);
		missile->render();
	}
	delete(missile);
}
*/

static double angle = -1;
static SDL_RendererFlip temp_flip = SDL_FLIP_NONE;
//
//void fire_missile(GameObject* tank) {
//	if (angle == -1) {
//		temp_flip = tank->flip();
//		angle = tank->get_angle();
//		cout << "APploied\n";
//	}
//
//	if (missile == nullptr) {
//		missile = new GameObject("assets/misile.png", tank->x() + 32, tank->y() + 32, "MISSILE", 32);
//		missile->render();
//	}
//
//	missile->rotate(angle);
//	missile->change_fliptype(temp_flip);
//
//	if (angle == 0) {
//		//cout<<"shooting vertically";
//		if (temp_flip == SDL_FLIP_NONE) {
//			//	missile->change_fliptype(SDL_FLIP_NONE);
//
//			if (Map::viewMap(missile->y(), missile->x()) == 0 && missile->y() > 0 && missile->y() < 640) {
//				missile->move_up(-5);
//				missile->render();
//			}
//			else {
//				//flag = 0;
//				missile->die();
//				cout << "\nmissile  died\n";
//				angle = -1;
//				temp_flip = SDL_FLIP_NONE;
//				delete(missile);
//				missile = nullptr;
//			}
//		}
//		else if (temp_flip == SDL_FLIP_VERTICAL) {
//			//missile->change_fliptype(SDL_FLIP_VERTICAL);
//
//			if (Map::viewMap(missile->y(), missile->x()) == 0 && missile->y() > 0 && missile->y() < 640) {
//				missile->move_up(5);
//				missile->render();
//			}
//			else {
//				flag = 0;
//				missile->die();
//				cout << "\nmissile  died\n";
//				angle = -1;
//				temp_flip = SDL_FLIP_NONE;
//				delete(missile);
//				missile = nullptr;
//			}
//		}
//	}
//
//	else if (angle == 90) {
//		//cout << "shooting sideways!\n";
//		if (temp_flip == SDL_FLIP_NONE) {
//			missile->change_fliptype(temp_flip);
//
//			if (Map::viewMap(missile->y(), missile->x()) == 0 && missile->x() > 0 && missile->x() < 800) {
//				missile->move_side(5);
//				missile->render();
//			}
//			else {
//				flag = 0;
//				missile->die();
//				cout << "\nmissile  died\n";
//				angle = -1;
//				temp_flip = SDL_FLIP_NONE;
//				delete(missile);
//				missile = nullptr;
//			}
//		}
//		else if (temp_flip == SDL_FLIP_VERTICAL) {
//			//missile->change_fliptype(temp_flip);
//
//			if (Map::viewMap(missile->y(), missile->x()) == 0 && missile->x() > 0 && missile->x() < 800) {
//				missile->move_side(-5);
//				missile->render();
//			}
//			else {
//				flag = 0;
//				missile->die();
//				//cout << "WHy ois not null?";
//				cout << "\nmissile  died\n";
//				angle = -1;
//				temp_flip = SDL_FLIP_NONE;
//				delete(missile);
//				missile = nullptr;
//			}
//		}
//	}
//}