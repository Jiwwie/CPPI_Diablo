#pragma once

class Door
{
public:
	Door(int anExit, int anEntry, bool aLocked) :
		myEntry(anEntry),
		myExit(anExit),
		myLocked(aLocked)
	{
	};

	int EnterDoor(int aRoomNum);

private:
	int myEntry;
	int myExit;
	bool myLocked;
};

