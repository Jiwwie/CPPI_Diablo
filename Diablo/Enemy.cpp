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
    system("pause");
}