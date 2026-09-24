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

void GameFunction::Battle(Player& aPlayer, std::vector<Room>& someRooms)
{
    while (someRooms[aPlayer.GetCurrentRoom()].myEnemies.size() > 0 && aPlayer.isAlive())
    {
        int chosenEnemy = 0;
        system("cls");
        aPlayer.ShowStats();
        std::cout << "Enemies in room: " << someRooms[aPlayer.GetCurrentRoom()].myEnemies.size();

        std::cout << "\n\n";
        someRooms[aPlayer.GetCurrentRoom()].DisplayEnemies();

        std::cout << "Chose enemy to attack:\n";
        chosenEnemy = GetEnemyTarget(chosenEnemy, someRooms[aPlayer.GetCurrentRoom()].myEnemies);
        chosenEnemy -= 1;
        aPlayer.DoDamage(someRooms[aPlayer.GetCurrentRoom()].myEnemies[chosenEnemy]);
        for (int enemies = 0; enemies < someRooms[aPlayer.GetCurrentRoom()].myEnemies.size() ; enemies++)
        {
            someRooms[aPlayer.GetCurrentRoom()].myEnemies[enemies].DoDamage(aPlayer);
        }
        system("pause");
        someRooms[aPlayer.GetCurrentRoom()].KillEnemy(chosenEnemy);
    }

}

