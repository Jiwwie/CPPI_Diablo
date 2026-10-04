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

	void ApplyBoon(Player* aPlayer) const;
	void RemoveBoon(Player* aPlayer) const;
	void ShowEffect();

	std::string GetName() const { return myBoonName; };
	int GetDuration() const { return myDuration; };
	void DecreaseDuration() { myDuration = myDuration - 1; }

private:
	std::string myBoonName;
	int myDuration;
	int myEffect;
};

