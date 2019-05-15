#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef MY_SYMBOL_H
#define MY_SYMBOL_H

extern std::string Map_back[16];
extern std::string Map_ants[16];
extern int food;
extern int branches;
extern std::vector<int> ant_x;
extern std::vector<int> ant_y;

using namespace sf;

class Role{
public:
    Role(int r);
    virtual ~Role();
    virtual void Work(bool danger)=0;
    virtual bool Check(int X, int Y)=0;
    virtual void SetPlace()=0;
    void SetSprite(int choice);
    Sprite GetSprite();
    void SetX(int X);
    void SetY(int Y);
    int GetX();
    int GetY();
    void SetPosition(int X, int Y);
    int GetRole();
private:
    int role;
    Sprite sprite;
    Texture texture;
    int x,y;
};

#endif //MY_SYMBOL_H