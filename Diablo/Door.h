#pragma once


class Door
{
public:
	Door(int anExit, int anEntry) :
		myEntry(anEntry),
		myExit(anExit)
	{
	};

	int EnterDoor(int aRoomNum);

private:
	int myEntry; //left to right entry
	int myExit;  //right to left entry

};

