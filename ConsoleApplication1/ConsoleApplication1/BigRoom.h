#pragma once
#include "room.h"
class BigRoom :
	public room
{
public:
	void init(int type);
	void update(int objectX, int objectY);
};

