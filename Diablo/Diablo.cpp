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
    Player player(10, 6, 3);
    Player cheater(9999, 9999, 9999);

    int startGame = 0;

    std::cout << "== Welcome to Diablue ==\n\n";
    std::cout << "[" << 1 << "]" << " Start game ->\n\n";
    std::cout << "[" << 2 << "]" << " Activate god mode ->\n\n";

    std::cin >> startGame;

    switch (startGame)
    {
        case 1:
        {
            while (player.isAlive() && player.GetCurrentRoom() < rooms.size())
            {
                if (player.GetCurrentRoom() == static_cast<int>(Enum::RoomName::Room46))
                {
                    break;
                }

                rooms[player.GetCurrentRoom()].EnterRoom(player, rooms);
            }
            break;
        }
        case 2:
        {
            while (cheater.isAlive() && cheater.GetCurrentRoom() < rooms.size())
            {
                if (cheater.GetCurrentRoom() == static_cast<int>(Enum::RoomName::Room46))
                {
                    break;
                }

                rooms[cheater.GetCurrentRoom()].EnterRoom(cheater, rooms);
            }
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


