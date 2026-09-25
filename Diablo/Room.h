#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"

class Room
{
public:
	std::vector<Enemy> myEnemies;

	void DisplayEnemies() const;
	void SpawnEnemies(int anAmount);
	void KillEnemy(int anEnemy);

	int GetEnemyTarget(int aChoice) const;

	void Battle(Player& aPlayer);

	void EnterRoom(Player& aPlayer);

private:

};

