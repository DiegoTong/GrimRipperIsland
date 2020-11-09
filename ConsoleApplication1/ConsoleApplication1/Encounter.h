#pragma once
#include "Enemy.h"
#include "Player.h"
class Encounter
{
	// Encounter is used to determine whether or not the player will have an encounter with the enemy as well as handling the combat.
public:
	// eBattle is an enum for the switch statement for combat options
	enum eBattle { ATTACK = 49, USEITEM, FLEE };
	// init() initializes all the values of the encounter game object.
	void init();
	// update() is called at the gameLoop(). It randomizes encounterNum and if it is high enough, the player will face an enemy. This is only trigger if the player has moved.
	// It also randomizes a number to set the enemy and if the player has decided to face a boss, then it will initialize a boss battle.
	void update();
	// checkEncounter() is called in the update() to check if the player will face an enemy or not.
	void checkEncounter();
	// setEnemy() sets an enemy depending of the type passed in the parameter.
	void setEnemy(int type);
	// battle() is runs the battle loop. It checks for player input for the fight and will handle the fighting. It also handles how much damage the enemy deals the player, and 
	// loot dropped by the enemy.
	void battle();
	// This function checks if the gameCharacter passed (player or enemy) is alive and it will returns a bool acordingly.
	bool checkIfAlive(GameCharacter character);
	// encounterNum stores the random value for the encounter
	int encounterNum;
	// setEnemyType stores the random value for the enemy or the BossID if it is a boss.
	int setEnemyType;
	// battleEnd is used to end the battleLoop. It will only turn on if the player either: defited the enemy/boss, died or ran away.
	bool battleEnd;
	// attacked checks if the player inputed an actual command for the combat, if not then don't let the enemy attack.
	bool attacked;
	// flee stores a random value to check if the player succesfully fleed combat.
	int flee;
	// player is apointer of type Player that stores the addres of the player game object.
	Player* player;
	// enemy is created initiated every time the player enters combat.
	Enemy enemy;
};

