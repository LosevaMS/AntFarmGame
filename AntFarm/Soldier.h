#pragma once
#include "stdafx.h"
#include <iostream>
#include "Role.h"


class Soldier : public Role{
public:
	Soldier();
	~Soldier();
	virtual void Work(bool danger) override;
	virtual bool Check(int X, int Y) override;
	virtual void SetPlace() override;
private:
	bool place;
	int goal_x, goal_y;
	int cnt = 0;//счётчик ударов в битве с врагом
};
