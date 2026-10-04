#pragma once
#include "Item.h"
#include "Boon.h"
#include "Random.h"

class Chest
{
public:
	Chest(int anItemAmount, int aBoonAmount) :
		myItemAmount(anItemAmount),
		myBoonAmount(aBoonAmount)
	{
		RandomizeChestContent();
	};

	std::vector<Item> myItems;
	std::vector<Boon> myBoons;

	void OpenChest(std::vector<Item>& someItems, std::vector<Boon>& someBoons);
	void RandomizeChestContent();
	void SpawnChestItems(int anItemIndex);
	void SpawnChestBoons(int aBoonIndex);

private:
	Random myRnd;
	int myItemAmount;
	int myBoonAmount;

};

