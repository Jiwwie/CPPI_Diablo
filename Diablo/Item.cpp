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



void Item::ShowStats() const
{
	std::cout << myItemName << " || Weight: " << myWeight << '\n';
}
