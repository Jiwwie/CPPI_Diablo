#include "Room.h"
#include "Door.h"
#include "Chest.h"
#include "Player.h"
#include "Enum.h"
#include "Random.h"
#include "Consts.h"
#include "GameFunction.h"
#include "ItemFactory.h"

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
	for (int enemyCount = 0; enemyCount < anAmount; enemyCount++)
	{
        Random rnd;
		Enemy enemy(rnd.GetRandomInt(Const::MIN_ENEMY_HP, Const::MAX_ENEMY_HP), rnd.GetRandomInt(Const::MIN_ENEMY_DMG, Const::MAX_ENEMY_DMG));
		myEnemies.push_back(enemy);
	}
}

void Room::SpawnChests(int anAmount, ItemFactory& anItemFactory)
{
	for (int i = 0; i < anAmount; i++)
	{
        Random rnd;
		Chest chest(rnd.GetRandomInt(1, 2), rnd.GetRandomInt(0, 3), anItemFactory);
		myChests.push_back(chest);
	}
}

void Room::SetDoors(Door* aDoor)
{
    myDoors.push_back(aDoor);
}

void Room::KillEnemy(int anEnemy, ItemFactory& anItemFactory)
{
	if (!myEnemies[anEnemy].isAlive())
	{
		myEnemies.erase(myEnemies.begin() + anEnemy);

        int enemyDrop = myRnd.GetRandomInt(0, 1);
        if (enemyDrop == 1)
        {
            int rndItem = (myRnd.GetRandomInt(0, static_cast<int>(ItemId::Count)-1));
            std::cout << "Enemy dropped an item\n";
            SpawnEnemyDrop(rndItem, anItemFactory);
        }
	}
}

void Room::SpawnEnemyDrop(int anItemIndex, ItemFactory& anItemFactory)
{
	anItemFactory.Create(static_cast<ItemId>(anItemIndex));
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
    Enum::RoomName currentRoom = static_cast<Enum::RoomName>(aPlayer.GetCurrentRoom());

    system("cls");
    switch (currentRoom)
    {
        case Enum::RoomName::EntranceHall:
        {
            std::cout << "You walk into the ENTRANCE HALL...\n";
            std::cout << "The lobby is dark and garish.\n";
            std::cout << "You feel as though your adventure is about to begin...\n\n";
            break;
        }
        case Enum::RoomName::Courtyard:
        {
            std::cout << "You walk into the COURTYARD...\n";
            std::cout << "Although you're still inside the mansion,\n";
            std::cout << "This room feels oddly similar to the outside.\n\n";
            break;
        }
        case Enum::RoomName::Parlor:
        {
            std::cout << "You walk into the PARLOR...\n";
            std::cout << "The room is furnished with couches and armchairs.\n";
            std::cout << "You feel cozy.\n\n";
            break;
        }
        case Enum::RoomName::Room46:
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

void Room::Battle(Player& aPlayer, ItemFactory& anItemFactory)
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
        KillEnemy(chosenEnemy, anItemFactory);
        for (int enemies = 0; enemies < myEnemies.size(); enemies++)
        {
            myEnemies[enemies].DoDamage(aPlayer);
        }
        system("pause");
    }

}

