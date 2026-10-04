#include "Chest.h"
#include "Random.h"
#include "Consts.h"
#include "Enum.h"
#include "Item.h"
#include "Boon.h"


void Chest::OpenChest(std::vector<Item>& someItems, std::vector<Boon>& someBoons)
{
    std::cout << "You open the chest. It contained: \n\n";
    if (myItems.size() <= 0 && myBoons.size() <= 0)
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

        for (int i = 0; i < myBoons.size(); i++)
        {
            someBoons.push_back(myBoons[i]);
            myBoons[i].ShowEffect();
            std::cout << '\n';
        }
        std::cout << "[All contents dropped on floor]\n";
    }
}

void Chest::RandomizeChestContent()
{
    for (int i = 0; i < myItemAmount; i++)
    {
        int rndItem = (myRnd.GetRandomInt(0, 7));
        SpawnChestItems(rndItem);
    }
    for (int i = 0; i < myBoonAmount; i++)
    {
        int rndBoon = (myRnd.GetRandomInt(0, 4));
        SpawnChestBoons(rndBoon);
    }
}

void Chest::SpawnChestBoons(int anItemIndex)
{
    Enum::Boon boon = static_cast<Enum::Boon>(anItemIndex);

    switch (boon)
    {
        case Enum::Boon::Apple:
        {
            Boon apple("Apple", 0, static_cast<int>(Enum::Boon::Apple));
            myBoons.push_back(apple);
            break;
        }
        case Enum::Boon::Banana:
        {
            Boon banana("Banana", 0, static_cast<int>(Enum::Boon::Banana));
            myBoons.push_back(banana);
            break;
        }
        case Enum::Boon::ClubSandwich:
        {
            Boon sandwich("Club Sandwich", 2, static_cast<int>(Enum::Boon::ClubSandwich));
            myBoons.push_back(sandwich);
            break;
        }
        case Enum::Boon::WoodFriedPizza:
        {
            Boon pizza("Wood Fried Pizza", 1, static_cast<int>(Enum::Boon::WoodFriedPizza));
            myBoons.push_back(pizza);
            break;
        }
        case Enum::Boon::LunchBox:
        {
            Boon lunchbox("Lunch Box", 2, static_cast<int>(Enum::Boon::LunchBox));
            myBoons.push_back(lunchbox);
            break;
        }
        default:
            break;
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