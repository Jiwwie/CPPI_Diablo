#include "Room.h"
#include "Player.h"
#include "GameFunction.h"

void Room::DisplayEnemies() const
{
	for (int enemyNum = 0; enemyNum < myEnemies.size(); enemyNum++)
	{
		std::cout << "[" << enemyNum + 1 << "] "; 
		myEnemies[enemyNum].ShowStats();
		std::cout << '\n';
	}
}

void Room::SpawnEnemies(int anAmount)
{
	for (int enemyCount = 0; enemyCount < anAmount; enemyCount++)
	{
		Enemy enemy(20, 5);
		myEnemies.push_back(enemy);
	}
}

void Room::KillEnemy(int anEnemy)
{
	if (!myEnemies[anEnemy].isAlive())
	{
		myEnemies.erase(myEnemies.begin() + anEnemy);
	}
}

void Room::Battle(Player& aPlayer, std::vector<Room>& someRooms)
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
        chosenEnemy = GameFunction::GetEnemyTarget(chosenEnemy, someRooms[aPlayer.GetCurrentRoom()].myEnemies);
        chosenEnemy -= 1;
        aPlayer.DoDamage(someRooms[aPlayer.GetCurrentRoom()].myEnemies[chosenEnemy]);
        for (int enemies = 0; enemies < someRooms[aPlayer.GetCurrentRoom()].myEnemies.size(); enemies++)
        {
            someRooms[aPlayer.GetCurrentRoom()].myEnemies[enemies].DoDamage(aPlayer);
        }
        system("pause");
        someRooms[aPlayer.GetCurrentRoom()].KillEnemy(chosenEnemy);
    }

}
