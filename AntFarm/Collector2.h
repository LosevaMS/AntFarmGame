#pragma once
#include "Role.h"

class Collector2 : public Role{
public:
	Collector2();
	~Collector2();
	virtual void Work(bool danger) override;
	virtual bool Check(int X, int Y) override;
	virtual void SetPlace() override;
	bool Check1(int X, int Y);
private:
	int goal_x;
	int goal_y;
	bool branch_ant;
	bool place;
	int mybranch;
};
