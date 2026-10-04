#include "Chest.h"
#include "Random.h"
#include "Consts.h"
#include "Enum.h"
#include "Item.h"


void Chest::OpenChest(std::vector<Item>& someItems)
{
    std::cout << "You open the chest. It contained: \n\n";
    if (myItems.size() <= 0)
    {
        std::cout << "Nothing..\n";
    }
    else
    {
        for (int i = 0; i < myItems.size(); i++)
        {
            someItems.push_back(myItems[i]);
            myItems[i].ShowStats();
            std::cout << '\n';
        }
        std::cout << "[All items dropped on floor]\n";
    }
}

void Chest::RandomizeChestItems()
{
    int rndItem = (myRnd.GetRandomInt(0, 7));
    for (int i = 0; i < myItemAmount; i++)
    {
        SpawnChestItems(rndItem);
    }
}

void Chest::SpawnChestItems(int anItemIndex)
{
    Enum::Item item = static_cast<Enum::Item>(anItemIndex);

    switch (item)
    {
    case Enum::Item::MoonPendant:
    {
        Item pendant("Moon Pendant", Const::WEIGHT_MEDIUM, static_cast<int>(Enum::Stat::MaxHealth), 25);
        myItems.push_back(pendant);
        break;
    }
    case Enum::Item::RunningShoes:
    {
        Item shoes("Running Shoes", Const::WEIGHT_MEDIUM, static_cast<int>(Enum::Stat::Agility), 2);
        myItems.push_back(shoes);
        break;
    }
    case Enum::Item::SleepingMask:
    {
        Item mask("Sleeping Mask", Const::WEIGHT_LIGHT, static_cast<int>(Enum::Stat::Defense), 10);
        myItems.push_back(mask);
        break;
    }
    case Enum::Item::BrokenLever:
    {
        Item lever("Broken Lever", Const::WEIGHT_HEAVY, static_cast<int>(Enum::Stat::Strength), 3);
        myItems.push_back(lever);
        break;
    }
    case Enum::Item::MagnifyingGlass:
    {
        Item glass("Magnifying Glass", Const::WEIGHT_MEDIUM, static_cast<int>(Enum::Stat::Endurance), 1);
        myItems.push_back(glass);
        break;
    }
    case Enum::Item::LuckyRabbitsFoot:
    {
        Item foot("Lucky Rabbit's Foot", Const::WEIGHT_LIGHT, static_cast<int>(Enum::Stat::Strength), 1);
        myItems.push_back(foot);
        break;
    }
    case Enum::Item::CrownOfTheBlueprints:
    {
        Item crown("Crown of the Blueprints", Const::WEIGHT_VERY_HEAVY, static_cast<int>(Enum::Stat::Strength), 5);
        myItems.push_back(crown);
        break;
    }
    case Enum::Item::KnightsShield:
    {
        Item shield("Knight's Shield", Const::WEIGHT_VERY_HEAVY, static_cast<int>(Enum::Stat::Endurance), 5);
        myItems.push_back(shield);
        break;
    }
    default:
        break;
    }
}