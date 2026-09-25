#include <iostream>
#include "Enemy.h"
#include "Player.h"


void Player::TakeDamage(int someDamage)
{
	myCurrentHealth -= someDamage;
}

void Player::DoDamage(Enemy& anEnemy) const
{
	std::cout << "You slash the enemy with one blow. \n";
	std::cout << "You hit it for " << GetDamageValue() << " HP. \n";
	anEnemy.TakeDamage(GetDamageValue());
}


void Player::ShowStats() const
{
	system("cls");
	std::cout << "== STATS == ";
	std::cout << "\nHP: ";
	std::cout << GetCurrentHealth() << "/" << GetMaxHealth();
	std::cout << " || DMG: ";
	std::cout << GetDamageValue();
	std::cout << " || DEF: ";
	std::cout << GetDefense();
	//std::cout << " || INV CAP: ";
	//std::cout << GetInventoryCap();
	std::cout << "\n\n";
}