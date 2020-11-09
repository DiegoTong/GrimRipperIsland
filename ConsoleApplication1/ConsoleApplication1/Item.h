#pragma once
#include "GameCharacter.h"
class Item :
	public GameCharacter
{
	// The Item class is used as a parent class for all items and it is a child of GameCharacter itself
public:
	// numInInvetory stores how many of a given item are in in the player's inventory.
	int numInInventory;
	// itemType stores what type of item it is. 0 for apple, 1 for axe, etc..
	int itemType;
	// itemLocation stores the x and y coordinates of the item
	location itemLocation;
};

