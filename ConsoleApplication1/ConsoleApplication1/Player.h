#pragma once
#include "GameCharacter.h"
#include <thread>
#include "chrono"
#include "Candle.h"
#include "Clock.h"
#include "Map.h"

#include "Axe.h"
#include "Crown.h"
#include "Painting.h"
#include "Statue.h"

#include "Apple.h"
using namespace chrono;
using namespace this_thread;
class Player :
	public GameCharacter
	// This is the player class and it will store the players information as well as take the players input for the level. It stores variables as the player's health and attack as well as
	// The player's position. It also stores the story of the game.
{
public:
	// This enum is used to switch through all the option the player has on the level. WASD is used to move, 1 to pick up items and 2 to talk to the boss.
	enum eOptions { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd', ITEMS = 49, TALK = 50, CHEATS = 'c', ADDALLITEMS = 'v' };
	// This enum is used to switch through all the options the player has while interacting with the boss. 
	enum eBossOption {FIGHT =1,ASK,OFFERITEMS};
	// The init() function is used to initialized the player variables.
	void init(string pName);
	// The update() function is called at the gameLoop() and it takes two ints, maxX and maxY, to determine the walls of the room. It also checks for the player's input. And updates some
	// variables like number of items in the invetory, palyerHasMoved and isFightingBoss boss.
	void update(int maxX, int maxY);
	// useItem() is called when the player wants to use an available item. It takes an int type to determine which item will be used. If it is a consumable, then it will substract it from the inventory
	void useItem(int type);
	// addItem() is called whenever a player is on top of an item. It will add the item on the inventory.
	void addItem(int type);
	// story1() is the first part/intro of the story
	void story1();
	// print() is used to print the characters on the story and the items in the item menu.
	void print(int number);
	// goodEnding() and evilEnding() are called depending on the amount of good deeds the player has achieved. If it is high enough it will call the goodEnding. These are called after the while loop in the gameLoo() 
	void goodEnding();
	void evilEnding();
	// end() is the last part/outro of the story and it is called at the very end of the gameLoop() function.
	void end();
	// location is a struct that stores the player's x and y coordinates.
	location playerLocation;
	// attack, armor and maxHealth are static stats that the player has. They increment if any of the bosses is defeted.
	int attack;
	int armor;
	int maxHealth;
	// Inventory is a vector of Items that stores an instance of all the items that the player can hold.
	vector<Item> inventory;
	// numItemsInInventory stores the number of total items in the inventory
	int numItemsInInventory;
	// inBattle checks if the player is in battle and will disable the player controllers if so.
	bool inBattle;
	// hasMoved checks to see if the player moved. If so it will return true. This is mainly used for the encounter class.
	bool hasMoved;
	// toggleEncounter will toggle whether the player can encounter enemies.
	bool toggleEncounter;
	// toggleMap will toggle the minimap at the bottom
	bool toggleMap;
	// isFightingBoss will return true if the player decides to fight a boss.
	bool isFightingBoss;
	// isOnBoss will return true if the player's coordinates are the same as the bosse's coordinates
	bool isOnBoss;
	// bossDefited will return true if the player decided to fight the boss and win.
	bool bossDefited;
	// bossConvinced will return true if the player found the items and talk to the boss.
	bool bossConvinced;
	// int time stores the current time of the player and it changes if the player uses the clock item.
	int time;
	// bossID stores the id of the boss and it will determine which boss the player is interacting with.
	int bossID;
	// GoodDeeds stores the number of good deeds the player has done. It increments every time the player convices a boss and decrises if the player fought a boss.
	int GoodDeeds;
	// An instance of each item the player can have are intialized and store in the inventory vector.
	Apple apple;
	Axe axe;
	Crown crown;
	Painting painting;
	Statue statue;
	Candle candle;
	Clock clock;
	Map map;
};

