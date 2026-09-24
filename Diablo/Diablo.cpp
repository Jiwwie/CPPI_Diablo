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


    std::cout << "Current room: " << player.GetCurrentRoom() + 1 << '\n';
    GameFunction::Battle(player, rooms);
    player.SetCurrentRoom();
    std::cout << "Current room: " << player.GetCurrentRoom() + 1 << '\n';
    GameFunction::Battle(player, rooms);


    if (room.myEnemies.size() <= 0)
    {
        std::cout << "You defeated the enemies";
    }
    else
    {
        std::cout << "You died.";
    }

    system("pause");

}

