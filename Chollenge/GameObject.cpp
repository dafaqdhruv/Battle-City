#include "GameObject.h"
#include <string.h>

GameObject::GameObject(const char* filename, int x, int y, const char* obj_type_name, int bit_size) {
	angle = 0;
	fliptype = SDL_FLIP_NONE;
	tempX = tempY = 0;
	SrcRect.x = SrcRect.y = 0;
	SrcRect.h = SrcRect.w = 32;
	DestRect.h = DestRect.w = bit_size;

	obj_type = std::string(obj_type_name);

	ObjTex = TextureManager::LoadTexture(filename);
	if (ObjTex) { cout << "TextureLoaded!\n"; }
	xpos = DestRect.x = x;
	ypos = DestRect.y = y;

	cout << obj_type << endl;
}

void GameObject::move_up(int a) {
	ypos += a;
	DestRect.y = ypos;
}

void GameObject::move_side(int a) {
	xpos += a;
	DestRect.x = xpos;
}

void GameObject::render() {
	TextureManager::Draw(ObjTex, SrcRect, DestRect, angle, fliptype);
}

void GameObject::limit() {


	if (x() > 800 - 64)	xpos = 800 - 64;
	if (x() < 0)	xpos = 0;
	if (y() > 640 - 64)	ypos = 640 - 64;
	if (y() < 0)	ypos = 0;
	//if (Map::viewMap((y()+32)/32, (x()+32) / 32) != 0 && Map::viewMap((y() + 32) / 32, (x() + 32) / 32) != 6) {
	//	xpos = tempX;
	//	ypos = tempY;
		//cout << "THEFOQ\t"<<x()<<endl;
	//}
	if (Map::viewMap(y() + 64, x() + 32) != 0 && Map::viewMap(y() + 64, x() + 32) != 6)
		ypos = tempY;

	if (Map::viewMap(y(), (x() + 32)) != 0 && Map::viewMap(y(), (x() + 32)) != 6)
		ypos = tempY;

	if (Map::viewMap(y(), (x() + 64)) != 0 && Map::viewMap(y(), (x() + 64)) != 6)
		xpos = tempX;

	if (Map::viewMap(y(), (x())) != 0 && Map::viewMap(y(), (x())) != 6)
		xpos = tempX;
}

void GameObject::copy() {
	tempX = xpos;
	tempY = ypos;
}

void GameObject::die() {
	Map::modify_map(y() / 32, x() / 32, 0);
}

//int angle = -1;
//SDL_RendererFlip temp_flip = SDL_FLIP_NONE;