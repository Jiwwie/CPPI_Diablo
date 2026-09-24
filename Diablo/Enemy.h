#pragma once
class Player;

class Enemy
{
public:
	Enemy(int someHealth, int someDamage)
	{
		myHealth = someHealth;
		myDamage = someDamage;
	}

	bool isAlive() const { return myHealth > 0; }

	void TakeDamage(int someDamage);
	void DoDamage(Player& aPlayer);

private:
	int myHealth;
	int myDamage;

};
