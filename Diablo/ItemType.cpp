#include <iostream>
#include "ItemType.h"
#include "Item.h"


std::string ItemType::GetStatStr() const
{
	Enum::Stat stat = static_cast<Enum::Stat>(myStatIndex);
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
