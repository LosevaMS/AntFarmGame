#pragma once
#include "Baby.h"
#include "Nanny.h"
#include "Soldier.h"
#include "Collector1.h"
#include "Collector2.h"
#include "Cleaner.h"

class Ant{
public:
    Ant (int X, int Y, int Age);
    ~Ant();
    void Move(bool danger);
    void Upload();
    void SetRole(bool flag);
    bool GetAlive();
    Sprite GetSprite();
    int GetX();
    int GetY();
    void SetSprite(int choice);
    void SetDead();
    void SetHealth();
private:
    Role *antrole;
    int age;
    int health;
    bool alive;
    std::string role;
    int satiety;
};
