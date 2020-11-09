#pragma once
#include "Level.h"
class Level3 :
	public Level
{
public:
	void init(Player* mPlayer);
	BigRoom bREntrance;
	LongRoomPr lREntranceToLobby;
	SmallRoom sRLobby;
	LongRoomPr lRLobbyToNorthernRoom;
	SmallRoom sRNorthernRoom;
	LongRoom lREntranceToWestRoom1;
	LongRoomPr lREntranceToWestRoom2;
	LongRoom lREntranceToWestRoom3;
	LongRoomPr lREntranceToWestRoom4;
	SmallRoom sRWestRoom;
	LongRoom lREntranceToBallRoom;
	BigRoom bRBallRoom;
	SmallRoom sRBathRoom;
	SmallRoom sRWestWing;
	LongRoomPr lRWestWingToSouthWestChamber;
	MediumRoom mRSouthWestChamber;
	LongRoom lRSouthWestChamberToBoss;
	MediumRoom mRBossRoom;
	LongRoom lRSouthEastChamberToBoss;
	MediumRoom mRSouthEastChamber;
	LongRoomPr lRSouthEastChamberToSouthGateHouse;
	MediumRoom mRSouthGateHouse;
	LongRoomPr lRSouthGateHouseToNorthGateHouse;
	SmallRoom sRNorthGateHouse;
	LongRoom lRNorthGateHouseToEntrance;
	LongRoomPr lRNorthGateHouseToWestChamber;
	MediumRoom mRWestChamber;


};

