#include "Level.h"

void Level::init()
{
	
}

void Level::update(int level)
{
	if (player->playerLocation.x > 0 && player->playerLocation.x < currentRoom->sizeX)
	{
		if (player->playerLocation.y == 0)
		{
			if (currentRoom->getPortals(1).isActive == true && player->playerLocation.x == currentRoom->getPortals(1).portalLocation.x && player->playerLocation.y == currentRoom->getPortals(1).portalLocation.y)
			{
				for (vector <room*> ::iterator it = levelRooms.begin(); it != levelRooms.end(); ++it) {
					if ((*it)->roomName == currentRoom->getPortals(1).roomConnected)
					{
						currentRoom = (*it);
						break;
					}
				}
				player->playerLocation.x = currentRoom->getPortals(2).portalLocation.x;
				player->playerLocation.y = currentRoom->getPortals(2).portalLocation.y -1;
			}
		}
		else
		{
			if (currentRoom->getPortals(2).isActive == true && player->playerLocation.x == currentRoom->getPortals(2).portalLocation.x && player->playerLocation.y == currentRoom->getPortals(2).portalLocation.y)
			{
				for (vector <room*> ::iterator it = levelRooms.begin(); it != levelRooms.end(); ++it) {
					if ((*it)->roomName == currentRoom->getPortals(2).roomConnected)
					{
						currentRoom = (*it);
						break;
					}
				}
				player->playerLocation.x = currentRoom->getPortals(1).portalLocation.x;
				player->playerLocation.y = currentRoom->getPortals(1).portalLocation.y +1;
			}
		}

	}
	else if (player->playerLocation.y > 0 && player->playerLocation.y < currentRoom->sizeY)
	{
		if (player->playerLocation.x == 0)
		{
			if (currentRoom->getPortals(4).isActive == true && player->playerLocation.x == currentRoom->getPortals(4).portalLocation.x && player->playerLocation.y == currentRoom->getPortals(4).portalLocation.y)
			{
				for (vector <room*> ::iterator it = levelRooms.begin(); it != levelRooms.end(); ++it) {
					if ((*it)->roomName == currentRoom->getPortals(4).roomConnected)
					{
						currentRoom = (*it);
						break;
					}
				}
				player->playerLocation.x = currentRoom->getPortals(3).portalLocation.x-1;
				player->playerLocation.y = currentRoom->getPortals(3).portalLocation.y;
			}
		}
		else
		{

			if (currentRoom->getPortals(3).isActive == true && player->playerLocation.x == currentRoom->getPortals(3).portalLocation.x && player->playerLocation.y == currentRoom->getPortals(3).portalLocation.y)
			{
				for (vector <room*> ::iterator it = levelRooms.begin(); it != levelRooms.end(); ++it) {
					if ((*it)->roomName == currentRoom->getPortals(3).roomConnected)
					{
						currentRoom = (*it);
						break;
					}
				}
				player->playerLocation.x = currentRoom->getPortals(4).portalLocation.x + 1;
				player->playerLocation.y = currentRoom->getPortals(4).portalLocation.y;

			}
		}

	}
	checkItemPickedUp();
	currentRoom->update(player->playerLocation.x, player->playerLocation.y);
	CheckTime();
	cout << "Move with WASD || \"1\" use item || \"2\" talk " << endl;
	stats();
	if (player->toggleMap == true)
	{
		printMap(level);
	}

	if (player->health <= 0 || player->bossConvinced == true || player->bossDefited == true)
	{
		if (player->health > 0)
		{
			system("CLS");
			player->print(0);
			cout << "Well done " << player->name << endl;
			system("PAUSE");

			if (player->bossConvinced == true)
			{
				system("CLS");
				player->print(0);
				cout << "I knew you had a big heart inside you " << endl;
				system("PAUSE");
				player->GoodDeeds++;
			}
			else
			{
				system("CLS");
				player->print(0);
				cout << "One less monster to worry about " << endl;
				system("PAUSE");
				player->GoodDeeds--;
			}
		}
		
		levelFinished = true;
		player->bossConvinced = false;
		player->bossDefited = false;
		system("CLS");
	}
}
void Level::CheckTime()
{
	if (levelTime != player->time)
	{
		levelTime = player->time;
		player->health = player->maxHealth;
	}
}
void Level::setItemsInRooms(int level)
{
	for (int i = 0; i < levelRooms.size(); i++)
	{
		setItemRan = (rand() % 6) + 1;
		if (levelRooms[i]->roomType == 0)
		{
			if (setItemRan > 1)
			{
				levelRooms[i]->setItemLocation((rand() % levelRooms[i]->sizeX), (rand() % levelRooms[i]->sizeY), 0);
			}
		}
		if (levelRooms[i]->roomType == 2)
		{
			chestRooms.push_back(i);
		}
		if (levelRooms[i]->roomType == 3)
		{
			levelRooms[i]->setItemLocation(levelRooms[i]->sizeX, levelRooms[i]->sizeY, 9);
		}
	}
	if (level == 1)
	{
		for (int i = 0; i < 2; i++)
		{
			setItemRan = rand() % chestRooms.size();
			if (i == 0)
			{
				levelRooms[chestRooms[setItemRan]]->setItemLocation(levelRooms[chestRooms[setItemRan]]->sizeX, levelRooms[chestRooms[setItemRan]]->sizeY, 7);
			}
			else
			{
				levelRooms[chestRooms[setItemRan]]->setItemLocation(levelRooms[chestRooms[setItemRan]]->sizeX, levelRooms[chestRooms[setItemRan]]->sizeY , 2);
			}
			chestRooms.erase(chestRooms.begin() + setItemRan);
		}
	}
	else if (level == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			setItemRan = rand() % chestRooms.size();
			if (i == 0)
			{
				levelRooms[chestRooms[setItemRan]]->setItemLocation(levelRooms[chestRooms[setItemRan]]->sizeX, levelRooms[chestRooms[setItemRan]]->sizeY, 5);
			}
			else
			{
				levelRooms[chestRooms[setItemRan]]->setItemLocation(levelRooms[chestRooms[setItemRan]]->sizeX, levelRooms[chestRooms[setItemRan]]->sizeY, 3);
			}
			chestRooms.erase(chestRooms.begin() + setItemRan);
		}
	}
	else if (level == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			setItemRan = rand() % chestRooms.size();
			if (i == 0)
			{
				levelRooms[chestRooms[setItemRan]]->setItemLocation(levelRooms[chestRooms[setItemRan]]->sizeX, levelRooms[chestRooms[setItemRan]]->sizeY, 6);
			}
			else if(i == 1)
			{
				levelRooms[chestRooms[setItemRan]]->setItemLocation(levelRooms[chestRooms[setItemRan]]->sizeX, levelRooms[chestRooms[setItemRan]]->sizeY, 1);
			}
			else if (i == 2)
			{
				levelRooms[chestRooms[setItemRan]]->setItemLocation(levelRooms[chestRooms[setItemRan]]->sizeX, levelRooms[chestRooms[setItemRan]]->sizeY, 4);
			}
			chestRooms.erase(chestRooms.begin() + setItemRan);
		}
	}

}

