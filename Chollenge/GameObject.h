#pragma once
#ifndef GameObject_h
#include "Map.h"
#include "TextureManager.h"
#include <vector>

class GameObject {
public:
	GameObject(const char* filename, int x, int y, const char* obj_type_name, int bit_size);
	~GameObject() {};
	std::string obj_type;
	int x() { return xpos; }
	int y() { return ypos; }
	SDL_RendererFlip flip() { return fliptype; }
	double get_angle() { return angle; }
	void move_up(int a);
	void move_side(int a);
	void rotate(double a) { angle = a; }
	void change_fliptype(SDL_RendererFlip a) { fliptype = a; }
	void limit();
	//void fire_missile();
	void copy();
	void die();
	void render();
	int obj;

private:
	int xpos;
	int ypos;
	double angle;
	int tempX, tempY;
	SDL_RendererFlip fliptype;
	SDL_Texture* ObjTex;
	SDL_Rect SrcRect, DestRect;
};

#endif // !GameObject_h
