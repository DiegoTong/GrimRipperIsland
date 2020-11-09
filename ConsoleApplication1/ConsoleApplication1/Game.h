#pragma once
#include "room.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Encounter.h"
class Game
{
	// The game class will be running the main game loop. The update for the player and the levels will be called in the gameLoop() function and it will be printing
	// the islands that the player can visit. It will also be checking for when the game is over.
public:
	// This enums are used on the switch statement that allows the player to choose which island/level is to be visited
	enum eLevels {LEVEL1=1, LEVEL2, LEVEL3};
	// The gameLoop will be running the player, encounter and level update functions. This will serve as the main loop for the whole game
	void gameLoop(string pName);
	// Print is use mainly to test new sprites and is not used in the final product
	void print();
	// checkGameOver() checks if either the player has no health or all the levels have been completed. If so finish the game
	void checkGameOver(GameCharacter player, Level level1, Level level2, Level level3);
	// chooseLevel() allows the player to choose between the 3 islands/levels
	void chooseLevel();
	// printMap() prints out the islands
	void printMap();
	// gameOver is used to get out of the gameLoop and it turns true once if the statement in checkGameOver is true
	bool gameOver;
	// ichcekInput is used to check the player input. If the input is correct then proceed, otherwise loop again till the player inputs a correct input
	bool icheckInput;
	// the map array stores the island ascii art
	char map[30][30];
	// levels is a vector of pointers that stores all the levels. It is use to cicle through all the levels easier
	vector<Level*> levels;
	// levelChoice stores which level the player has choosen
	int levelChoice;
	// chosenLevel is a pointer of type level that points to the level chosen by the palyer.
	Level* chosenLevel;
};

