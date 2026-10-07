#include "GameFunction.h"
#include "Room.h"
#include "Chest.h"
#include "Enum.h"
#include "Player.h"
class ItemFactory;

void GameFunction::CreateRooms(std::vector<Room>& someRooms, ItemFactory& anItemFactory)
{
    int EntranceHall = static_cast<int>(Enum::RoomName::EntranceHall);
    int Courtyard = static_cast<int>(Enum::RoomName::Courtyard);
    int Parlor = static_cast<int>(Enum::RoomName::Parlor);
    int Room46 = static_cast<int>(Enum::RoomName::Room46);

    Room entranceHall("Entrance Hall");
    Room courtyard("Courtyard");
    Room parlor("Parlor");
    Room room46("Room 46");

    someRooms.push_back(entranceHall);
    someRooms.push_back(courtyard);
    someRooms.push_back(parlor);
    someRooms.push_back(room46);

    static Door door1(EntranceHall, Courtyard, true);
    static Door door2(Courtyard, Parlor, false);
    static Door door3(Parlor, Room46, true);

    //Entrance hall
    someRooms[0].SpawnEnemies(1);
    someRooms[0].SpawnChests(1, anItemFactory);
    someRooms[0].SetDoors(&door1);

    //Courtyard
    someRooms[1].SpawnEnemies(3);
    someRooms[1].SetDoors(&door1);
    someRooms[1].SetDoors(&door2);

    //Parlor
    someRooms[2].SpawnEnemies(2);
    someRooms[2].SpawnChests(3, anItemFactory);
    someRooms[2].SetDoors(&door2);
    someRooms[2].SetDoors(&door3);

    //Room 46
    someRooms[3].SetDoors(&door3);
}

void GameFunction::PickCheats(Player& aPlayer)
{
    int activateCheats = 0;
    system("cls");
    std::cout << "[1] Activate UNDEAD\n\n";
    std::cout << "[2] Activate GIANTS STRENGTH\n\n";
    std::cout << "[3] Activate BOTH\n\n";

    std::cin >> activateCheats;
    while (activateCheats <= 0 || activateCheats > 3 || std::cin.fail())
    {
        GameFunction::ClearInputBuffer();
        std::cout << "Invalid input, try again : ";
        std::cin >> activateCheats;
    }
    GameFunction::ClearInputBuffer();

    switch (activateCheats)
    {
    case 1:
    {
        aPlayer.SetUndead();
        break;
    }
    case 2:
    {
        aPlayer.SetGiantsStrength();
        break;
    }
    case 3:
    {
        aPlayer.SetUndead();
        aPlayer.SetGiantsStrength();
        break;
    }
    default:
        break;
    }
}

void GameFunction::StartGame(Player& aPlayer, std::vector<Room>& someRooms, ItemFactory& anItemFactory)
{
    while (aPlayer.isAlive() && aPlayer.GetCurrentRoom() < someRooms.size())
    {
        someRooms[aPlayer.GetCurrentRoom()].EnterRoom(aPlayer, someRooms, anItemFactory);
        
        if (aPlayer.GetCurrentRoom() == static_cast<int>(Enum::RoomName::Room46))
        {
            Room::RoomIntro(aPlayer);
            break;
        }
        
    }
}