#include "LongRoomPr.h"
void LongRoomPr::init(int type)
{
	roomType = type;
	sizeX = 3;
	sizeY = 14;
	resize(sizeX, sizeY);
	clean();
}
void LongRoomPr::update(int objectX, int objectY)
{
	system("CLS");
	clean();
	cout << "---------" << endl;
	grid[objectY][objectX] = 'a';
	print();
	cout << "---------" << endl;
}