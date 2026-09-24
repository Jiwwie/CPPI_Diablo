#include "GameFunction.h"
#include "Room.h"
#include "Player.h"

int GameFunction::GetEnemyTarget(int aChoice, std::vector<Enemy>& someEnemies)
{
    std::cin >> aChoice;
    while (aChoice <= 0 || aChoice > someEnemies.size() || std::cin.fail())
    {
        ClearInputBuffer();
        std::cout << "Invalid option. ";
        std::cin >> aChoice;
    }
    ClearInputBuffer();
    return aChoice;
}