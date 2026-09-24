#pragma once
#include "Room.h"
#include "Player.h"

namespace GameFunction
{
	inline void Battle(Player& aPlayer, std::vector<Room> someRooms)
	{
        while (someRooms[aPlayer.GetCurrentRoom()].myEnemies.size() > 0 && aPlayer.isAlive())
        {
            int chosenEnemy = 0;
            std::cout << "Enemies in room: " << someRooms[aPlayer.GetCurrentRoom()].myEnemies.size();

            aPlayer.ShowStats();
            someRooms[aPlayer.GetCurrentRoom()].DisplayEnemies();

            std::cout << "Chose enemy to attack:\n";
            std::cin >> chosenEnemy;
            system("pause");

            aPlayer.DoDamage(someRooms[aPlayer.GetCurrentRoom()].myEnemies[chosenEnemy]);
            someRooms[aPlayer.GetCurrentRoom()].KillEnemy(chosenEnemy);
        }

	}


}
