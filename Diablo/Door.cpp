#include <iostream>
#include "Door.h"
#include "GameFunction.h"

void Door::UnlockDoor()
{
	while (myLocked)
	{
		int choice = 0;
		system("cls");
		std::cout << "The door is locked!\n";
		std::cout << "What do you want to do?\n";
		std::cout << "[1] Lockpick the door\n";
		std::cout << "[2] Break the door\n";
		std::cout << "[3] Walk away from door\n";

		std::cin >> choice;
		while (choice <= 0 || choice > 3 || std::cin.fail())
		{
			GameFunction::ClearInputBuffer();
			std::cout << "Invalid input, try again : ";
			std::cin >> choice;
		}
		GameFunction::ClearInputBuffer();

		switch (choice)
		{
			case 1:
			{
				std::cout << "You lockpick the door\n";
				myLocked = false;
				break;
			}
			case 2:
			{
				std::cout << "You break the door\n";
				myLocked = false;
				break;
			}
			case 3:
			{

				break;
			}
			default:
				break;
		}

	}
}

int Door::EnterDoor(int aRoomNum) const
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