#pragma once
class EnemyType
{

public:

	void SetHealth(const int someHealth) { myHealth = someHealth; } 
	void SetDamage(const int someDamage) { myDamage = someDamage; }

	int GetHealth() const { return myHealth; }
	int GetDamage() const { return myDamage; }

private:
	int myHealth;
	int myDamage;
};

