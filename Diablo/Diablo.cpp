#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include "GameFunction.h"

int main()
{
    std::vector<Room> rooms;

    Player player;
    Room room;
    rooms.push_back(room);
    rooms.push_back(room);
    rooms[0].SpawnEnemies(3);
    rooms[1].SpawnEnemies(1);

    rooms[player.GetCurrentRoom()].Battle(player);
    player.SetCurrentRoom();
    rooms[player.GetCurrentRoom()].Battle(player);


    if (room.myEnemies.size() <= 0)
    {
        std::cout << "You defeated the enemies\n";
    }
    else
    {
        std::cout << "You died.\n";
    }

    system("pause");

}

