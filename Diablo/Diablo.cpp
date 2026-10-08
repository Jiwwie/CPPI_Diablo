#include <iostream>
#include <vector>
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Room.h"
#include "Door.h"
#include "Enum.h"
#include "Random.h"
#include "ItemFactory.h"
#include "EnemyFactory.h"
#include "GameFunction.h"

int main()
{
    std::vector<Room> rooms;
    ItemFactory itemFactory;
    itemFactory.Init();
    EnemyFactory enemyFactory;
    enemyFactory.Init();
    Random random;
    Player player;
    GameFunction::CreateRooms(rooms, itemFactory, enemyFactory);
    
    int startGame = 0;

    std::cout << "== Welcome to Diablue ==\n";
    std::cout << "\nYour goal is to navigate the mansion and get to \"Room 46\". \n\n";
    std::cout << "[1] Start game ->\n\n";
    std::cout << "[2] Activate god mode ->\n\n";

    std::cin >> startGame;
    while (startGame <= 0 || startGame > 2 || std::cin.fail())
    {
        GameFunction::ClearInputBuffer();
        std::cout << "Invalid input, try again : ";
        std::cin >> startGame;
    }
    GameFunction::ClearInputBuffer();

    switch (startGame)
    {
        case 1:
        {
            GameFunction::StartGame(player, rooms, itemFactory);
            break;
        }
        case 2:
        {
            GameFunction::PickCheats(player);
            GameFunction::StartGame(player, rooms, itemFactory);
            break;
        }
        default:
            break;
    }

    
    if (rooms[player.GetCurrentRoom()].GetRoomSize() <= 0 && player.isAlive())
    {
        system("cls");
        std::cout << "You reached Room 46!\n";
        std::cout << "Victory...!\n";
    }
    else
    {
        system("cls");
        std::cout << "The enemy deals a final blow...\n";
        std::cout << "You died! :(\n";
    }

    system("pause");

}


