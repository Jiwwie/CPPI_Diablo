#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include "GameFunction.h"

void DisplayEnemies(std::vector<Enemy>& someEnemies);

int main()
{
    //int currentRoom = 0;
    //std::vector<Room> rooms;

    Player player;
    Room room1;

    room1.SpawnEnemies(3);

    while (room1.myEnemies.size() > 0 && player.isAlive())
    {
        int chosenEnemy = 0;
        std::cout << "Enemies in room: " << room1.myEnemies.size();

        player.ShowStats();
        DisplayEnemies(room1.myEnemies);

        std::cout << "Chose enemy to attack:\n";
        std::cin >> chosenEnemy;
        system("pause");

        player.DoDamage(room1.myEnemies[chosenEnemy]);
    }

    if (room1.myEnemies.size() <= 0)
    {
        std::cout << "You defeated the enemy";
    }
    else
    {
        std::cout << "You died.";
    }

}

void DisplayEnemies(std::vector<Enemy>& someEnemies)
{
    for (int enemyNum = 0; enemyNum < someEnemies.size(); enemyNum++)
    {
        someEnemies[enemyNum].ShowStats();
        std::cout << '\n';
    }
}