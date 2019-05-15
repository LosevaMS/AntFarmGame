#include "Ant.h"
#include "Notifications.h"

Ant::Ant(int X, int Y, int Age) : age(Age), role(""), alive(true), health(200){
	SetRole(false);
	antrole->SetX(X);
	antrole->SetY(Y);
	antrole->SetPosition(antrole->GetX(), antrole->GetY());
	switch (antrole->GetRole()){
	case 0: Map_ants[Y / 85][X / 85] = 'b'; break;
	case 1: Map_ants[Y / 85][X / 85] = 'n'; break;
	case 2: Map_ants[Y / 85][X / 85] = 's'; break;
	case 3: Map_ants[Y / 85][X / 85] = 'f'; break; //food
	case 4: Map_ants[Y / 85][X / 85] = 't'; break; //tree
	}
}
Ant::~Ant(){};
void Ant::SetRole(bool flag){
	int x, y, choice;
	bool move = false;;
	if (flag == true) {
		x = antrole->GetX();
		y = antrole->GetY();
	}
	if (age<15 && role != "baby"){
		role = "baby";
		antrole = new Baby();
		satiety = 10;
	}
	if (age >= 15 && age<25 && role != "nanny"){
		role = "nanny";
		antrole = new Nanny();
		satiety = 20;
		move = true;
		if (flag == true) Map_ants[y / 85][x / 85] = 'n';
	}
	if (age >= 25 && age<50 && role != "soldier"){
		role = "soldier";
		antrole = new Soldier();
		satiety = 30;
		move = true;
		if (flag == true) Map_ants[y / 85][x / 85] = 's';
	}
	if (age >= 50 && age<300 && role != "collector1" && role != "collector2"){
		choice = rand() % 2;
		switch (choice){
		case 0: role = "collector1"; antrole = new Collector1(); break;
		case 1: role = "collector2"; antrole = new Collector2; break;
		}
		satiety = 30;
		move = true;
		if (flag == true){
			switch (choice){
			case 0: Map_ants[y / 85][x / 85] = 'f'; break;
			case 1: Map_ants[y / 85][x / 85] = 't'; break;
			}
		}
	}
	if (age >= 300 && (role != "collector1" || role != "collector2")){
		role = "cleaner";
		antrole = new Cleaner();
		satiety = 40;
		move = true;
		if (flag == true) Map_ants[y / 85][x / 85] = 'c';
	}
	if (flag == true){
		antrole->SetX(x);
		antrole->SetY(y);
		antrole->SetPosition(x, y);
	}
	if (move == true){
		antrole->SetPlace();
	}
}

Sprite Ant::GetSprite(){
	return antrole->GetSprite();
}

void Ant::Move(bool danger){
	antrole->Work(danger);
	Upload();
	SetRole(true);
	if (health <= 0){
		alive = false;
	}
}

void Ant::Upload(){
	age++;
	satiety++;
	if (food == 0) health -= 1;
	if (health <= 0) alive = false;
	if (food>0) food -= 1;
}

void Ant::SetSprite(int choice){
	antrole->SetSprite(choice);
}

bool Ant::GetAlive(){
	return alive;
}

int Ant::GetX(){
	return antrole->GetX();
}

int Ant::GetY(){
	return antrole->GetY();
}

void Ant::SetDead(){
	if (health <= 0) alive = false;
}

void Ant::SetHealth(){
	health -= 100;
}