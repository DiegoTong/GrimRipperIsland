#include "MediumRoom.h"
void MediumRoom::init(int type)
{
	roomType = type;
	sizeX = 11;
	sizeY = 7;
	resize(sizeX, sizeY);
	clean();
}
void MediumRoom::update(int objectX, int objectY)
{
	system("CLS");
	clean();
	cout << "-------------------------" << endl;
	grid[objectY][objectX] = 'a';
	print();
	cout << "-------------------------" << endl;
}