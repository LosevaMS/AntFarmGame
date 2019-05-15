#include "Nanny.h"

Nanny::Nanny() : Role(1){}
Nanny::~Nanny(){}

void Nanny::Work(bool danger){
	int dir = 0;
	int x = GetX();
	int y = GetY();
	while (dir<8){
		if (ifPampers(dir, x, y)){
			break;
		}
		dir++;
	}
	if (dir == 8){
		int x1 = x, y1 = y;
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
				if (dir == 0 || dir == 3 || dir == 5) SetSprite(9);
				if (dir == 2 || dir == 4 || dir == 7) SetSprite(10);
				SetX(x);
				SetY(y);
				SetPosition(x, y);
				Map_ants[y / 85][x / 85] = 'n';
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

bool Nanny::Check(int X, int Y){
	if (X >= 0 && Y >= 0 && Map_back[Y / 85][X / 85] == 'd' && Map_ants[Y / 85][X / 85] == '0') return true;
	return false;
}

bool Nanny::ifPampers(int dir, int x, int y){
	bool flag = false;
	switch (dir){
	case 0: if (x - 85 >= 0 && y - 85 >= 0 && Map_back[(y - 85) / 85][(x - 85) / 85] == 's'){
		flag = true;
		Map_back[(y - 85) / 85][(x - 85) / 85] = 'd';
		Map_ants[(y - 85) / 85][(x - 85) / 85] = 'n';
		Map_ants[y / 85][x / 85] = '0';
		x -= 85;
		y -= 85;
		break;
	}
	case 1: if (y - 85 >= 0 && Map_back[(y - 85) / 85][x / 85] == 's'){
		flag = true;
		Map_back[(y - 85) / 85][x / 85] = 'd';
		Map_ants[(y - 85) / 85][x / 85] = 'n';
		Map_ants[y / 85][x / 85] = '0';
		y -= 85;
		break;
	}
	case 2: if (y - 85 >= 0 && Map_back[(y - 85) / 85][(x + 85) / 85] == 's'){
		flag = true;
		Map_back[(y - 85) / 85][(x + 85) / 85] = 'd';
		Map_ants[(y - 85) / 85][(x + 85) / 85] = 'n';
		Map_ants[y / 85][x / 85] = '0';
		x += 85;
		y -= 85;
		break;
	}
	case 3: if (x - 85 >= 0 && Map_back[y / 85][(x - 85) / 85] == 's'){
		flag = true;
		Map_back[y / 85][(x - 85) / 85] = 'd';
		Map_ants[y / 85][(x - 85) / 85] = 'n';
		Map_ants[y / 85][x / 85] = '0';
		x -= 85;
		break;
	}
	case 4: if (Map_back[y / 85][(x + 85) / 85] == 's'){
		flag = true;
		Map_back[y / 85][(x + 85) / 85] = 'd';
		Map_ants[y / 85][(x + 85) / 85] = 'n';
		Map_ants[y / 85][x / 85] = '0';
		x += 85;
		break;
	}
	case 5: if (x - 85 >= 0 && Map_back[(y + 85) / 85][(x - 85) / 85] == 's'){
		flag = true;
		Map_back[(y + 85) / 85][(x - 85) / 85] = 'd';
		Map_ants[(y + 85) / 85][(x - 85) / 85] = 'n';
		Map_ants[y / 85][x / 85] = '0';
		x -= 85;
		y += 85;
		break;
	}
	case 6: if (Map_back[(y + 85) / 85][x / 85] == 's'){
		flag = true;
		Map_back[(y + 85) / 85][x / 85] = 'd';
		Map_ants[(y + 85) / 85][x / 85] = 'n';
		Map_ants[y / 85][x / 85] = '0';
		y += 85;
		break;
	}
	case 7: if (Map_back[(y + 85) / 85][(x + 85) / 85] == 's'){
		flag = true;
		Map_back[(y + 85) / 85][(x + 85) / 85] = 'd';
		Map_ants[(y + 85) / 85][(x + 85) / 85] = 'n';
		Map_ants[y / 85][x / 85] = '0';
		x += 85;
		y += 85;
		break;
	}
	}
	if (flag == true){
		if (dir == 0 || dir == 3 || dir == 5) SetSprite(9);
		if (dir == 2 || dir == 4 || dir == 7) SetSprite(10);
		SetX(x);
		SetY(y);
		SetPosition(x, y);
		return true;
	}
	return false;
}

void Nanny::SetPlace(){

}
