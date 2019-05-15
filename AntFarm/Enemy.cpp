#include "Enemy.h"

Enemy::Enemy(int X, int Y):x(X),y(Y) {
	goal_x = -1;
	goal_y = -1;
	ant_x = -1; ant_y = -1;
	texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/kira_r.png");
	sprite.setTexture(texture);
	SetPosition(x, y);
	branch_food_ant = false;
}
Enemy::~Enemy(){};
void Enemy::Destroy(){
	int x = GetX();
	int y = GetY();
	int x1 = x, y1 = y, attempts = 0, dir;
	//уничтожение муравьев
	bool ant_flag = false;
	if (ant_y == -1 && ant_x == -1){
		bool ant_flag1 = false;
		for (int i = 1; i <= 4; i++){
			x1 = x; y1 = y;
			for (int j = 1; j <= 4; j++){
				if (ant_flag1 == false){
					switch (i){
					case 1: y1 -= 85; break;
					case 2: x1 -= 85; break;
					case 3: x1 += 85; break;
					case 4: y1 += 85; break;
					}
					if (x1 >= 0 && y1 >= 0 && x1 <= 2465 && y1 <= 1275){
						if (Map_ants[y1 / 85][x1 / 85] != '0' && Map_ants[y1 / 85][x1 / 85] != 'E'){
							ant_x = x1 / 85;
							ant_y = y1 / 85;
							ant_flag1 = true;
						}
					}
				}
			}
		}
		x1 = x; y1 = y;
		if (ant_flag1 == false){
			x1 = x; y1 = y;
			while (attempts != 10){
				dir = rand() % 8;
				switch (dir){
				case 0: x -= 85; y -= 85; break;
				case 1: y -= 85; break;
				case 2: x += 85; y -= 85; break;
				case 3: x -= 85; break;
				case 4: x += 85; break;
				case 5: x -= 85; y += 85; break;
				case 6: y += 85; break;
				case 7: x += 85; y += 85; break;
				}
				if (Check(x, y)){
					SetSprite(11);
					SetX(x);
					SetY(y);
					SetPosition(x, y);
					Map_ants[y / 85][x / 85] = 'E';
					Map_ants[y1 / 85][x1 / 85] = '0';
					break;
				}
				else {
					x = x1;
					y = y1;
					attempts++;
				}
			}
		}
	}
	if (ant_y != -1 && ant_x != -1){
		if (Map_ants[ant_y][ant_x] != '0' && Map_ants[ant_y][ant_x] != 'E'){
			if (x>ant_x * 85 && ant_flag == false && Map_ants[y / 85][(x - 85) / 85] == '0') { x -= 85; ant_flag = true; SetSprite(11); }
			if (x<ant_x * 85 && ant_flag == false && Map_ants[y / 85][(x + 85) / 85] == '0') { x += 85; ant_flag = true; SetSprite(11); }
			if (y<ant_y * 85 && ant_flag == false && Map_ants[(y + 85) / 85][x / 85] == '0') { y += 85; ant_flag = true; }
			if (y>ant_y * 85 && ant_flag == false && Map_ants[(y - 85) / 85][x / 85] == '0') { y -= 85; ant_flag = true; }

			if (x == ant_x * 85 && y == ant_y * 85) {
				if (Map_ants[y / 85][x / 85] != '0'){
					x -= 85;
				}
				else {
					x = x1;
					y = y1;
				}
				if (Map_ants[y / 85][x / 85] != '0'){
					x += 85;
				}
				else {
					x = x1;
					y = y1;
				}
				if (Map_ants[y / 85][x / 85] != '0'){
					y += 85;
				}
				else {
					x = x1;
					y = y1;
				}
				if (Map_ants[y / 85][x / 85] != '0'){
					y -= 85;
				}
				else {
					x = x1;
					y = y1;
				}
			}
			SetX(x);
			SetY(y);
			SetPosition(x, y);
			Map_ants[y / 85][x / 85] = 'E';
			Map_ants[y1 / 85][x1 / 85] = '0';
			
		}
		else {
			ant_x = -1;
			ant_y = -1;
		}
	}
	//уничтожение веток и еды
	bool flag = false;
	while (ant_flag == false){
		if (goal_y == -1 && goal_x == -1){
			bool flag = false;
			for (int i = 1; i <= 4; i++){
				x1 = x; y1 = y;
				for (int j = 1; j <= 4; j++){
					if (flag == false){
						switch (i){
						case 1: y1 -= 85; break;
						case 2: x1 -= 85; break;
						case 3: x1 += 85; break;
						case 4: y1 += 85; break;
						}
						if (x1 >= 0 && y1 >= 0 && x1 <= 2465 && y1 <= 1275){
							if (Map_back[y1 / 85][x1 / 85] == 'b' || Map_back[y1 / 85][x1 / 85] == 'c' || Map_back[y1 / 85][x1 / 85] == 'p'){
								goal_x = x1 / 85;
								goal_y = y1 / 85;
								flag = true;
							}
						}
					}
				}
			}
			x1 = x; y1 = y;
			if (flag == false){
				x1 = x; y1 = y;
				while (attempts != 10){
					dir = rand() % 8;
					switch (dir){
					case 0: x -= 85; y -= 85; break;
					case 1: y -= 85; break;
					case 2: x += 85; y -= 85; break;
					case 3: x -= 85; break;
					case 4: x += 85; break;
					case 5: x -= 85; y += 85; break;
					case 6: y += 85; break;
					case 7: x += 85; y += 85; break;
					}
					if (Check(x, y)){
						SetSprite(11);
						SetX(x);
						SetY(y);
						SetPosition(x, y);
						Map_ants[y / 85][x / 85] = 'E';
						Map_ants[y1 / 85][x1 / 85] = '0';
						break;
					}
					else {
						x = x1;
						y = y1;
						attempts++;
					}
				}
			}
		}
		if (goal_y != -1 && goal_x != -1){
			if (Map_back[goal_y][goal_x] == 'b' || Map_back[goal_y][goal_x] == 'c' || Map_back[goal_y][goal_x] == 'p'){
				if (x > goal_x * 85 && flag == false && Map_ants[y / 85][(x - 85) / 85] == '0') { x -= 85; flag = true; SetSprite(11); }
				if (x < goal_x * 85 && flag == false && Map_ants[y / 85][(x + 85) / 85] == '0') { x += 85; flag = true; SetSprite(11); }
				if (y < goal_y * 85 && flag == false && Map_ants[(y + 85) / 85][x / 85] == '0') { y += 85; flag = true; }
				if (y > goal_y * 85 && flag == false && Map_ants[(y - 85) / 85][x / 85] == '0') { y -= 85; flag = true; }
				SetX(x);
				SetY(y);
				SetPosition(x, y);
				Map_ants[y / 85][x / 85] = 'E';
				Map_ants[y1 / 85][x1 / 85] = '0';
				if (x == goal_x * 85 && y == goal_y * 85) {
					//SetSprite(11);
					Map_back[y / 85][x / 85] = 'g';
					goal_y = -1;
					goal_x = -1;
					branch_food_ant = false;
				}
			}
			else {
				goal_y = -1;
				goal_x = -1;
			}
		}
		break;
	}
}
Sprite Enemy::GetSprite(){
	return sprite;
}
void Enemy::SetSprite(int choice){
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
	case 11: texture.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/kira_r.png"); break;
	}
	sprite.setTexture(texture);
}

void Enemy::Upload(){
	satiety++;
}
void Enemy::SetPosition(int X, int Y){
	sprite.setPosition(X, Y);
}
void Enemy::SetX(int X){
	x = X;
}

int Enemy::GetX(){
	return x;
}

void Enemy::SetY(int Y){
	y = Y;
}

int Enemy::GetY(){
	return y;
}
bool Enemy::Check(int X, int Y){
	if (X / 85 < 0 || Y / 85 < 0 || Y / 85>15 || X / 85>29) return false;
	if ((Map_back[Y / 85][X / 85] == 'd' || Map_back[Y / 85][X / 85] == 'g') && Map_ants[Y / 85][X / 85] == '0') return true;
	return false;
}