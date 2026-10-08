#pragma once
#include "EnemyType.h"
class Player;
class EnemyType;

class Enemy
{
public:
	Enemy(const EnemyType& anEnemyType) :
		myEnemyType(&anEnemyType)
	{
	};

	bool IsAlive() const { return myCurrentHealth > 0; }

	void TakeDamage(int someDamage);
	void DoDamage(Player& aPlayer) const;

	void ShowStats() const;

	int GetHealth() const { return myCurrentHealth; }
	int GetDamage() const { return myEnemyType->GetDamage(); }

private:
	const EnemyType* myEnemyType;
	int myCurrentHealth = myEnemyType->GetHealth();

};
