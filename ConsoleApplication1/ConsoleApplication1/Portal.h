#pragma once
#include "Item.h"
class Portal :
	public Item
{
	// The portal object is used to connect rooms. It stores the x and y coordinates of the portal and the name of the room it is connected to. 
	// It also keeps track to see if it is active or not.
public:
	void init(string otherRoom, int x, int y);
	bool isActive = false;
	string roomConnected;
	location portalLocation;
};

