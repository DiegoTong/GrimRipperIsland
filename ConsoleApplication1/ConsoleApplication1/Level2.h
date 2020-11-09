#pragma once
#include "Level.h"
class Level2 :
	public Level
{
public:
	void init(Player* mPlayer);
	SmallRoom sREntrance;
	LongRoomPr lREntranceToLobby;
	BigRoom bRLobby;
	LongRoomPr lRLobbyToDresser1;
	LongRoomPr lRLobbyToDresser2;
	SmallRoom Dresser;
	LongRoom lRLobbyToObservatory;
	MediumRoom mRObservatory;
	LongRoomPr lRNorthLabEntrance;
	LongRoom lRWestLabEntrance;
	MediumRoom mRLab;
	LongRoom lRWestLibraryEntrance;
	MediumRoom mRLibary;
	LongRoom lREastLibraryEntrance;
	SmallRoom sRStable;
	LongRoomPr lRObservatoryToStable;
	LongRoomPr lRObservatoryToBoss1;
	LongRoomPr lRObservatoryToBoss2;
	MediumRoom mRBossRoom;
	// 19 rooms
};

