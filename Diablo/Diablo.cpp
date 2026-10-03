#include <iostream>
#include <vector>
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Room.h"
#include "Door.h"
#include "Enum.h"
#include "Random.h"
#include "GameFunction.h"

int main()
{
    std::vector<Room> rooms;
    GameFunction::CreateRooms(rooms);
    Random random;
    Player player;
    Item gem("Gem", 1, static_cast<int>(Enum::Stat::MaxHealth), 10);
    for (int i = 0; i < random.GetRandomInt(2,5); i++)
    {
        Item key("Key", 1, static_cast<int>(Enum::Stat::Strength), 10);
        player.AddItem(key);
    }

    player.ShowStats();
    player.ShowInventory();
    system("pause");
    system("cls");

    player.AddItem(gem);
    player.ShowStats();
    player.ShowInventory();

    system("pause");

    system("cls");
    player.PromptDrop();
    system("pause");
    player.ShowStats();
    player.ShowInventory();
    system("pause");

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
            GameFunction::StartGame(player, rooms);
            break;
        }
        case 2:
        {
            GameFunction::PickCheats(player);
            GameFunction::StartGame(player, rooms);
            break;
        }
        default:
            break;
    }

    
    if (rooms[player.GetCurrentRoom()].myEnemies.size() <= 0 && player.isAlive())
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


