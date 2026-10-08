#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Room.h"
#include "Player.h"

void Enemy::TakeDamage(int someDamage)
{
    myCurrentHealth -= someDamage;
}

void Enemy::DoDamage(Player& aPlayer) const
{
    aPlayer.TakeDamage(GetDamage());
}

void Enemy::ShowStats() const
{
	std::cout << "Enemy: ";
	std::cout << "HP: ";
	std::cout << myCurrentHealth;
	std::cout << " | ATK: ";
	std::cout << GetDamage();
	std::cout << "\n";
}