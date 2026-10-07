#pragma once
#include "Item.h"
#include "Boon.h"
#include "Random.h"
class ItemFactory;

class Chest
{
public:
	Chest(int anItemAmount, int aBoonAmount, ItemFactory& anItemFactory);

	std::vector<Item> myItems;
	std::vector<Boon> myBoons;

	void OpenChest(std::vector<Item>& someItems, std::vector<Boon>& someBoons);
	void RandomizeChestContent(ItemFactory& anItemFactory);
	void SpawnChestItems(int anItemIndex, ItemFactory& anItemFactory);
	void SpawnChestBoons(int aBoonIndex);

private:
	Random myRnd;
	int myItemAmount;
	int myBoonAmount;

};

