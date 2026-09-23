#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Room.h"

int main()
{
    int currentRoom = 0;
    std::vector<Room> rooms;

    Player player;
    Enemy enemy(50, 5);

    player.ShowStats();

    enemy.DoDamage(player);

    player.ShowStats();
}