#pragma once
#include <iostream>
#include "Player.h"
#include "Enum.h"
#include "ItemType.h"

class Item
{
public:
	Item(const ItemType& anItemType) :
		myItemType(&anItemType)
	{
	};

	void ApplyStat(Player* aPlayer) const;
	void RemoveStat(Player* aPlayer) const;

	int GetStatBonus() const { return myItemType->GetStatBonus(); }
	int GetStatIndex() const { return myItemType->GetStatIndex(); }
	int GetWeight() const { return myItemType->GetWeight(); }
	std::string GetStatStr() const { return myItemType->GetStatStr(); }
	std::string GetName() const { return myItemType->GetName(); }

	void ShowStats() const;



private:
	const ItemType* myItemType;

};

