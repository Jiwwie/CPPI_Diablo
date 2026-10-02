#pragma once
#include <iostream>
#include "Player.h"
#include "Enum.h"

class Player;

class Item
{
public:
	Item(std::string anItemName, int someWeight, int aStat, int aStatIncrease) :
		myItemName(anItemName),
		myWeight(someWeight),
		myStat(aStat),
		myStatBonus(aStatIncrease)
	{
	};

	void ApplyStat(Player* aPlayer) const;
	void RemoveStat(Player* aPlayer) const;

	void ShowStats() const;

	int GetWeight() const { return myWeight; }
	int GetStatBonus() const { return myStatBonus; }
	int GetStat() const { return myStat; }
	std::string GetName() const { return myItemName; }

private:
	std::string myItemName;
	int myStat;
	int myStatBonus;
	int myWeight;

};

