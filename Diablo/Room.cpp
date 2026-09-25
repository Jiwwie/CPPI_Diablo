#include "Room.h"
#include "Door.h"
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

void Room::SetDoors(Door& aDoor)
{
    myDoors.push_back(aDoor);
}

void Room::KillEnemy(int anEnemy)
{
	if (!myEnemies[anEnemy].isAlive())
	{
		myEnemies.erase(myEnemies.begin() + anEnemy);
	}
}

int Room::GetTarget(int aChoice) const
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
        chosenEnemy = GetTarget(chosenEnemy);
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

void Room::UseDoor(Player& aPlayer)
{
    int menuChoice;
    system("cls");
    std::cout << "Current room: " << aPlayer.GetCurrentRoom() + 1 << '\n';
    std::cout << "=========================================\n";
    std::cout << "You looked for more enemies in this room.\n";
    std::cout << "But no one came.\n\n";
    std::cout << "What do you want to do?\n";
    for (int i = 0; i < myDoors.size(); i++)
    {
        std::cout << "[" << i + 1 << "] ";
        std::cout << " Door \n";
    }
    std::cin >> menuChoice;
    while (menuChoice <= 0 || menuChoice > myDoors.size() || std::cin.fail())
    {
        GameFunction::ClearInputBuffer();
        std::cout << "Invalid input, try again : ";
        std::cin >> menuChoice;
    }
    GameFunction::ClearInputBuffer();

    aPlayer.SetCurrentRoom(myDoors[menuChoice - 1].EnterDoor(aPlayer.GetCurrentRoom()));

}

void Room::EnterRoom(Player& aPlayer)
{
    Battle(aPlayer);
    
    UseDoor(aPlayer);

}
