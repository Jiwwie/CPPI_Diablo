#include <iostream>
#include "Door.h"
#include "Player.h"
#include "GameFunction.h"

void Door::UnlockDoor(Player& aPlayer)
{
	bool byDoor = true;

	while (byDoor)
	{
		int choice = 0;
		system("cls");
		std::cout << "The door is locked!\n";
		std::cout << "What do you want to do?\n";
		std::cout << "[1] Pick the lock\n";
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
				if (aPlayer.GetAgility() >= 5)
				{
					std::cout << "\n*Click* . . . The door opens before you...\n\n";
					myLocked = false;
					byDoor = false;
				}
				else
				{
					std::cout << "\nYou try to pick the lock but FAIL miserably\n\n";
				}
				break;
			}
			case 2:
			{
				if (aPlayer.GetStrength() >= 8)
				{
					std::cout << "\nYou hit the door and it crumbles before you...\n";
					std::cout << "You feel masculine.\n\n";
					myLocked = false;
					byDoor = false;
				}
				else
				{
					std::cout << "\nYou hit the door with all your strength...\n";
					std::cout << "But it does not budge.\n\n";
				}
				break;
			}
			case 3:
			{
				byDoor = false;
				break;
			}
			default:
				break;
		}

		system("pause");

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