#pragma once
#include "room.h"
class LongRoom : public room
{
public:
	void init(int type);
	void update(int objectX, int objectY);
};

