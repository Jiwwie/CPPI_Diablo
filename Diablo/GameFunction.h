#pragma once
#include "Room.h"
#include "Player.h"

namespace GameFunction
{
    inline void ClearInputBuffer()
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    int GetEnemyTarget(int aChoice, std::vector<Enemy>& someEnemies);
    
    void Battle(Player& aPlayer, std::vector<Room>& someRooms);

}
