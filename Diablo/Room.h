#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Door.h"

class Room
{
	public:
		Room(std::string aRoomName) :
			myRoomName(aRoomName)
		{
		};


		std::vector<Enemy> myEnemies;
		std::vector<Door> myDoors;

		void DisplayEnemies() const;
		void SpawnEnemies(int anAmount);
		void SetDoors(Door& aDoor);
		void KillEnemy(int anEnemy);
		int GetTarget(int aChoice) const;

		void Battle(Player& aPlayer);

		void UseDoor(Player& aPlayer, std::vector<Room>& someRooms);
	 
		void EnterRoom(Player& aPlayer, std::vector<Room>& someRooms);

		std::string GetRoomName() { return myRoomName; };

	private:
		std::string myRoomName;
};

