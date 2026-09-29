#include "GameFunction.h"
#include "Room.h"
#include "Enum.h"
#include "Player.h"

void GameFunction::CreateRooms(std::vector<Room>& someRooms)
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

    //static Door cheatDoor(EntranceHall, Room46, true);

    //Entrance hall
    someRooms[0].SpawnEnemies(1);
    someRooms[0].SetDoors(&door1);
    //someRooms[0].SetDoors(&cheatDoor);

    //Courtyard
    someRooms[1].SpawnEnemies(3);
    someRooms[1].SetDoors(&door1);
    someRooms[1].SetDoors(&door2);

    //Parlor
    someRooms[2].SpawnEnemies(2);
    someRooms[2].SetDoors(&door2);
    someRooms[2].SetDoors(&door3);

    //Room 46
    someRooms[3].SetDoors(&door3);
}

void GameFunction::StartGame(Player& aPlayer, std::vector<Room>& someRooms)
{
    while (aPlayer.isAlive() && aPlayer.GetCurrentRoom() < someRooms.size())
    {
        if (aPlayer.GetCurrentRoom() == static_cast<int>(Enum::RoomName::Room46))
        {
            break;
        }

        someRooms[aPlayer.GetCurrentRoom()].EnterRoom(aPlayer, someRooms);
    }
}