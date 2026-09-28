#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include "Door.h"
#include "Enum.h"
#include "GameFunction.h"

void CreateRooms(std::vector<Room>& someRooms);

int main()
{
    std::vector<Room> rooms;
    Player player;

    CreateRooms(rooms);

    while (player.isAlive() && player.GetCurrentRoom() < rooms.size())
    {

        if (player.GetCurrentRoom() == static_cast<int>(Enum::RoomName::Room46))
        {
            break;
        }

        rooms[player.GetCurrentRoom()].EnterRoom(player, rooms);
    }


    if (rooms[player.GetCurrentRoom()].myEnemies.size() <= 0 && player.isAlive())
    {
        system("cls");
        std::cout << "You win!\n";
    }
    else
    {
        system("cls");
        std::cout << "You died.\n";
    }

    system("pause");

}

void CreateRooms(std::vector<Room>& someRooms)
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

    Door door1(EntranceHall, Courtyard, false);
    Door door2(Courtyard, Parlor, false);
    Door door3(Parlor, Room46, false);

    //Entrance hall
    someRooms[0].SpawnEnemies(1);
    someRooms[0].SetDoors(door1);

    //Courtyard
    someRooms[1].SpawnEnemies(3);
    someRooms[1].SetDoors(door1);
    someRooms[1].SetDoors(door2);

    //Parlor
    someRooms[2].SpawnEnemies(2);
    someRooms[2].SetDoors(door2);
    someRooms[2].SetDoors(door3);

    //Room 46
    someRooms[3].SetDoors(door3);
}

