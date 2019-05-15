#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

extern std::string Map_back[16];
extern std::string Map_ants[16];

class Enemy{
public:
	Enemy(int X, int Y);
	~Enemy();
	void Destroy();
	void SetPosition(int X, int Y);
	void Upload();
	Sprite GetSprite();
	void SetSprite(int choice);
	void SetX(int X);
	int GetX();
	void SetY(int Y);
	int GetY();
	bool Check(int X, int Y);
private:
	int x, y;
	int goal_x;
	int goal_y;
	int ant_x;
	int ant_y;
	int cnt=0;//для лимита ударов при атаке
	bool branch_food_ant;
	bool alive;
	int satiety;
	Sprite sprite;
	Texture texture;
};
