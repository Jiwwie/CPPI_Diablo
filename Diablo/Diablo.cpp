#include <iostream>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include "Door.h"
#include "Enum.h"
#include "GameFunction.h"

int main()
{
    std::vector<Room> rooms;
    GameFunction::CreateRooms(rooms);
    Player player;

    int startGame = 0;

    std::cout << "== Welcome to Diablue ==\n";
    std::cout << "Get to \"Room 46\"!!! \n\n";
    std::cout << "[" << 1 << "]" << " Start game ->\n\n";
    std::cout << "[" << 2 << "]" << " Activate god mode ->\n\n";

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
            int activateCheats = 0;
            system("cls");
            std::cout << "[" << 1 << "]" << " Activate UNDEAD\n\n";
            std::cout << "[" << 2 << "]" << " Activate GIANTS STRENGTH\n\n";
            std::cout << "[" << 3 << "]" << " Activate BOTH\n\n";

            std::cin >> activateCheats;
            while (startGame <= 0 || startGame > 3 || std::cin.fail())
            {
                GameFunction::ClearInputBuffer();
                std::cout << "Invalid input, try again : ";
                std::cin >> startGame;
            }
            GameFunction::ClearInputBuffer();

            switch (activateCheats)
            {
                case 1:
                {
                    player.SetUndead();
                    break;
                }
                case 2:
                {
                    player.SetGiantsStrength();
                    break;
                }
                case 3:
                {
                    player.SetUndead();
                    player.SetGiantsStrength();
                    break;
                }
                default:
                    break;
            }

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


