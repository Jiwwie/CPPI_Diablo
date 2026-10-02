#pragma once
#include <iostream>
#include <random>
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

    void PickCheats(Player& aPlayer);

    void StartGame(Player& aPlayer, std::vector<Room>& someRooms);

}
