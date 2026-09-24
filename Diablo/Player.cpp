#include <iostream>
#include "Enemy.h"
#include "Player.h"


void Player::TakeDamage(int someDamage)
{
	myCurrentHealth -= someDamage;
}

void Player::DoDamage(Enemy& anEnemy) const
{
	std::cout << "Player does damage \n";
	anEnemy.TakeDamage(GetDamageValue());
}


void Player::ShowStats() const
{
	std::cout << "\n== STATS == ";
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