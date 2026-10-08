#include "Chest.h"
#include "Random.h"
#include "Consts.h"
#include "Enum.h"
#include "Item.h"
#include "Boon.h"
#include "ItemFactory.h"

Chest::Chest(int anItemAmount, int aBoonAmount, ItemFactory& anItemFactory) :
    myItemAmount(anItemAmount),
    myBoonAmount(aBoonAmount)
{
    RandomizeChestContent(anItemFactory);
};

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

void Chest::RandomizeChestContent(ItemFactory& anItemFactory)
{
    for (int i = 0; i < myItemAmount; i++)
    {
        int rndItem = (myRnd.GetRandomInt(0, static_cast<int>(ItemId::Count)-1));
        SpawnChestItems(rndItem, anItemFactory);
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

void Chest::SpawnChestItems(int anItemIndex, ItemFactory& anItemFactory)
{
    Item item = anItemFactory.Create(static_cast<ItemId>(anItemIndex));
    myItems.push_back(item);
}