void Room::PostBattle(Player& aPlayer)
{
    int choice = 0;
    while (choice != 3)
    {
        system("cls");
        std::cout << "Current room: " << myRoomName << '\n';
        std::cout << "=========================================\n";
        std::cout << "You looked for more enemies in this room.\n";
        std::cout << "But no one came.\n\n";
        std::cout << "What do you do?\n";

        std::cout << "[1] Show Stats\n\n";
        std::cout << "[2] Find loot\n\n";
        std::cout << "[3] Go to doors\n\n";

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
                system("cls");
                aPlayer.ShowStats();
                aPlayer.ShowInventory(myItems);
                system("pause");
                break;
            }
            case 2:
            {
                choice = 0;
                while (choice != 4)
                {
                    system("cls");
                    std::cout << "Items on floor:\n\n";
                    for (int i = 0; i < myItems.size(); i++)
                    {
                        std::cout << "* ";
                        myItems[i].ShowStats();
                    }
                    for (int i = 0; i < myBoons.size(); i++)
                    {
                        std::cout << "* ";
                        myBoons[i].ShowEffect();
                    }
                    std::cout << "\n\nWhat do you want to do?\n";
                    std::cout << "[1] Pick up item\n";
                    std::cout << "[2] Pick up boon\n";
                    std::cout << "[3] Open chests: currently [" << myChests.size() << "] chests in room.\n";
                    std::cout << "[4] Continue\n";
                    std::cin >> choice;
                    while (choice <= 0 || choice > 4 || std::cin.fail())
                    {
                        GameFunction::ClearInputBuffer();
                        std::cout << "Invalid input: ";
                        std::cin >> choice;
                    }
                    GameFunction::ClearInputBuffer();

                    if (choice == 1 && myItems.size() > 0)
                    {
                        system("cls");
                        std::cout << "Items on floor:\n\n";
                        for (int i = 0; i < myItems.size(); i++)
                        {
                            std::cout << "[" << i + 1 << "] ";
                            myItems[i].ShowStats();
                        }
                        std::cout << "\nWhat will you pick up?\n";
                        std::cin >> choice;
                        while (choice <= 0 || choice > myItems.size() || std::cin.fail())
                        {
                            GameFunction::ClearInputBuffer();
                            std::cout << "Invalid input: ";
                            std::cin >> choice;
                        }
                        GameFunction::ClearInputBuffer();
                        choice = choice - 1;
                        aPlayer.AddItem(choice, myItems[choice], myItems);
                        choice = 0;
                    }
                    else if (choice == 1 && myItems.size() <= 0)
                    {
                        std::cout << "There's nothing to pick up.\n";
                    }

                    if (choice == 2 && myBoons.size() > 0)
                    {
                        system("cls");
                        std::cout << "Boons on floor:\n\n";
                        for (int i = 0; i < myBoons.size(); i++)
                        {
                            std::cout << "[" << i + 1 << "] ";
                            myBoons[i].ShowEffect();
                        }
                        std::cout << "\nWhat will you pick up?\n";
                        std::cin >> choice;
                        while (choice <= 0 || choice > myBoons.size() || std::cin.fail())
                        {
                            GameFunction::ClearInputBuffer();
                            std::cout << "Invalid input: ";
                            std::cin >> choice;
                        }
                        GameFunction::ClearInputBuffer();
                        choice = choice - 1;
                        aPlayer.AddBoon(choice, myBoons[choice], myBoons);
                        choice = 0;
                    }
                    else if (choice == 2 && myBoons.size() <= 0)
                    {
                        std::cout << "There's nothing to pick up.\n";
                    }

                    if (choice == 3 && myChests.size() > 0)
                    {
                        myChests[0].OpenChest(myItems, myBoons);
                        myChests.erase(myChests.begin());
                    }
                    else if (choice == 3 && myChests.size() <= 0)
                    {
                        std::cout << "There are no chests to open.\n";
                    }
                    system("pause");
                }
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

void Room::EnterRoom(Player& aPlayer, std::vector<Room>& someRooms, ItemFactory& anItemFactory)
{
    RoomIntro(aPlayer);
    Battle(aPlayer, anItemFactory);
    if (aPlayer.isAlive())
    {
        for (int i = 0; i < aPlayer.myBoons.size();)
        {
            if (aPlayer.myBoons[i].GetDuration() > 0)
            {
                aPlayer.myBoons[i].DecreaseDuration();
            }
            if (aPlayer.myBoons[i].GetDuration() <= 0)
            {
                aPlayer.myBoons[i].RemoveBoon(&aPlayer);
                aPlayer.myBoons.erase(aPlayer.myBoons.begin() + i);
            }
            else
            {
                i++;
            }
        }
        PostBattle(aPlayer);
        SelectDoor(aPlayer, someRooms);
    }
}
