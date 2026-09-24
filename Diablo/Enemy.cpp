#include <iostream>
#include "Enemy.h"
#include "Player.h"

void Enemy::TakeDamage(int someDamage)
{
    myHealth -= someDamage;
}

void Enemy::DoDamage(Player& aPlayer)
{
    std::cout << "Enemy does damage \n";
    aPlayer.TakeDamage(myDamage);
}

void Enemy::ShowStats() const
{
	std::cout << "\n";
	std::cout << "--Enemy stats--\n";
	std::cout << "HP: ";
	std::cout << myHealth;
	std::cout << "\nATK: ";
	std::cout << myDamage;
	std::cout << "\n";
}