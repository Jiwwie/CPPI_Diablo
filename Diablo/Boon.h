#pragma once
#include <iostream>
#include "Player.h"

class Boon
{
public:
	Boon(std::string aName, int aDuration, int anEffect) :
		myBoonName(aName),
		myDuration(aDuration),
		myEffect(anEffect)
	{
	};

	void ApplyBoon(Player* aPlayer, int boonIndex) const;
	//void RemoveBoon(Player* aPlayer) const;
	void ShowEffect();

	std::string GetName() const { return myBoonName; };

private:
	std::string myBoonName;
	int myDuration;
	int myEffect;
};

