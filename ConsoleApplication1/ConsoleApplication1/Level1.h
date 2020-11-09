#pragma once
#include "Level.h"
class Level1 :
	public Level
{
public:
	void init(Player* mPlayer);
	LongRoom lREntrance;
	SmallRoom sREntranceleft;
	SmallRoom sREntranceRight;
	LongRoomPr lREntranceToMain;
	BigRoom bRMainRoom;
	SmallRoom sMMainRoomLeft;
	MediumRoom mRBoss;
	LongRoom lRMainToSide;
	SmallRoom sRKitchen;
	MediumRoom Hall;
	SmallRoom sRHallTop;
	LongRoomPr lRHallToChest;
	SmallRoom sRChestRoom;
};

