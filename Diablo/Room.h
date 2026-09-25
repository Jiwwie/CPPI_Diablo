#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Door.h"

class Room
{
public:
	std::vector<Enemy> myEnemies;
	std::vector<Door> myDoors;

	void DisplayEnemies() const;
	void SpawnEnemies(int anAmount);
	void SetDoors(Door& aDoor);
	void KillEnemy(int anEnemy);
	int GetTarget(int aChoice) const;

	void Battle(Player& aPlayer);

	void UseDoor(Player& aPlayer);
	 
	void EnterRoom(Player& aPlayer);

private:

};

