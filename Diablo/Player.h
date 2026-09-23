#pragma once
class Enemy;

class Player
{
public:
	void TakeDamage(int someDamage);
	void DoDamage(Enemy& anEnemy);

	void ShowStats() const;

	int GetDamageValue() const { return myStrength * myAgility; }
	int GetMaxHealth() const { return myArmor * 4 + myStrength * 6 + myAgility * 3; }
	int GetCurrentHealth() const { return myCurrentHealth; }
	int GetDefense() const { return myArmor + myAgility; }
	int GetInventoryCap() const { return myStrength + myAgility / 3; }

private:
	int myStrength = 10;
	int myAgility = 10;
	int myArmor = 10;

	int myCurrentHealth = GetMaxHealth();
	int myCurrentRoom = 0;
};
