#pragma once
#include "Item.h"
#include "Random.h"

class Chest
{
public:
	Chest(int anItemAmount, int aSpellAmount) :
		myItemAmount(anItemAmount),
		mySpellAmount(aSpellAmount)
	{
	};

	std::vector<Item> myItems;

	void RandomizeChestItems();
	void SpawnChestItems(int anItemIndex);

private:
	Random myRnd;
	int myItemAmount;
	int mySpellAmount;

};

