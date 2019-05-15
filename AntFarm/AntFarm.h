#pragma once
#include "Ant.h"
#include <list>

class AntFarm{
public:
	std::list <Ant*> ants;
	AntFarm();
	void AddAnt(Ant ant);
	void Live();
private:
	int max_number; // максимальное количество
	int max_food;
	int number;
	int n, m; //размер
};
