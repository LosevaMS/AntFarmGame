#include "Baby.h"

Baby::Baby() : Role(0){}
Baby::~Baby(){}
void Baby::Work(bool danger){
	int x = GetX();
	int y = GetY();
	int x1 = x, y1 = y;
	int dir, choice = rand() % 9;
	int attempts = 0;
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
			if (dir == 0 || dir == 3 || dir == 5) SetSprite(7);
			if (dir == 2 || dir == 4 || dir == 7) SetSprite(8);
			SetX(x);
			SetY(y);
			SetPosition(x, y);
			Map_ants[y / 85][x / 85] = 'b';
			Map_ants[y1 / 85][x1 / 85] = '0';
			if (choice == 1) Map_back[y1 / 85][x1 / 85] = 's';
			break;
		}
		else {
			x = x1;
			y = y1;
			attempts++;
		}
	}
}
bool Baby::Check(int X, int Y){
	if (X >= 0 && Y >= 0 && Map_back[Y / 85][X / 85] == 'd' && Map_ants[Y / 85][X / 85] == '0') return true;
	return false;
}

void Baby::SetPlace(){

}
