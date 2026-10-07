#include "Consts.h"
#include "Enum.h"
#include "Item.h"
#include "ItemType.h"
#include "ItemFactory.h"

Item ItemFactory::Create(ItemId anId)
{ 
	return Item(myItemTypes[static_cast<int>(anId)]);
}


void ItemFactory::Init()
{
	ItemType& moonPendant = myItemTypes[static_cast<int>(ItemId::MoonPendant)];
	moonPendant.SetName("Moon Pendant");
	moonPendant.SetWeight(Const::WEIGHT_MEDIUM);
	moonPendant.SetStatIndex(static_cast<int>(Enum::Stat::MaxHealth));
	moonPendant.SetStatBonus(30);

	ItemType& runningShoes = myItemTypes[static_cast<int>(ItemId::RunningShoes)];
	runningShoes.SetName("Running Shoes");
	runningShoes.SetWeight(Const::WEIGHT_MEDIUM);
	runningShoes.SetStatIndex(static_cast<int>(Enum::Stat::Agility));
	runningShoes.SetStatBonus(2);

	ItemType& sleepingMask = myItemTypes[static_cast<int>(ItemId::SleepingMask)];
	sleepingMask.SetName("Sleeping Mask");
	sleepingMask.SetWeight(Const::WEIGHT_LIGHT);
	sleepingMask.SetStatIndex(static_cast<int>(Enum::Stat::Defense));
	sleepingMask.SetStatBonus(10);

	ItemType& brokenLever = myItemTypes[static_cast<int>(ItemId::BrokenLever)];
	brokenLever.SetName("Broken Lever");
	brokenLever.SetWeight(Const::WEIGHT_HEAVY);
	brokenLever.SetStatIndex(static_cast<int>(Enum::Stat::Strength));
	brokenLever.SetStatBonus(3);

	ItemType& magnifyingGlass = myItemTypes[static_cast<int>(ItemId::MagnifyingGlass)];
	magnifyingGlass.SetName("Magnifying Glass");
	magnifyingGlass.SetWeight(Const::WEIGHT_MEDIUM);
	magnifyingGlass.SetStatIndex(static_cast<int>(Enum::Stat::Endurance));
	magnifyingGlass.SetStatBonus(1);

	ItemType& luckyRabbitsFoot = myItemTypes[static_cast<int>(ItemId::LuckyRabbitsFoot)];
	luckyRabbitsFoot.SetName("Lucky Rabbit's Foot");
	luckyRabbitsFoot.SetWeight(Const::WEIGHT_LIGHT);
	luckyRabbitsFoot.SetStatIndex(static_cast<int>(Enum::Stat::Strength));
	luckyRabbitsFoot.SetStatBonus(1);

	ItemType& crownOfTheBlueprints = myItemTypes[static_cast<int>(ItemId::CrownOfTheBlueprints)];
	crownOfTheBlueprints.SetName("Crown of the Blueprints");
	crownOfTheBlueprints.SetWeight(Const::WEIGHT_VERY_HEAVY);
	crownOfTheBlueprints.SetStatIndex(static_cast<int>(Enum::Stat::Strength));
	crownOfTheBlueprints.SetStatBonus(5);

	ItemType& knightsShield = myItemTypes[static_cast<int>(ItemId::KnightsShield)];
	knightsShield.SetName("Knight's Shield");
	knightsShield.SetWeight(Const::WEIGHT_VERY_HEAVY);
	knightsShield.SetStatIndex(static_cast<int>(Enum::Stat::Endurance));
	knightsShield.SetStatBonus(5);


}