#pragma once
#include "Player.h"
class Enemy :
	public Player
{
public:
	void init(int type);
	void print(int type);
	int encounterLevel;
};

