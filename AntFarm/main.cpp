// AntFarm.cpp: определяет точку входа для консольного приложения.
//
#include <SFML/Graphics.hpp>
//#include "Ant.h"
//#include "AntFarm.h"
#include "Enemy.h"
#include "AntFarm.h"
#include "stdafx.h"
#include <iomanip>
#include <windows.h>
#include <random>
#include <ctime>
#include <list>
#include <Windows.h>
#include <fstream>

#include <iostream>
#include "Ant.h"
using namespace sf;
#define MAX_FOOD 10;

int main() {

	int wasted_time = 0;

	srand(time(NULL));

	RenderWindow window(sf::VideoMode(2550, 1360), "Ant Farm");

	//для текста
	Font font;
	font.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/font.otf");
	std::string food_str = std::to_string(food);
	std::string branches_str = std::to_string(branches);
	std::string wasted_time_str = std::to_string(wasted_time);
	//текст
	Text text;
	text.setString("Amount of food: " + food_str + '\n' +
		"Amount of branches: " + branches_str + '\n' +
		"Wasted Time: " + wasted_time_str);
	text.setFont(font);
	text.setCharacterSize(35);
	text.setColor(Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setPosition(2050, 0);

	// земля
	Texture dirt;
	dirt.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/ground.png");
	Sprite dirt_sprite;
	dirt_sprite.setTexture(dirt);

	// трава
	Texture grass;
	grass.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/grass.png");
	Sprite grass_sprite;
	grass_sprite.setTexture(grass);

	// тарелка
	Texture plate;
	plate.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/plate.png");
	Sprite plate_sprite;
	plate_sprite.setTexture(plate);

	// тарелка с едой
	Texture plate_food;
	plate_food.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/plate_with_burger.png");
	Sprite plate_food_sprite;
	plate_food_sprite.setTexture(plate_food);

	// ветки
	Texture branch;
	branch.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/new.png");
	Sprite branch_sprite;
	branch_sprite.setTexture(branch);

	// бургер
	Texture burger;
	burger.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/chickenburger.png");
	Sprite burger_sprite;
	burger_sprite.setTexture(burger);

	// пицца
	Texture pizza;
	pizza.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/pizza.png");
	Sprite pizza_sprite;
	pizza_sprite.setTexture(pizza);
	//  мусор
	Texture rubbish;
	rubbish.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/rubbish.png");
	Sprite rubbish_sprite;
	rubbish_sprite.setTexture(rubbish);
	// памперсы
	Texture pampers;
	pampers.loadFromFile("/Users/Мария/Desktop/AntFarm/AntFarm/pampers.png");
	Sprite pampers_sprite;
	pampers_sprite.setTexture(pampers);


	// время
	Clock clock;
	float time_game_ant = 0, time_game_branch = 0, time_game_food = 0;
	float time_spent = 0;

	// координаты
	int x, y;

	int attempts = 0, choice;

	// муравейник
	//AntFarm antfarm;
//	std::list<Ant*>::iterator it;


	Map_back[5][14]='c';
	Enemy Kira(2040, 425);

	//Ant s1(1870, 425, 25);
	//Ant s2(1870, 510, 30);
	//Ant s3(510, 510, 30);

	Ant a(0, 595, 0);
	Ant a1(170, 595, 0);
	Ant a2(1995, 510, 25);
	Ant a3(2040, 595, 25);
	Ant a4(1955,1190,100);
	Ant a5(1955,85,150);
	Ant a6(2040,1275,150);
	//antfarm.AddAnt(a);
//	antfarm.AddAnt(a1);
//	antfarm.AddAnt(a2);

	// начало
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//прошедшее время
		time_spent = clock.getElapsedTime().asMicroseconds();
		clock.restart(); //перезагружает время
		time_spent = time_spent / 1000;
		time_game_ant += time_spent;
		time_game_branch += time_spent;
		time_game_food += time_spent;

		//генерация ветки
		if (time_game_branch >= 10000){
			attempts = 0;
			while (attempts != 10){
				x = rand() % 20;
				y = rand() % 10;
				if (Map_back[y][x] == 'g' && Map_ants[y][x] == '0'){
					Map_back[y][x] = 'b';
					break;
				}
			}
			time_game_branch = 0;
		}

		//генерация еды
		if (time_game_food >= 5000){
			attempts = 0;
			while (attempts != 10){
				x = rand() % 20;
				y = rand() % 10;
				choice = rand() % 2;
				if (Map_back[y][x] == 'g' && Map_ants[y][x] == '0'){
					switch (choice){
					case 0: Map_back[y][x] = 'c'; break;
					case 1: Map_back[y][x] = 'p'; break;
					}
					break;
				}
			}
			time_game_food = 0;
		}

		// муравейник живет (тут будет что-то со списком)
		if (time_game_ant >= 1000){
			//antfarm.Live();
			a.Move(true);
			a1.Move(true);
			a2.Move(true);
			a3.Move(true);
			a4.Move(true);
			a5.Move(true);
			a6.Move(true);
			Kira.Destroy();
			//s1.Move(true);
			//s2.Move(true);
			//s3.Move(true);
			wasted_time++;
			time_game_ant = 0;
		}

		food_str = std::to_string(food);
		branches_str = std::to_string(branches);
		wasted_time_str = std::to_string(wasted_time);

		text.setString("Amount of food: " + food_str + '\n' +
			"Amount of branches: " + branches_str + '\n' +
			"Wasted Time: " + wasted_time_str);

		window.clear();

		for (int i = 0; i<16; i++){
			for (int j = 0; j<30; j++){
				if (Map_back[i][j] == 'd'){
					dirt_sprite.setPosition(j * 85, i * 85);
					window.draw(dirt_sprite);
				}
				if (Map_back[i][j] == 'g'){
					grass_sprite.setPosition(j * 85, i * 85);
					window.draw(grass_sprite);
				}
				if (Map_back[i][j] == 'f'){
					plate_sprite.setPosition(j * 85, i * 85);
					window.draw(plate_sprite);
				}
				if (Map_back[i][j] == 'o'){
					plate_food_sprite.setPosition(j * 85, i * 85);
					window.draw(plate_food_sprite);
				}
				if (Map_back[i][j] == 'b'){
					branch_sprite.setPosition(j * 85, i * 85);
					window.draw(branch_sprite);
				}
				if (Map_back[i][j] == 'c'){
					burger_sprite.setPosition(j * 85, i * 85);
					window.draw(burger_sprite);
				}
				if (Map_back[i][j] == 'p'){
					pizza_sprite.setPosition(j * 85, i * 85);
					window.draw(pizza_sprite);
				}
				if (Map_back[i][j] == 's'){
					pampers_sprite.setPosition(j * 85, i * 85);
					window.draw(pampers_sprite);
				}
				if (Map_back[i][j] == 'r'){
					rubbish_sprite.setPosition(j * 85, i * 85);
					window.draw(rubbish_sprite);
				}
			}
		}

		/*for (it = antfarm.ants.begin(); it != antfarm.ants.end(); it++){
			window.draw((*it)->GetSprite());
		}*/
		window.draw(a.GetSprite());
		window.draw(a1.GetSprite());
		window.draw(a2.GetSprite());
		window.draw(a3.GetSprite());
		window.draw(a4.GetSprite());
		window.draw(a5.GetSprite());
		window.draw(a6.GetSprite());
		window.draw(Kira.GetSprite());
		//window.draw(s1.GetSprite());
		//window.draw(s2.GetSprite());
		//window.draw(s3.GetSprite());

		window.draw(text);

		window.display();

	}

	for (int i = 0; i<16; i++){
		for (int j = 0; j<30; j++){
			std::cout << Map_ants[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}