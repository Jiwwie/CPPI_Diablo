#include <iostream>
#include "Player.h"
#include "Enemy.h"

int main()
{
    Player player;
    Enemy enemy(50, 5);

    player.ShowStats();

    enemy.DoDamage(player);

    player.ShowStats();
}