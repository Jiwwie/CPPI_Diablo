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

int Room::GetEnemyTarget(int aChoice) const
{
    std::cin >> aChoice;
    while (aChoice <= 0 || aChoice > myEnemies.size() || std::cin.fail())
    {
        GameFunction::ClearInputBuffer();
        std::cout << "There's no enemy there...\n ";
        std::cin >> aChoice;
    }
    GameFunction::ClearInputBuffer();
    return aChoice;
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

        std::cout << "Which enemy do you attack?\n";
        chosenEnemy = GetEnemyTarget(chosenEnemy);
        chosenEnemy -= 1;
        aPlayer.DoDamage(myEnemies[chosenEnemy]);
        KillEnemy(chosenEnemy);
        for (int enemies = 0; enemies < myEnemies.size(); enemies++)
        {
            myEnemies[enemies].DoDamage(aPlayer);
        }
        system("pause");
    }

}

void Room::EnterRoom(Player& aPlayer)
{
    int menuChoice;

    Battle(aPlayer);

    system("cls");
    std::cout << "Current room: " << aPlayer.GetCurrentRoom() + 1 << '\n';
    std::cout << "=========================================\n";
    std::cout << "You looked for more enemies in this room.\n";
    std::cout << "But no one came.\n\n";
    std::cout << "What do you want to do?\n";
    std::cout << "[1] Go back || [2] Go foraward || [3] Show stats\n";
    std::cin >> menuChoice;
    while (menuChoice <= 0 || menuChoice > 3 || std::cin.fail())
    {
        GameFunction::ClearInputBuffer();
        std::cout << "[1] or [2] : ";
        std::cin >> menuChoice;
    }
    GameFunction::ClearInputBuffer();

    switch (menuChoice)
    {
        case 1:
        {
            aPlayer.GoPreviousRoom();
            break;
        }
        case 2:
        {
            aPlayer.GoNextRoom();
            break;
        }
        case 3:
        {
            aPlayer.ShowStats();
            system("pause");
            break;
        }
        default:
            break;
    }

}
