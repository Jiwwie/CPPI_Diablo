#include "Boon.h"
#include "Enum.h"

void Boon::ApplyBoon(Player* aPlayer, int boonIndex) const
{
	Enum::Boon boon = static_cast<Enum::Boon>(boonIndex);
	switch (boon)
	{
		case Enum::Boon::Apple:
		{
			aPlayer->HealPlayer(10);
			break;
		}
		case Enum::Boon::Banana:
		{
			aPlayer->HealPlayer(12);
			break;
		}
		case Enum::Boon::ClubSandwich:
		{
			aPlayer->HealPlayer(12);
			break;
		}
		case Enum::Boon::WoodFriedPizza:
		{
			aPlayer->HealPlayer(12);
			break;
		}
		case Enum::Boon::LunchBox:
		{
			aPlayer->HealPlayer(12);
			break;
		}

		default:
			break;
	}
}

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