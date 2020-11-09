#include "BigRoom.h"
void BigRoom::init(int type)
{
	roomType = type;
	sizeX = 17;
	sizeY = 7;
	resize(sizeX, sizeY);
	clean();
}
void BigRoom::update(int objectX, int objectY)
{
	system("CLS");
	clean();
	cout << "-------------------------------------" << endl;
	grid[objectY][objectX] = 'a';
	print();
	cout << "-------------------------------------" << endl;
}
