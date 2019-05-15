#include "Collector1.h"


Collector1::Collector1() : Role(3), myfood(100){
	goal_x = -1;
	goal_y = -1;
	food_ant = false;
}
Collector1::~Collector1(){}

void Collector1::SetPlace(){
}

void Collector1::Work(bool danger){
	int x = GetX();
	int y = GetY();
	int x1 = x, y1 = y, attempts = 0, dir;
	if (Map_back[y / 85][x / 85] == 'd' || Map_back[y / 85][x / 85] == 's') place = false;
	if (Map_back[y / 85][x / 85] != 'd' && Map_back[y / 85][x / 85] != 's') place = true;
	if (place == false){
		while (attempts != 10){
			dir = rand() % 5;
			switch (dir){
			case 0: y -= 85; break;
			case 1: x += 85; y -= 85; break;
			case 2: x += 85; break;
			case 3: y += 85; break;
			case 4: x += 85; y += 85; break;
			}
			if (x >= 0 && y >= 0){
				if (Map_back[y / 85][x / 85] == 'g') place = true;
				SetX(x);
				SetY(y);
				SetPosition(x, y);
				Map_ants[y / 85][x / 85] = 'f';
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
	else {
		if (danger == true && (x >= 0 && y >= 0 && x <= 1275 && y <= 1020) == false){
			goal_x = -1;
			goal_y = -1;
			x1 = x; y1 = y;
			attempts = 0;
			while (attempts != 10){
				dir = rand() % 4;
				switch (dir){
				case 0: x -= 85; y -= 85; break;
				case 1: y -= 85; break;
				case 2: x -= 85; break;
				case 3: x -= 85; y += 85; break;
				}
				if (Check(x, y)){
					if (food_ant == false) SetSprite(5);
					if (Map_back[y / 85][x / 85] == 'c') SetSprite(1);
					if (Map_back[y / 85][x / 85] == 'p') SetSprite(0);
					SetX(x);
					SetY(y);
					SetPosition(x, y);
					Map_ants[y / 85][x / 85] = 'f';
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
		else {
			if (food_ant == false){ //поиск еды
				bool flag = false;
				if (goal_y == -1 && goal_x == -1){
					bool flag = false;
					for (int i = 1; i <= 8; i++){
						x1 = x; y1 = y;
						for (int j = 1; j <= 5; j++){
							if (flag == false){
								switch (i){
								case 1: y1 -= 85; break;
								case 2: x1 -= 85; break;
								case 3: x1 += 85; break;
								case 4: y1 += 85; break;
								case 5: y1 -= 85; x1 -= 85; break;
								case 6: y1 += 85; x1 -= 85; break;
								case 7: y1 -= 85; x1 += 85; break;
								case 8: y1 += 85; x1 += 85; break;
								}
								if (x1 >= 0 && y1 >= 0 && x1 <= 2465 && y1 <= 1275){
									if (((Map_back[y1 / 85][x1 / 85] == 'p' || Map_back[y1 / 85][x1 / 85] == 'c') && danger == false) || ((Map_back[y1 / 85][x1 / 85] == 'p' || Map_back[y1 / 85][x1 / 85] == 'c') && x1 <= 1275 && danger == true)){
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
							if ((Check(x, y) && danger == false) || ((Check1(x, y) && danger == true))){
								if (dir == 0 || dir == 3 || dir == 5) SetSprite(5);
								if (dir == 2 || dir == 4 || dir == 7) SetSprite(2);
								SetX(x);
								SetY(y);
								SetPosition(x, y);
								Map_ants[y / 85][x / 85] = 'f';
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
					if (Map_back[goal_y][goal_x] == 'p' || Map_back[goal_y][goal_x] == 'c'){
						if (x>goal_x * 85 && flag == false && Map_ants[y / 85][(x - 85) / 85] == '0') { x -= 85; flag = true; SetSprite(5); }
						if (x<goal_x * 85 && flag == false && Map_ants[y / 85][(x + 85) / 85] == '0') { x += 85; flag = true; SetSprite(2); }
						if (y<goal_y * 85 && flag == false && Map_ants[(y + 85) / 85][x / 85] == '0') { y += 85; flag = true; }
						if (y>goal_y * 85 && flag == false && Map_ants[(y - 85) / 85][x / 85] == '0') { y -= 85; flag = true; }
						SetX(x);
						SetY(y);
						SetPosition(x, y);
						Map_ants[y / 85][x / 85] = 'f';
						Map_ants[y1 / 85][x1 / 85] = '0';
						if (x == goal_x * 85 && y == goal_y * 85) {
							if (Map_back[y / 85][x / 85] == 'c') SetSprite(1);
							if (Map_back[y / 85][x / 85] == 'p') SetSprite(0);
							Map_back[y / 85][x / 85] = 'g';
							goal_y = -1;
							goal_x = -1;
							food_ant = true;
						}
					}
					else {
						goal_y = -1;
						goal_x = -1;
					}
				}

			}
			else { //уже нашел ветку
				x1 = x;
				y1 = y;
				while (attempts != 10){
					dir = rand() % 4;
					switch (dir){
					case 0: x -= 85; break;
					case 1: y -= 85; break;
					case 2: x -= 85; y -= 85; break;
					case 3: x -= 85; y += 85; break;
					}
					if (x >= 0 && y >= 0){
						if (Map_back[y / 85][x / 85] == 's' || Map_back[y / 85][x / 85] == 'd') {
							SetSprite(2);
							branches += myfood;
							myfood = 1;
							food_ant = false;
							break;
						}
						if ((Check(x, y) && danger == false) || (Check1(x, y) && danger == true)){
							if (Map_back[y / 85][x / 85] == 'p' || Map_back[y / 85][x / 85] == 'c'){
								myfood++;
								Map_back[y / 85][x / 85] = 'g';
							}
							SetX(x);
							SetY(y);
							SetPosition(x, y);
							Map_ants[y / 85][x / 85] = 'f';
							Map_ants[y1 / 85][x1 / 85] = '0';
							break;
						}
						x = x1;
						y = y1;
						attempts++;
					}
					else {
						x = x1;
						y = y1;
						attempts++;
					}
				}
			}
		}
	}
}

bool Collector1::Check(int X, int Y){
	if (X >= 0 && Y >= 0 && X <= 2465 && Y <= 1275 && (Map_back[Y / 85][X / 85] == 'g' || Map_back[Y / 85][X / 85] == 'p' || Map_back[Y / 85][X / 85] == 'c' || Map_back[Y / 85][X / 85] == 'b') && Map_ants[Y / 85][X / 85] == '0') return true;
	return false;
}
bool Collector1::Check1(int X, int Y){
	if (X >= 0 && Y >= 0 && X <= 1275 && Y <= 1275 && (Map_back[Y / 85][X / 85] == 'g' || Map_back[Y / 85][X / 85] == 'p' || Map_back[Y / 85][X / 85] == 'c' || Map_back[Y / 85][X / 85] == 'b') && Map_ants[Y / 85][X / 85] == '0') return true;
	return false;
}