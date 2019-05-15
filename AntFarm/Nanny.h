#pragma once
#include "stdafx.h"
#include <iostream>
#include "Role.h"

class Nanny : public Role{
public:
	Nanny();
	~Nanny();
	virtual void Work(bool danger) override;
	virtual bool Check(int X, int Y) override;
	virtual void SetPlace() override;
	bool ifPampers(int dir, int x, int y);
};
