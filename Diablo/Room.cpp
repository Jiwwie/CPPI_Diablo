#include "Room.h"
#include "Door.h"
#include "Player.h"
#include "Enum.h"
#include "Random.h"
#include "Consts.h"
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

    int enemyDrop = myRnd.GetRandomInt(0, 1);
    if (enemyDrop == 1)
    {
        int rndItem = (myRnd.GetRandomInt(0, 7));
        std::cout << "Enemy dropped an item\n";
        SpawnEnemyDrop(rndItem);
        std::cout << rndItem;
    }

}

void Room::SpawnEnemyDrop(int anItemIndex)
{
    Enum::Item item = static_cast<Enum::Item>(anItemIndex);

        switch (item)
        {
            case Enum::Item::MoonPendant:
            {
                Item pendant("Moon Pendant", Const::WEIGHT_MEDIUM, static_cast<int>(Enum::Stat::MaxHealth), 25);
                myItems.push_back(pendant);
                break;
            }
            case Enum::Item::RunningShoes:
            {
                Item shoes("Running Shoes", Const::WEIGHT_MEDIUM, static_cast<int>(Enum::Stat::Agility), 2);
                myItems.push_back(shoes);
                break;
            }
            case Enum::Item::SleepingMask:
            {
                Item mask("Sleeping Mask", Const::WEIGHT_LIGHT, static_cast<int>(Enum::Stat::Defense), 10);
                myItems.push_back(mask);
                break;
            }
            case Enum::Item::BrokenLever:
            {
                Item lever("Broken Lever", Const::WEIGHT_HEAVY, static_cast<int>(Enum::Stat::Strength), 3);
                myItems.push_back(lever);
                break;
            }
            case Enum::Item::MagnifyingGlass:
            {
                Item glass("Magnifying Glass", Const::WEIGHT_MEDIUM, static_cast<int>(Enum::Stat::Endurance), 1);
                myItems.push_back(glass);
                break;
            }
            case Enum::Item::LuckyRabbitsFoot:
            {
                Item foot("Lucky Rabbit's Foot", Const::WEIGHT_LIGHT, static_cast<int>(Enum::Stat::Strength), 1);
                myItems.push_back(foot);
                break;
            }
            case Enum::Item::CrownOfTheBlueprints:
            {
                Item crown("Crown of the Blueprints", Const::WEIGHT_VERY_HEAVY, static_cast<int>(Enum::Stat::Strength), 5);
                myItems.push_back(crown);
                break;
            }
            case Enum::Item::KnightsShield:
            {
                Item shield("Knight's Shield", Const::WEIGHT_VERY_HEAVY, static_cast<int>(Enum::Stat::Endurance), 5);
                myItems.push_back(shield);
                break;
            }
            default:
                break;
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
                aPlayer.ShowStats();
                aPlayer.ShowInventory();
                system("pause");
                break;
            }
            case 2:
            {
                choice = 0;
                while (choice != 2)
                {
                    system("cls");
                    for (int i = 0; i < myItems.size(); i++)
                    {
                        std::cout << "[" << i + 1 << "] ";
                        myItems[i].ShowStats();
                    }
                    std::cout << "What do you want to do?\n";
                    std::cout << "[1] Pick something up\n";
                    std::cout << "[2] Continue\n";
                    std::cin >> choice;
                    while (choice <= 0 || choice > 2 || std::cin.fail())
                    {
                        GameFunction::ClearInputBuffer();
                        std::cout << "Invalid input: ";
                        std::cin >> choice;
                    }
                    GameFunction::ClearInputBuffer();

                    if (choice == 1 && myItems.size() > 0)
                    {
                        std::cout << "What will you pick up?\n";
                        std::cin >> choice;
                        while (choice <= 0 || choice > myItems.size() || std::cin.fail())
                        {
                            GameFunction::ClearInputBuffer();
                            std::cout << "Invalid input: ";
                            std::cin >> choice;
                        }
                        GameFunction::ClearInputBuffer();
                        aPlayer.AddItem(choice-1, myItems[choice - 1], myItems);
                        choice = 0;
                    }
                    else if (choice == 1 && myItems.size() <= 0)
                    {
                        std::cout << "There's nothing to pick up.\n";
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
