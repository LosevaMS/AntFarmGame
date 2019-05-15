#pragma once
#include "Role.h"
#include <iostream>

extern std::string Map_back[16];
extern std::string Map_ants[16];

class Notifications : public Role{
public:
	Notifications();
	~Notifications();
	void Work1();
	virtual bool Check(int X, int Y) override;
	virtual void SetPlace() override;
private:
	int goal_x = -1;;
	int goal_y = -1;;
};
