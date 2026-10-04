#include "Boon.h"
#include "Enum.h"

void Boon::ApplyBoon(Player* aPlayer) const
{
	Enum::Boon boon = static_cast<Enum::Boon>(myEffect);
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
			aPlayer->HealPlayer(25);
			aPlayer->ModifyStrength(2);
			break;
		}
		case Enum::Boon::WoodFriedPizza:
		{
			aPlayer->HealPlayer(40);
			aPlayer->ModifyStrength(10);
			break;
		}
		case Enum::Boon::LunchBox:
		{
			aPlayer->HealPlayer(15);
			aPlayer->ModifyStrength(3);
			break;
		}
		default:
			break;
	}
}

void Boon::RemoveBoon(Player* aPlayer) const
{
	Enum::Boon boon = static_cast<Enum::Boon>(myEffect);
	switch (boon)
	{
	case Enum::Boon::Apple:
	{	
		break;
	}
	case Enum::Boon::Banana:
	{
		break;
	}
	case Enum::Boon::ClubSandwich:
	{
		aPlayer->ModifyStrength(-2);
		break;
	}
	case Enum::Boon::WoodFriedPizza:
	{
		aPlayer->ModifyStrength(-10);
		break;
	}
	case Enum::Boon::LunchBox:
	{
		aPlayer->ModifyStrength(-3);
		break;
	}
	default:
		break;
	}
}
 
void Boon::ShowEffect() const
{
	if (myDuration == 0)
	{
		std::cout << "BOON: " << myBoonName << " || Effect: " << GetEffectStr() << " || Duration: Instant" << '\n';
	}
	else
	{
		std::cout << "BOON: " << myBoonName << " || Effect: " << GetEffectStr() << " || Duration: " << myDuration << '\n';
	}
}

std::string Boon::GetEffectStr() const
{
	Enum::Boon boon = static_cast<Enum::Boon>(myEffect);

	switch (boon)
	{
		case Enum::Boon::Apple:
		{
			return "Heals 10 HP";
			break;
		}
		case Enum::Boon::Banana:
		{
			return "Heals 12 HP";
			break;
		}
		case Enum::Boon::ClubSandwich:
		{
			return "Heals 25 HP, +2 Strength";
			break;
		}
		case Enum::Boon::WoodFriedPizza:
		{
			return "Heals 40 HP, +10 Strength";
			break;
		}
		case Enum::Boon::LunchBox:
		{
			return "Heals 15 HP, +3 Strength";
			break;
		}
		default:                         
			return "???";
			break;
	}
}