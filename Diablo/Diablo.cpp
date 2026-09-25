#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include "Door.h"
#include "GameFunction.h"

int main()
{
    std::vector<Room> rooms;

    Player player;
    Room entranceHall("Entrance Hall");
    Room courtyard("Courtyard");
    Room parlor("Parlor");
    Door door(0, 1, false);
    Door door2(1, 2, false);
    rooms.push_back(entranceHall);
    rooms.push_back(courtyard);
    rooms[0].SpawnEnemies(1);
    rooms[0].SetDoors(door);
    rooms[1].SpawnEnemies(3);
    rooms[1].SetDoors(door);

    while (player.isAlive() && player.GetCurrentRoom() < rooms.size())
    {
        rooms[player.GetCurrentRoom()].EnterRoom(player, rooms);
    }


    if (rooms[player.GetCurrentRoom()].myEnemies.size() <= 0)
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You died.\n";
    }

    system("pause");

}

