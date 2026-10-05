#pragma once
#include "Item.h"

enum class ItemId
{
    MoonPendant,
    RunningShoes,
    SleepingMask,
    BrokenLever,
    MagnifyingGlass,
    LuckyRabbitsFoot,
    CrownOfTheBlueprints,
    KnightsShield
};

class ItemFactory
{
public:

	Item Create(ItemId anId);

private:

};

