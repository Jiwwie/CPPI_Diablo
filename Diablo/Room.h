#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Door.h"
#include "Item.h"
#include "Boon.h"
#include "Chest.h"
#include "Random.h"
class ItemFactory;
class EnemyFactory;

class Room
{
	public:
		Room(std::string aRoomName) :
			myRoomName(aRoomName)
		{
		};

		
		void DisplayEnemies() const;
		void SpawnEnemies(int anAmount, EnemyFactory& anEnemyFactory);
		void SpawnChests(int anAmount, ItemFactory& anItemFactory);
		void SetDoors(Door* aDoor);
		
		void KillEnemy(int anEnemy, ItemFactory& anItemFactory);
		void SpawnEnemyDrop(int anItemIndex, ItemFactory& anItemFactory);
		int GetTarget(int aChoice) const;

		static void RoomIntro(Player& aPlayer);
		void Battle(Player& aPlayer, ItemFactory& anItemFactory);
		void PostBattle(Player& aPlayer);
		void SelectDoor(Player& aPlayer, std::vector<Room>& someRooms);
	 
		void EnterRoom(Player& aPlayer, std::vector<Room>& someRooms, ItemFactory& anItemFactory);

		std::string GetRoomName() const { return myRoomName; };
		size_t GetRoomSize() const { return myEnemies.size(); };

	private:
		std::string myRoomName;
		Random myRnd;

		std::vector<Chest> myChests;
		std::vector<Enemy> myEnemies;
		std::vector<Boon> myBoons;
		std::vector<Item> myItems;
		std::vector<Door*> myDoors;
};

