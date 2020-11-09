#include "room.h"

void room::init()
{

}
void room::update(int x, int y)
{

}
void room::print()
{
	updateItemsLocation();
	for (int i = 0; i <= sizeY; i++)
	{
		cout << "|";
		for (int g = 0; g <= sizeX - 1; g++)
		{
			cout << grid[i][g] << " ";
		}
		cout << grid[i][sizeX] << "|" << endl;;
	}
}
void room::resize(int mapX,int mapY)
{
	grid.resize(sizeY +1);
	for (int i = 0; i <= sizeY; i++)
	{
		grid[i].resize(sizeX +1);
	}
}
void room::createPortal(int direction, string otherRoom, int x, int y)
{
	if (direction == 1)
	{
		nPortal.init(otherRoom, x, y);
		nPortal.isActive = true;
	}
	else if (direction == 2)
	{
		sPortal.init(otherRoom, x, y);
		sPortal.isActive = true;
	}
	else if (direction == 3)
	{
		ePortal.init(otherRoom, x, y);
		ePortal.isActive = true;
	}
	else if (direction == 4)
	{
		wPortal.init(otherRoom, x, y);
		wPortal.isActive = true;
	}
}
void room::clean()
{
	for (int i = 0; i <= sizeY; i++)
	{
		for (int g = 0; g <= sizeX; g++)
		{
			grid[i][g] = '-';
		}
	}
}
Portal room::getPortals(int direction)
{
	if (direction == 1)
	{
		return nPortal;
	}
	else if (direction == 2)
	{
		return sPortal;
	}
	else if (direction == 3)
	{
		return ePortal;
	}
	else if (direction == 4)
	{
		return wPortal;
	}
}
void room::updateItemsLocation()
{
	if (nPortal.isActive == true)
	{
		grid[nPortal.portalLocation.y][nPortal.portalLocation.x] = '0';
	}
	if (sPortal.isActive == true)
	{
		grid[sPortal.portalLocation.y][sPortal.portalLocation.x] = '0';
	}
	if (ePortal.isActive == true)
	{
		grid[ePortal.portalLocation.y][ePortal.portalLocation.x] = '0';
	}
	if (wPortal.isActive == true)
	{
		grid[wPortal.portalLocation.y][wPortal.portalLocation.x] = '0';
	}
	if (isItemInRoom == true && roomType == 2)
	{
		grid[itemLocY][itemLocX] = 'i';
	}
	if (isItemInRoom == true && roomType == 0)
	{
		grid[itemLocY][itemLocX] = 'o';
	}
	if (isItemInRoom == true && roomType == 3)
	{
		grid[itemLocY][itemLocX] = 'B';
	}
}

void room::setItemLocation(int x, int y, int type)
{
	if (type != 0)
	{
		x = x / 2;
		y = y / 2;
	}
	else if (type == 0)
	{
		if (x >= sizeX-1)
		{
			x = x - 1;
		}
		else if (x == 0)
		{
			x = x + 1;
		}
		if (y >= sizeY - 1)
		{
			y = y - 1;
		}
		else if (y == 0)
		{
			y = y + 1;
		}
	}
	isItemInRoom = true;
	itemLocX = x;
	itemLocY = y;
	itemType = type;
}