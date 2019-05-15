#include "Antfarm.h"

AntFarm::AntFarm() : number(0), max_food(50), max_number(30), n(9), m(8){}

void AntFarm::AddAnt(Ant ant){
	ants.push_back(&ant);
	number++;
}

void AntFarm::Live(){
	bool danger;
	std::list<Ant*>::iterator it;
	for (it = ants.begin(); it != ants.end(); it++){
		(*it)->Move(danger);
	}
}


