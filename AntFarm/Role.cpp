#include "Role.h"


Role::Role(int r) : role(r){
	std::string s;
	switch (r){
	case 0: s = "baby"; break;
	case 1: s = "nanny"; break;
	case 2: s = "soldier"; break;
	case 3: s = "collector1"; break;
	case 4: s = "collector2"; break;
	case 5: s = "cleaner"; break;
	}
	texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/" + s + "_r.png");
	sprite.setTexture(texture);
}

Role::~Role(){}

void Role::SetSprite(int choice){
	switch (choice){
	case 0: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/col_pizza.png"); break;
	case 1: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/col_burger.png"); break;
	case 2: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/collector1_r.png"); break;
	case 3: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/col_branch.png"); break;
	case 4: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/collector2_r.png"); break;
	case 5: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/collector1_l.png"); break;
	case 6: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/collector2_l.png"); break;
	case 7: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/baby_l.png"); break;
	case 8: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/baby_r.png"); break;
	case 9: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/nanny_l.png"); break;
	case 10: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/nanny_r.png"); break;
	case 11: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/soldier_r.png"); break;
	case 12: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/soldier_l.png"); break;
	case 13: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/cleaner_l.png"); break;
	case 14: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/cleaner_r.png"); break;
	}
	sprite.setTexture(texture);
}

Sprite Role::GetSprite(){
	return sprite;
}

void Role::SetX(int X){
	x = X;
}

int Role::GetX(){
	return x;
}

void Role::SetY(int Y){
	y = Y;
}

int Role::GetY(){
	return y;
}

void Role::SetPosition(int X, int Y){
	sprite.setPosition(X, Y);
}

int Role::GetRole(){
	return role;
}
