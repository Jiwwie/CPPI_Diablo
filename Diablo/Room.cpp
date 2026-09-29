#include "Room.h"
#include "Door.h"
#include "Player.h"
#include "Enum.h"
#include "GameFunction.h"

void Room::DisplayEnemies() const
{
	for (int enemyNum = 0; enemyNum < myEnemies.size(); enemyNum++)
	{
		std::cout << "[" << enemyNum + 1 << "] "; 
		myEnemies[enemyNum].ShowStats();
		std::cout << '\n';
	}
}

void Room::SpawnEnemies(int anAmount)
{
    struct EnemyStats
    {
        int baseHealth = 25;
        int highHealth = 75;
        int baseDamage = 10;
        int highDamage = 20;
    };

    EnemyStats stat;

	for (int enemyCount = 0; enemyCount < anAmount; enemyCount++)
	{
		Enemy enemy(stat.baseHealth, stat.baseDamage);
		myEnemies.push_back(enemy);
	}
}

void Room::SetDoors(Door* aDoor)
{
    myDoors.push_back(aDoor);
}


void Room::KillEnemy(int anEnemy)
{
	if (!myEnemies[anEnemy].isAlive())
	{
		myEnemies.erase(myEnemies.begin() + anEnemy);
	}
}

int Room::GetTarget(int aChoice) const
{
    std::cin >> aChoice;
    while (aChoice <= 0 || aChoice > myEnemies.size() || std::cin.fail())
    {
        GameFunction::ClearInputBuffer();
        std::cout << "There's no enemy there...\n";
        std::cin >> aChoice;
    }
    GameFunction::ClearInputBuffer();
    return aChoice;
}

void Room::RoomIntro(Player& aPlayer)
{
    const int EntranceHall = static_cast<int>(Enum::RoomName::EntranceHall);
    const int Courtyard = static_cast<int>(Enum::RoomName::Courtyard);
    const int Parlor = static_cast<int>(Enum::RoomName::Parlor);
    const int Room46 = static_cast<int>(Enum::RoomName::Room46);

    int currentRoom = aPlayer.GetCurrentRoom();

    system("cls");
    switch (currentRoom)
    {
        case EntranceHall:
        {
            std::cout << "You walk into the ENTRANCE HALL...\n";
            std::cout << "The lobby is dark and garish.\n";
            std::cout << "You feel as though your adventure is about to begin...\n\n";
            break;
        }
        case Courtyard:
        {
            std::cout << "You walk into the COURTYARD...\n";
            std::cout << "Although you're still inside the mansion,\n";
            std::cout << "This room feels oddly similar to the outside.\n\n";
            break;
        }
        case Parlor:
        {
            std::cout << "You walk into the PARLOR...\n";
            std::cout << "The room is furnished with couches and armchairs.\n";
            std::cout << "You feel cozy.\n\n";
            break;
        }
        case Room46:
        {
            std::cout << "You walk into ROOM 46...\n";
            std::cout << "At last, your adventure through the mansion comes to an end.\n\n";
            break;
        }
        default:
            break;
    }

    system("pause");
}

void Room::Battle(Player& aPlayer)
{
    while (myEnemies.size() > 0 && aPlayer.isAlive())
    {
        int chosenEnemy = 0;
        system("cls");
        std::cout << "Current room: " << myRoomName << '\n';
        std::cout << "Enemies in room: " << myEnemies.size();

        std::cout << "\n\n";
        DisplayEnemies();
        aPlayer.ShowStats();

        std::cout << "Which enemy do you attack?\n";
        chosenEnemy = GetTarget(chosenEnemy);
        chosenEnemy -= 1;
        aPlayer.DoDamage(myEnemies[chosenEnemy]);
        KillEnemy(chosenEnemy);
        for (int enemies = 0; enemies < myEnemies.size(); enemies++)
        {
            myEnemies[enemies].DoDamage(aPlayer);
        }
        system("pause");
    }

}

void Room::PostBattle(Player& aPlayer) const
{
    int choice = 0;
    while (choice != 3)
    {
        choice = 0;
        system("cls");
        std::cout << "Current room: " << myRoomName << '\n';
        std::cout << "=========================================\n";
        std::cout << "You looked for more enemies in this room.\n";
        std::cout << "But no one came.\n\n";
        std::cout << "What do you do?\n";

        std::cout << "[" << 1 << "] Show Stats\n\n";
        std::cout << "[" << 2 << "] Find loot\n\n";
        std::cout << "[" << 3 << "] Go to doors\n\n";

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
                aPlayer.ShowStats();
                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                std::cout << "You looked for loot but the room was empty\n";
                system("pause");
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

void Room::SelectDoor(Player& aPlayer, std::vector<Room>& someRooms)
{
    int doorChoice;
    system("cls");
    std::cout << "Current room: " << myRoomName << '\n';
    std::cout << "=========================================\n";
    std::cout << "Before you stands " << myDoors.size() << " doors.\n";
    std::cout << "Which door do you approach?\n\n";
    for (int i = 0; i < myDoors.size(); i++)
    {
        std::cout << "[" << i + 1 << "] ";
        std::cout << " Door to " << someRooms[myDoors[i]->EnterDoor(aPlayer.GetCurrentRoom())].GetRoomName() << "\n\n";
    }

    std::cin >> doorChoice;

    while (doorChoice <= 0 || doorChoice > myDoors.size() || std::cin.fail())
    {
        GameFunction::ClearInputBuffer();
        std::cout << "Invalid input, try again : ";
        std::cin >> doorChoice;
    }
    GameFunction::ClearInputBuffer();
    doorChoice -= 1;

    if (myDoors[doorChoice]->GetLocked())
    {
        myDoors[doorChoice]->UnlockDoor(aPlayer);
    }

    if (!(myDoors[doorChoice]->GetLocked()))
    {
        aPlayer.SetCurrentRoom(myDoors[doorChoice]->EnterDoor(aPlayer.GetCurrentRoom()));
    }

}

void Room::EnterRoom(Player& aPlayer, std::vector<Room>& someRooms)
{
    RoomIntro(aPlayer);
    Battle(aPlayer);
    if (aPlayer.isAlive())
    {
        PostBattle(aPlayer);
        SelectDoor(aPlayer, someRooms);
    }
}
