#pragma once
#include "Portal.h"
class room
{
	// The room class serves as a parent class to all the room classes. There are 5 different types of rooms with different sizes that will be combined to make the level's map.
	// The portals that connect to the other rooms are created here and as well as the items/enemy boss of the level.
public:
	// The init() function is a virtual function because each room child class will have its own unique initialization.
	virtual void init();
	// The update() function is also a virtual function and each child class will have its own unique update.
	virtual void update(int x, int y);
	// updateItemsLocation() updates the item location in the rooom to be displayed. This is called before printing the room.
	void updateItemsLocation();
	// print() prints out the room as well as all objects/enemy boss and player.
	void print();
	// createPortal stores values in the chosen portal. There are 4 diferent types of portals North/South/East/West that will determine which way the player is heading.
	// This is used so that the player can spawn inside the map. It also stores the name of the room the portal will be linked with and the location of the portal itself.
    void createPortal(int direction,string otherRoom, int x, int y);
	// The clean() function resets the rooms and cleans it from any ascii character that should not be there(player's old location or items collected).
	void clean();
	// resize() resizes the map to the dimensions passed.
	void resize(int mapX, int mapY);
	// getPortal() returns the portal from the valued passed (North =1 , South =2, East = 4 and West =4)
	Portal getPortals(int direction);
	// setItemLocation() sets an item/enemy boss on the location passed. It also sets its type. If it is bellow 9 it is an item. If it is 9 it is a boss.
	void setItemLocation(int x, int y, int type);
	// Stores the room name. Each room will have its own unique name that will be used to be linked with other rooms.
	string roomName;
	// sizeX and sizeY store the rooms dimensions.
	int sizeX = 0;
	int sizeY = 0;
	// roomType stores the room type. If it is a Chestroom it will spawn items; if it is just a room it might spawn apples; and if it is a Bossroom it will spawn a boss.
	int roomType;
	// isItemInRoom checks to see if the item is/still is in the room.
	bool isItemInRoom;
	// grid is used to store and print the map and any item, boss and player in the room.
	vector<vector<char>>grid;
	// portals is a vector of type portal that stores all the portals in the room.
	vector<Portal> portals;
	// These are the 4 portals each room has. They will be initialized in the level game objects if a portal is needed.
	Portal nPortal;
	Portal sPortal;
	Portal ePortal;
	Portal wPortal;
	// ItemLocX and ItemLocY store the item/Boss location in the room
	int itemLocX;
	int itemLocY;
	// The itemType store the type of the item. If 9 then it is a boss
	int itemType;
};

