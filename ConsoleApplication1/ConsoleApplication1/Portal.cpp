#include "Portal.h"
void Portal::init(string otherRoom, int x, int y)
{
	roomConnected = otherRoom;
	portalLocation.x = x;
	portalLocation.y = y;
}