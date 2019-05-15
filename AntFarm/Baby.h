#pragma once
#include "Role.h"


class Baby: public Role{
public:
    Baby();
    ~Baby();
    virtual void Work(bool danger) override;
    virtual bool Check(int X, int Y) override;
    virtual void SetPlace() override;
};
