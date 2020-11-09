#include "Encounter.h"

void Encounter::init()
{
	encounterNum = 0;
	flee = 0;
	setEnemyType = 0;
}
void Encounter::update()
{
	if (player->hasMoved == true)
	{
		if (player->toggleEncounter == true)
		{
			encounterNum = (rand() % 10) + 1;
			setEnemyType = (rand() % 7) + 1;
			setEnemy(setEnemyType);
			checkEncounter();
		}
	}
	else if (player->isFightingBoss == true)
	{
		setEnemy(player->bossID);
		battle();
		player->bossDefited = true;
	}
}
void Encounter::checkEncounter()
{
	if (encounterNum > 8)
	{
		battle();
	}
}
void Encounter::battle()
{
	attacked = false;
	battleEnd = false;
	player->inBattle = true;
	while (battleEnd == false)
	{
		attacked = false;
		system("CLS");
		cout << "enemy's health: " << enemy.health << endl;
		if (player->isFightingBoss == false)
		{
			enemy.print(setEnemyType);
		}
		else
		{
			enemy.print(player->bossID+10);
		}
		cout << "--------------------------------" << endl;
		cout << "ATTACK = 1 USE ITEM = 2 FLEE = 3" << endl;
		cout << "--------------------------------" << endl;
		cout << "player's health: " << (*player).health << endl;
		cout << "player's attack: " << (*player).attack << endl;
		cout << "player's armor: " << (*player).armor << endl;
		flee = 0;
		char bChoice;
		bChoice = _getch();
		switch (bChoice)
		{
		case ATTACK:
			enemy.health = enemy.health - (*player).attack;
			attacked = true;
			break;
		case USEITEM:
			system("CLS");
			for (int i = 0; i < player->inventory.size(); i++)
			{
				player->numItemsInInventory += player->inventory[i].numInInventory;
			}
			if (player->numItemsInInventory > 0)
			{
				for (int i = 0; i < player->inventory.size(); i++)
				{
					if (player->inventory[i].numInInventory > 0)
					{
						cout << "Number of " << player->inventory[i].name << "in inventory: (" << player->inventory[i].numInInventory << ") Press (" << i << ") to use" << endl;
					}
				}
				cout << "Press any key to exit" << endl;
				bChoice = _getch();
				if (bChoice - 48 == 0)
				{
					if (player->inventory[bChoice - 48].numInInventory > 0)
					{
						cout << "Item Used " << endl;
						player->useItem(bChoice - 48);
						if (bChoice - 48 == 0)
						{
							player->inventory[bChoice - 48].numInInventory--;
						}
					}
					else
					{
						cout << "Item not in the inventory" << endl;
					}
				}
				else
				{
					cout << "invalid choice" << endl;
				}
				system("PAUSE");
			}
			else
			{
				cout << "No items in inventory" << endl;
				system("PAUSE");
			}
			attacked = true;
			break;
		case FLEE:
			if (player->isFightingBoss == false)
			{
				flee = (rand() % 19) + 1;
				attacked = true;
			}
			else
			{
				cout << "Can't flee a boss battle" << endl;
			}
			break;
		default:
			break;
		}
		if (player->health > player->maxHealth)
		{
			player->health = player->maxHealth;
		}
		battleEnd = checkIfAlive(enemy);

		if (battleEnd == false && attacked == true)
		{
			if ((((*player).armor - enemy.attack)) < 0)
			{
				(*player).health = (*player).health + (*player).armor - enemy.attack;
			}
			battleEnd = checkIfAlive(*player);
		}
		if (flee > 6)
		{
			battleEnd = true;
		}
	}
	if (((rand() % 10) + 1) == 10)
	{
		player->inventory[0].numInInventory++;
	}
	player->inBattle = false;
}	
void Encounter::setEnemy(int type)
{
	if (player->isFightingBoss == false)
	{
		enemy.init(type);
	}
	else if (player->bossID == 1)
	{
		enemy.init(player->bossID+10);
	}
	else if (player->bossID == 2)
	{
		enemy.init(player->bossID+10);
	}
	else if (player->bossID == 3)
	{
		enemy.init(player->bossID + 10);
	}
	else if (player->bossID == 4)
	{
		enemy.init(player->bossID + 10);
	}
}
bool Encounter::checkIfAlive(GameCharacter character)
{
	if (character.health <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}