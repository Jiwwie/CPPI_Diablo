#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Room.h"
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
	std::cout << "Enemy: ";
	std::cout << "HP: ";
	std::cout << myHealth;
	std::cout << " | ATK: ";
	std::cout << myDamage;
	std::cout << "\n";
}