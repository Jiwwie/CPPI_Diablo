#pragma once

namespace Enum
{
    enum class RoomName
    {
        EntranceHall = 0,
        Courtyard = 1,
        Parlor = 2,
        Room46 = 3
    };

    enum class Stat
    {
        Strength,
        Agility,
        Endurance,
        MaxHealth,
        Defense,
        InventoryCap
    };

    enum class Item
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

    enum class Boon
    {
        Apple,
        Banana,
        ClubSandwich,
        WoodFriedPizza,
        LunchBox
    };
}