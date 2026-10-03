#include <iostream>
#include "Enemy.h"
#include "Enum.h"
#include "Player.h"
#include "Item.h"
#include "GameFunction.h"

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

void Player::AddItem(Item& anItem)
{
	if (GetItemWeight() + anItem.GetWeight() >= GetInventoryCap())
	{
		std::cout << "You can't carry this.\n";
		system("pause");
	}
	else
	{
		std::cout << anItem.GetName() << " added to inventory.\n";
		myItems.push_back(anItem);
		anItem.ApplyStat(this);
		system("pause");
	}
}

void Player::PromptDrop()
{
	int itemIndex;
	std::cout << "Which item do you want to drop?\n";
	for (int i = 0; i < myItems.size() ; i++)
	{
		std::cout << "[" << i + 1 << "] " << myItems[i].GetName() << "\n";
	}
	std::cin >> itemIndex;
	while (itemIndex <= 0 || itemIndex > myItems.size() || std::cin.fail())
	{
		GameFunction::ClearInputBuffer();
		std::cout << "You can't drop that: ";
		std::cin >> itemIndex;
	}
	GameFunction::ClearInputBuffer();
	DropItem(itemIndex-1);
}

void Player::DropItem(int anItemIndex)
{
	std::cout << "You drop " << myItems[anItemIndex].GetName() << ".\n";
	myItems[anItemIndex].RemoveStat(this);
	myItems.erase(myItems.begin() + anItemIndex);
}

void Player::UpdateStats(int aStat, int aStatBonus)
{
	Enum::Stat stat = static_cast<Enum::Stat>(aStat);
	switch (stat)
	{
		case Enum::Stat::Strength:
		{
			myStrength += aStatBonus;
			break;
		}
		case Enum::Stat::Agility:
		{
			myAgility += aStatBonus;
			break;
		}
		case Enum::Stat::Endurance:
		{
			myEndurance += aStatBonus;
			break;
		}
		case Enum::Stat::MaxHealth:
		{
			myHealthBonus += aStatBonus;
			if (aStatBonus > 0)
			{
				myCurrentHealth += aStatBonus;
			}
			break;
		}
		case Enum::Stat::Defense:
		{
			myDefenseBonus += aStatBonus;
			break;
		}
		case Enum::Stat::InventoryCap:
		{
			myInventoryBonus += aStatBonus;
			break;
		}
		default:
			break;
	}
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

void Player::ShowInventory()
{
	int input = 0;
	std::cout << "[1] Show inventory\n";
	std::cout << "[2] Continue\n";
	std::cin >> input;
	while (input <= 0 || input > 2 || std::cin.fail())
	{
		GameFunction::ClearInputBuffer();
		std::cout << "Invalid input, try again : ";
		std::cin >> input;
	}
	GameFunction::ClearInputBuffer();

	switch (input)
	{
		case 1:
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
				while (input != 3)
				{

					std::cout << "[1] Drop something\n";
					std::cout << "[2] Use item\n";
					std::cout << "[3] Continue\n";
					std::cin >> input;
					while (input <= 0 || input > 3 || std::cin.fail())
					{
						GameFunction::ClearInputBuffer();
						std::cout << "Invalid input, try again : ";
						std::cin >> input;
					}
					GameFunction::ClearInputBuffer();

					switch (input)
					{
						case 1:
						{
							system("cls");
							PromptDrop();
							break;
						}
						case 2:
						{
							break;
						}
						case 3:
						{
							break;
						}
						default:
							break;
					}
				}
			}

			break;
		}
		case 2:
		{
			break;
		}
		default:
			break;
	}
	

}
