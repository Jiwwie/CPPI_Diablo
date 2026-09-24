#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"

class Room
{
public:
	std::vector<Enemy> myEnemies;

	void SpawnEnemies(int anAmount)
	{
		for (int enemyCount = 0; enemyCount < anAmount; enemyCount++)
		{
			Enemy enemy(40, 5);
			myEnemies.push_back(enemy);
		}
	}

private:

};

