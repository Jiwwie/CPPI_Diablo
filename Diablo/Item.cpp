#include "Item.h"
#include "Player.h"

void Item::ApplyStat(Player* aPlayer) const
{
	aPlayer->UpdateStats(GetStatIndex(), GetStatBonus());
}

void Item::RemoveStat(Player* aPlayer) const
{
	aPlayer->UpdateStats(GetStatIndex(), -GetStatBonus());
}

void Item::ShowStats() const
{
	std::cout << GetName() << " || Bonus: " << GetStatBonus() << " " << GetStatStr() << " || Weight: " << GetWeight() << '\n';
}
