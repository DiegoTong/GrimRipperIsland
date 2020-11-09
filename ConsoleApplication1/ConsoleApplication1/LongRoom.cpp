#include "LongRoom.h"
void LongRoom::init(int type)
{
	roomType = type;
	sizeX = 25;
	sizeY = 3;
	resize(sizeX, sizeY);
	clean();
}
void LongRoom::update(int objectX, int objectY)
{
	system("CLS");
	clean();
	cout << "-----------------------------------------------------" << endl;
	grid[objectY][objectX] = 'a';
	print();
	cout << "-----------------------------------------------------" << endl;
}