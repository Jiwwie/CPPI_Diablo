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
	void KillEnemy(int anEnemy);
	int GetTarget(int aChoice) const;

	void AddDoor(Door aDoor);

	void Battle(Player& aPlayer);

	void EnterRoom(Player& aPlayer);

private:
	Door* myDoorPtr;

};

