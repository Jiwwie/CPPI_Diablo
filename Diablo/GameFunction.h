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
    
    void CreateRooms(std::vector<Room>& someRooms);

    void StartGame(Player& aPlayer, std::vector<Room>& someRooms);

}