void Level::checkItemPickedUp()
{
	if (player->playerLocation.x == currentRoom->itemLocX && player->playerLocation.y == currentRoom->itemLocY && currentRoom->isItemInRoom == true && currentRoom->itemType<9)
	{
		player->addItem(currentRoom->itemType);
		currentRoom->isItemInRoom = false;
		player->isOnBoss = false;
	}
	else if (player->playerLocation.x == currentRoom->itemLocX && player->playerLocation.y == currentRoom->itemLocY && currentRoom->isItemInRoom == true && currentRoom->itemType ==9)
	{
		player->isOnBoss = true;
	}
	else
	{
		player->isOnBoss = false;
	}
}

void Level::stats()
{
	cout << "Health: "<<player->health << " ";
	cout << "Attack: "<<player->attack << " ";
	cout << "Armor: " << player->armor << endl;
}

void Level::printMap(int level)
{

	if (level == 1)
		{
			char map1[19][37]{
' ',' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' ',' ',' ',' ',
' ','/',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\','.',' ',' ',
'|',' ',' ',' ','|',' ',' ',' ',' ','1','-','-','-','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ','\\','_',' ','|',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','|','1',' ','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','1','3','-','2',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','B',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_',
' ',' ',' ',' ','|',' ',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',
' ',' ',' ',' ','\\','_','/','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','/' };
			for (int i = 0; i < 19; i++)
			{
				for (int g = 0; g < 37; g++)
				{
					cout << map1[i][g];
				}
				cout << endl;
			}
		}
		else if (level == 2)
		{
			char map2[19][37]{
' ',' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' ',' ',' ',' ',
' ','/',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\','.',' ',' ',
'|',' ',' ',' ','|',' ',' ',' ',' ',' ','1',' ',' ',' ',' ',' ',' ',' ','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ','\\','_',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ','3','-','-','-','-','-','-','-','2',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|','-','-','-','2',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|','-','-','-','2','-','-','-','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ','1',' ',' ',' ',' ',' ',' ',' ','B',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_',
' ',' ',' ',' ','|',' ',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',
' ',' ',' ',' ','\\','_','/','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','/' };
			for (int i = 0; i < 19; i++)
			{
				for (int g = 0; g < 37; g++)
				{
					cout << map2[i][g];
				}
				cout << endl;
			}
		}
		else if (level == 3)
	{
		char map3[19][37]{
' ',' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' ',' ',' ',' ',
' ','/',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\','.',' ',' ',
'|',' ',' ',' ','|',' ',' ','-','-','-',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ','\\','_',' ','|',' ',' ','|',' ','|','-','-','-','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ','1',' ',' ',' ',' ',' ','|',' ','2',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ','1',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ','|','1','3','-','-','-','3','-','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','2',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ','2','-','-','-','B','-','-','-','2',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.',' ',' ',
' ',' ',' ',' ','|',' ',' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','_','_','_',
' ',' ',' ',' ','|',' ',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',
' ',' ',' ',' ','\\','_','/','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','/' };
		for (int i = 0; i < 19; i++)
		{
			for (int g = 0; g < 37; g++)
			{
				cout << map3[i][g];
			}
			cout << endl;
		}
	}
}