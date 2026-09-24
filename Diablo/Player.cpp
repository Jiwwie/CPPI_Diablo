#include <iostream>
#include "Enemy.h"
#include "Player.h"


void Player::TakeDamage(int someDamage)
{
	myCurrentHealth -= someDamage;
}

void Player::DoDamage(Enemy& anEnemy)
{
	std::cout << "Player does damage \n";
	anEnemy.TakeDamage(GetDamageValue());
	system("pause");
}


void Player::ShowStats() const
{
	std::cout << "Strength: ";
	std::cout << myStrength;
	std::cout << "\nAgility: ";
	std::cout << myAgility;
	std::cout << "\nArmor: ";
	std::cout << myEndurance;

	std::cout << "\n\nHP: ";
	std::cout << GetCurrentHealth() << "/" << GetMaxHealth();
	std::cout << " || DMG: ";
	std::cout << GetDamageValue();
	std::cout << " || DEF: ";
	std::cout << GetDefense();
	std::cout << "\n\n";
	system("pause");
}