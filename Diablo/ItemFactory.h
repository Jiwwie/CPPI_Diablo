#pragma once
#include <array>
#include "ItemType.h"

enum class ItemId
{
    MoonPendant,
    RunningShoes,
    SleepingMask,
    BrokenLever,
    MagnifyingGlass,
    LuckyRabbitsFoot,
    CrownOfTheBlueprints,
    KnightsShield,

	Count
};

class ItemFactory
{
public:

    void Init();
	Item Create(const ItemId anId) const;

private:
    std::array<ItemType, static_cast<int>(ItemId::Count)> myItemTypes;
};

