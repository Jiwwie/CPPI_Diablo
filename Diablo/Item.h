#pragma once
#include <iostream>

class Item
{
public:
	Item(std::string anItemName, int someWeight) :
		myItemName(anItemName),
		myWeight(someWeight)
	{
	};

	void ShowStats() const;

	int GetWeight() const { return myWeight; }

private:
	std::string myItemName;
	int myWeight;

};

