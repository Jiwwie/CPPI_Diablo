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
    Room room1;
    rooms.push_back(room1);
    rooms[0].SpawnEnemies(3);

    GameFunction::Battle(player, rooms);

    if (room1.myEnemies.size() <= 0)
    {
        std::cout << "You defeated the enemy";
    }
    else
    {
        std::cout << "You died.";
    }

}

