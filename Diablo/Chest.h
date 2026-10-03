#pragma once


class Chest
{
public:
	Chest(int anItemAmount, int aSpellAmount) :
		myItemAmount(anItemAmount),
		mySpellAmount(aSpellAmount)
	{
	};

private:
	int myItemAmount;
	int mySpellAmount;

};

