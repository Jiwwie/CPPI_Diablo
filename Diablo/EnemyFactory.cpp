#include "EnemyFactory.h"

Enemy EnemyFactory::Create(const EnemyId anId) const
{
	return Enemy(myEnemyTypes[static_cast<int>(anId)]);
}

void EnemyFactory::Init()
{
	EnemyType& enemy = myEnemyTypes[static_cast<int>(EnemyId::Enemy)];
	enemy.SetHealth(25);
	enemy.SetDamage(10);
}