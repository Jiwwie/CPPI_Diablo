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
    
}
