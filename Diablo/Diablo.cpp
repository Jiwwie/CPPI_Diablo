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
    Room room1;
    Room room2;
    Door door(0, 1, false);
    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms[0].SpawnEnemies(3);
    rooms[0].SetDoors(door);
    rooms[1].SpawnEnemies(1);
    rooms[1].SetDoors(door);

    while (player.isAlive() && player.GetCurrentRoom() < rooms.size())
    {
        rooms[player.GetCurrentRoom()].EnterRoom(player);

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

