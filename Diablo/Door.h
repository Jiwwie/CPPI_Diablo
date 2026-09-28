#pragma once
#include "Player.h"

class Door
{
public:
	Door(int anExit, int anEntry, bool aLocked) :
		myEntry(anEntry),
		myExit(anExit),
		myLocked(aLocked)
	{
	};

	void UnlockDoor(Player& aPlayer);

	int EnterDoor(int aRoomNum) const;

	bool GetLocked() const { return myLocked; }

private:
	int myEntry;
	int myExit;
	bool myLocked;
};

