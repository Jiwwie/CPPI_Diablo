#include "Door.h"

int Door::EnterDoor(int aRoomNum)
{
	if (myEntry == aRoomNum)
	{
		return myExit;
	}
	else
	{
		return myEntry;
	}

}