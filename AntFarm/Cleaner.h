#pragma once
#include "Role.h"

class Cleaner: public Role{
public:
    Cleaner();
    ~Cleaner();
    virtual void Work(bool danger) override;
    virtual bool Check(int X, int Y) override;
    virtual void SetPlace() override;
    bool Check1(int X,int Y);
private:
   bool rubbish_ant;
   int goal_x,goal_y;
};

