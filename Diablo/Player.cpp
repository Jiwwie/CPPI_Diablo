#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include "Item.h"

void Player::TakeDamage(int someDamage)
{
	int damageTaken = someDamage - (GetDefense() / 2);
	if (myUndead == true)
	{
		damageTaken = 0;
	}
	std::cout << "Enemy hits you. You lose " << damageTaken << " HP.\n";
	myCurrentHealth -= (damageTaken);
}

void Player::DoDamage(Enemy& anEnemy) const
{
	int damageDone = GetDamageValue();
	if (myGiantsStrength == true)
	{
		damageDone = 9999;
	}
	std::cout << "You slash the enemy with one blow. \n";
	std::cout << "You hit it for " << damageDone << " HP. \n";

	anEnemy.TakeDamage(damageDone);
}

void Player::AddItem(Item anItem)
{
	myItems.push_back(anItem);
}

int Player::GetItemWeight() const
{
	int weight = 0;
	for (int i = 0; i < myItems.size(); i++)
	{
		weight += myItems[i].GetWeight();
	}
	return weight;
}

void Player::ShowStats() const
{
	std::cout << "== STATS == ";
	std::cout << "\nHP: ";
	std::cout << GetCurrentHealth() << "/" << GetMaxHealth();
	std::cout << " || DMG: ";
	std::cout << GetDamageValue();
	std::cout << " || DEF: ";
	std::cout << GetDefense();
	std::cout << " || INV: ";
	std::cout << GetItemWeight() << "/" << GetInventoryCap();
	std::cout << "\n\n";
}

void Player::ShowInventory() const
{
	std::cout << "INVENTORY: ";

	if (myItems.size() <= 0)
	{
		std::cout << "\nEmpty.\n";
	}
	else
	{
		std::cout << "\n";
		for (int i = 0; i < myItems.size(); i++)
		{
			std::cout << "* ";
			myItems[i].ShowStats();
			std::cout << '\n';
		}
	}

}
