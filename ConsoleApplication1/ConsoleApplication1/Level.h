#pragma once
#include"SmallRoom.h"
#include"LongRoom.h"
#include"LongRoomPr.h"
#include"BigRoom.h"
#include"MediumRoom.h"
#include "Player.h"
class Level
	// Level serves as the parent class for all the level classes. Here the level game loop will be run. This is a smaller gameLoop inside the game loop and it is used to
	// check the players progress in the level. Each level has its own unique layout.
{
public:
	// The init() function is virtual because all level classes will have their own unique initialization.
	virtual void init();
	// checkItemPickedUp() checks to see if the player is on top of an item or a boss. If on top of an item, add it to the inventory and turn item is on the room to false. 
	// If on top of the boss, turn isOnBoss on.
	void checkItemPickedUp();
	// The update() function will check if the player is on top of a portal, call the update() of the current room, check the current time, and print out the map and stats.
	// This function is called at the gameLoop(). It takes an int level to see which map it will print.
	void update(int level);
	// setItemsInRooms sets all the items in the room. It will randomly assigned apples to each "normal" room with a random coordinate. It will assign the boss to the "boss room" 
	// and it will store the items on the "chess room". Depending on which level it is, it will store 2 to 3 itmes. These items are constant across all levels. It also takes an int level
	// to decide whether to store 2 or 3 items. It will randomly choose 2/3 chestrooms in the level to store the items.
    void setItemsInRooms(int level);
	// stats() prints out the player's stats.
	void stats();
	// printMap() prints out the map of the level. It takes an int level to decide which map to print
	void printMap(int level);
	// checkTime() checks the current time. If the player's time is different from the level's time, meaning the player change the time with the clock item, then it will proceed to heal the
	// palyer to full health.
	void CheckTime();
	// levelRooms is a vector of room pointers that stores all the rooms in the level. It is used to cycle through all the rooms in the level.
	vector<room*> levelRooms;
	// currentRoom is a pointer that stores the memory address of the current room which the player is in.
	room* currentRoom;
	// player is a pointer of type Player that stores the players's information
	Player* player;
	// levelFinished serves to end the level game loop. It is also used by the checkGameOVer() function in the game loop to see if the player has finished all three levels.
	bool levelFinished;
	// levelTime stores the current time of the level.
	int levelTime;
	// setItemRan stores the random values for the items.
	int setItemRan;
	// chestRooms is a vector of ints to decide which "chest room" on the map will store the items.
	vector<int> chestRooms;
};

