#pragma once
#include <iostream>
#include <random>
#include "Room.h"
#include "Player.h"

class ItemFactory;

namespace GameFunction
{      
    inline void ClearInputBuffer()
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    
    void CreateRooms(std::vector<Room>& someRooms, ItemFactory& anItemFactory);

    void PickCheats(Player& aPlayer);

    void StartGame(Player& aPlayer, std::vector<Room>& someRooms, ItemFactory& anItemFactory);

}
