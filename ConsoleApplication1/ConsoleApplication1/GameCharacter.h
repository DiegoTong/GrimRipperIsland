#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <map>

using namespace std;
class GameCharacter
{
	// GameCharacter is the parent class of all game objects int a level. This includes enemies, players and items.
public:
	// Location is a struct that stores the x and y coordinates of the gameCharacter
	struct location
	{
		int x;
		int y;
	};
	// Each gameCharacter will have its own init(), update() and print() function
	void init();
	void update();
	void print();
	// health is used to keep track of the gameCharacter's health
	int health;
	// name stores the name of the gameCharacter
	string name;
};

