#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Door.h"
#include "Item.h"
#include "Chest.h"
#include "Random.h"

class Room
{
	public:
		Room(std::string aRoomName) :
			myRoomName(aRoomName)
		{
		};

		Random myRnd;
		std::vector<Enemy> myEnemies;
		std::vector<Door*> myDoors;
		std::vector<Item> myItems;
		std::vector<Chest> myChests;
		
		void DisplayEnemies() const;
		void SpawnEnemies(int anAmount);
		void SpawnChests(int anAmount);
		void SetDoors(Door* aDoor);
		
		void KillEnemy(int anEnemy);
		void SpawnEnemyDrop(int anItemIndex);
		int GetTarget(int aChoice) const;

		static void RoomIntro(Player& aPlayer);
		void Battle(Player& aPlayer);
		void PostBattle(Player& aPlayer);
		void SelectDoor(Player& aPlayer, std::vector<Room>& someRooms);
	 
		void EnterRoom(Player& aPlayer, std::vector<Room>& someRooms);

		std::string GetRoomName() const { return myRoomName; };

	private:
		std::string myRoomName;
};

