#pragma once
#include "Role.h"

class Collector1 : public Role{
public:
	Collector1();
	~Collector1();
	virtual void Work(bool danger) override;
	virtual bool Check(int X, int Y) override;
	virtual void SetPlace() override;
	bool Check1(int X, int Y);
private:
	int goal_x;
	int goal_y;
	bool food_ant;
	bool place;
	int myfood;
};
