#include "Tank.h"

 Tank::Tank(const char* filename, int x, int y, const char* obj_type_name, int bit_size) : GameObject(filename, x, y, obj_type_name, bit_size) {
	  // flag = 0;
	 temp_angle = -1;
	 missile_count = 0;
	 temp_flip2 = SDL_FLIP_NONE;
	 //missiles = vector<GameObject*> (_max_missile_count, nullptr);
 }



 void Tank::render_missiles() {


	while (missiles.size() - missile_count) {

		
		missiles.push_back(new GameObject("assets/misile.png", x() + 32, y() + 32, "MISSILE", 32));
		if (missiles.back())	cout << missiles.back() << "Missile rendered\n";

		temp_flip2 = flip();
		temp_angle = get_angle();
		 
		missiles.back()->rotate(temp_angle);
		missiles.back()->change_fliptype(temp_flip2);
		
	}


	 for (int i = 0; i < missiles.size(); i++) {

		

		 if (missiles[i]->get_angle() == 0) {
			 
			  //cout<<"shooting vertically";
			 if (missiles[i]->flip() == SDL_FLIP_NONE) {
				
				 if (Map::viewMap(missiles[i]->y(), missiles[i]->x()) == 0 && missiles[i]->y() > 0 && missiles[i]->y() < 640) {
					 missiles[i]->move_up(-5);
					 missiles[i]->render();
				 }
				 else {
					 missiles[i]->die();
					 cout << missiles[i] << "missile died.\n";
					 delete(missiles[i]);
					 missiles[i] = nullptr;
					 miss_poof();
				 }
			 }
			 else if (missiles[i]->flip() == SDL_FLIP_VERTICAL) {
				 
				 if (Map::viewMap(missiles[i]->y(), missiles[i]->x()) == 0 && missiles[i]->y() > 0 && missiles[i]->y() < 640) {
					 missiles[i]->move_up(5);
					 missiles[i]->render();
				 }
				 else {
					 missiles[i]->die();
					 cout << missiles[i]<<"missile died.\n";
					 delete(missiles[i]);
					 missiles[i] = nullptr;
					 miss_poof();
				 }
			 }
		 }

		 else if (missiles[i]->get_angle() == 90) {

			 //cout << "shooting sideways!\n";
			 if (missiles[i]->flip() == SDL_FLIP_NONE) {

				 if (Map::viewMap(missiles[i]->y(), missiles[i]->x()) == 0 && missiles[i]->x() > 0 && missiles[i]->x() < 800) {
					 missiles[i]->move_side(5);
					 missiles[i]->render();
				 }
				 else {
					 missiles[i]->die();
					 cout << missiles[i] << "missile died.\n";
					 delete(missiles[i]);
					 missiles[i] = nullptr;
					 miss_poof();
				 }
			 }
			 else if (missiles[i]->flip() == SDL_FLIP_VERTICAL) {
				 

				 if (Map::viewMap(missiles[i]->y(), missiles[i]->x()) == 0 && missiles[i]->x() > 0 && missiles[i]->x() < 800) {
					 missiles[i]->move_side(-5);
					 missiles[i]->render();
				 }
				 else {
					 missiles[i]->die();
					 cout << missiles[i] << "missile died.\n";
					 delete(missiles[i]);
					 missiles[i] = nullptr;
					 miss_poof();
				 }
			 }
		 }
	 }


	 for (int i = 0; i< missiles.size(); i++) {
		if (missiles[i] == nullptr) {
			 missiles.erase(missiles.begin() + i);
		 }
	 }
 }