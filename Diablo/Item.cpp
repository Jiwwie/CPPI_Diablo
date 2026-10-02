#include "Item.h"
#include "Player.h"

void Item::ApplyStat(Player* aPlayer) const
{
	aPlayer->UpdateStats(myStat, myStatBonus);
}

void Item::RemoveStat(Player* aPlayer) const
{
	aPlayer->UpdateStats(myStat, -myStatBonus);
}

std::string Item::GetStatStr() const
{
	Enum::Stat stat = static_cast<Enum::Stat>(myStat);
	std::string statStr = "???";

	switch (stat)
	{
		case Enum::Stat::Strength:
		{
			statStr = "Strength";
			return statStr;
			break;
		}
		case Enum::Stat::Agility:
		{
			statStr = "Agility";
			return statStr;
			break;
		}
		case Enum::Stat::Endurance:
		{
			statStr = "Endurance";
			return statStr;
			break;
		}
		case Enum::Stat::MaxHealth:
		{
			statStr = "Max Health";
			return statStr;
			break;
		}
		case Enum::Stat::Defense:
		{
			statStr = "Defense";
			return statStr;
			break;
		}
		case Enum::Stat::InventoryCap:
		{
			statStr = "Inventory Capacity";
			return statStr;
			break;
		}
		default:
			return statStr;
			break;
	}
}

void Item::ShowStats() const
{
	std::cout << myItemName << " || Bonus: " << myStatBonus << " " << GetStatStr() << " || Weight: " << myWeight << '\n';
}
