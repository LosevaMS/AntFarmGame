#include "Notifications.h"

void Notifications::Work1(){
	int r=GetRole();
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 30; j++)
			if (Map_ants[i][j] == 'E'){
				goal_x = j;
				goal_y = i;
			}
	if (goal_x != -1 && goal_y != -1){
		if (r = 2){
			int x = GetX();
			int y = GetY();
			int x1 = x, y1 = y;
			SetPosition(x, y);
			Map_ants[y / 85][x / 85] = 's';
			if (Map_ants[goal_y][goal_x] == 'E'){
				if (x>goal_x * 85  && Map_ants[y / 85][(x - 85) / 85] == '0') { x -= 85;  SetSprite(12); }
				if (x<goal_x * 85  && Map_ants[y / 85][(x + 85) / 85] == '0') { x += 85;  SetSprite(11); }
				if (y<goal_y * 85  && Map_ants[(y + 85) / 85][x / 85] == '0') { y += 85;  }
				if (y>goal_y * 85  && Map_ants[(y - 85) / 85][x / 85] == '0') { y -= 85;  }
				SetX(x);
				SetY(y);
				SetPosition(x, y);
				Map_ants[y / 85][x / 85] = 's';
				Map_ants[y1 / 85][x1 / 85] = '0';
				if (x == goal_x * 85 && y == goal_y * 85) {
					if (Map_ants[y / 85][x / 85] == 'E'  && Map_ants[y / 85][(x - 85) / 85] == '0')
						x-=85;
					if (Map_ants[y / 85][x / 85] == 'E'  && Map_ants[y / 85][(x + 85) / 85] == '0')
						x += 85;
					if (Map_ants[y / 85][x / 85] == 'E'  && Map_ants[(y+1) / 85][x / 85] == '0')
						y += 85;
					if (Map_ants[y / 85][x / 85] == 'E'  && Map_ants[(y - 1) / 85][x / 85] == '0')
						y -= 85;
				}
			}
			else {
				goal_y = -1;
				goal_x = -1;
			}
		}
		if (r != 2){
			int attempts = 0;
			int dir;
			int x = GetX();
			int y = GetY();
			int x1 = x, y1 = y;
			while (attempts != 10){
				dir = rand() % 4;
				switch (dir){
				case 0: x -= 85; break;
				case 1: y -= 85; break;
				case 2: x -= 85; y -= 85; break;
				case 3: x -= 85; y += 85; break;
				}
				if (x >= 0 && y >= 0){
					if ( Map_back[y / 85][x / 85] == 'd') {
						SetX(x);
						SetY(y);
						SetPosition(x, y);
						if (r = 3){
							Map_ants[y / 85][x / 85] = 'f'; 
							SetSprite(5);
						}
						if (r = 4){
							Map_ants[y / 85][x / 85] = 't';
							SetSprite(6);
						}
						if (r = 5){
							Map_ants[y / 85][x / 85] = 'c';
							SetSprite(14);
						}
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