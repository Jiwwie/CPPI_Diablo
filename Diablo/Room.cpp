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

void Room::Battle(Player& aPlayer)
{
    while (myEnemies.size() > 0 && aPlayer.isAlive())
    {
        int chosenEnemy = 0;
        system("cls");
        aPlayer.ShowStats();
        std::cout << "Current room: " << aPlayer.GetCurrentRoom() + 1 << '\n';
        std::cout << "Enemies in room: " << myEnemies.size();

        std::cout << "\n\n";
        DisplayEnemies();

        std::cout << "Chose enemy to attack:\n";
        chosenEnemy = GameFunction::GetEnemyTarget(chosenEnemy, myEnemies);
        chosenEnemy -= 1;
        aPlayer.DoDamage(myEnemies[chosenEnemy]);
        for (int enemies = 0; enemies < myEnemies.size(); enemies++)
        {
            myEnemies[enemies].DoDamage(aPlayer);
        }
        system("pause");
        KillEnemy(chosenEnemy);
    }

}
