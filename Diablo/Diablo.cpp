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
    Room room;
    Door door(0, 1);
    rooms.push_back(room);
    rooms.push_back(room);
    rooms[0].SpawnEnemies(3);
    rooms[0].AddDoor(door);
    rooms[1].SpawnEnemies(1);
    rooms[1].AddDoor(door);

    while (player.isAlive() && player.GetCurrentRoom() < rooms.size())
    {
        rooms[player.GetCurrentRoom()].EnterRoom(player);

    }


    if (room.myEnemies.size() <= 0)
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You died.\n";
    }

    system("pause");

}

