#include "Boon.h"

//void Boon::ApplyBoon(Player* aPlayer) const

//void Boon::RemoveBoon(Player* aPlayer) const

void Boon::ShowEffect()
{
	if (myDuration == 0)
	{
		std::cout << "BOON: " << myBoonName << " || Duration: Instant" << '\n';
	}
	else
	{
		std::cout << "BOON: " << myBoonName << " || Duration: " << myDuration << '\n';
	}
}