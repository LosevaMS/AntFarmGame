#include "Soldier.h"

Soldier::Soldier() : Role(2), place(false){
	goal_x = -1;
	goal_y = -1;
}
Soldier::~Soldier(){}

void Soldier::Work(bool danger){
	int x = GetX();
	int y = GetY();
	int x1 = x, y1 = y;
	int dir;
	int attempts = 0;

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 30; j++)
			if (Map_ants[i][j] == 'E'){
				goal_x = j;
				goal_y = i;
			}
	if (goal_x == -1 && goal_y == -1){
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
				if (dir == 0 || dir == 3 || dir == 5) SetSprite(12);
				if (dir == 2 || dir == 4 || dir == 7) SetSprite(11);
				SetX(x);
				SetY(y);
				SetPosition(x, y);
				Map_ants[y / 85][x / 85] = 's';
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
	if (goal_x != -1 && goal_y != -1){
		if (Map_ants[goal_y][goal_x] == 'E'){
			if (x>goal_x * 85 && Map_ants[y / 85][(x - 85) / 85] == '0') { x -= 85;  SetSprite(12); }
			if (x<goal_x * 85 && Map_ants[y / 85][(x + 85) / 85] == '0') { x += 85;  SetSprite(11); }
			if (y<goal_y * 85 && Map_ants[(y + 85) / 85][x / 85] == '0') { y += 85; }
			if (y>goal_y * 85 && Map_ants[(y - 85) / 85][x / 85] == '0') { y -= 85; }
			SetX(x);
			SetY(y);
			SetPosition(x, y);
			Map_ants[y / 85][x / 85] = 's';
			Map_ants[y1 / 85][x1 / 85] = '0';
			if (x == goal_x * 85 && y == goal_y * 85) {
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
						if (dir == 0 || dir == 3 || dir == 5) SetSprite(12);
						if (dir == 2 || dir == 4 || dir == 7) SetSprite(11);
						SetX(x);
						SetY(y);
						SetPosition(x, y);
						Map_ants[y / 85][x / 85] = 's';
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
		else {
			goal_y = -1;
			goal_x = -1;
		}
	}
}

bool Soldier::Check(int X, int Y){
	if (X >= 0 && Y >= 0 && X <= 2465 && Y <= 1275 && Map_ants[Y / 85][X / 85] == '0' && (Map_back[Y / 85][X / 85] == 'g' || Map_back[Y / 85][X / 85] == 'd')) return true;
	return false;
}

void Soldier::SetPlace(){
}