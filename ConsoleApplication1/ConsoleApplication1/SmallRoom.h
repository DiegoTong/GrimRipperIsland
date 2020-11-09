#pragma once
#include "room.h"
class SmallRoom :
	public room
{
public:
	void init(int type);
	void update(int objectX, int objectY);
};

