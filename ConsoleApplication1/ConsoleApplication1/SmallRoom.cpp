#include "SmallRoom.h"
void SmallRoom::init(int type)
{
	roomType = type;
	sizeX = 7;
	sizeY = 5;
	resize(sizeX, sizeY);
	clean();
}
void SmallRoom::update(int objectX, int objectY)
{
	system("CLS");
	clean();
	cout << "-----------------" << endl;
	grid[objectY][objectX] = 'a';
	print();
	cout << "-----------------" << endl;
}