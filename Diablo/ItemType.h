#pragma once
#include <string>

class ItemType
{
public:


	void SetStatIndex(int aStatIndex) { myStatIndex = aStatIndex; }
	void SetStatBonus(int aStatBonus) { myStatBonus = aStatBonus; }
	void SetWeight(int aWeight) { myWeight = aWeight; }
	void SetName(std::string aName) { myItemName = aName; }

	int GetWeight() const { return myWeight; }
	int GetStatBonus() const { return myStatBonus; }
	int GetStatIndex() const { return myStatIndex; }
	std::string GetStatStr() const;
	std::string GetName() const { return myItemName; }

private:
	std::string myItemName;
	int myStatIndex;
	int myStatBonus;
	int myWeight;

};

