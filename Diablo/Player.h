#pragma once
class Enemy;

class Player
{
public:
	void TakeDamage(int someDamage);
	void DoDamage(Enemy& anEnemy) const;

	void ShowStats() const;
	
	bool isAlive() const { return myCurrentHealth > 0; }

	int GetDamageValue() const { return BaseValue_Damage + myStrength / 2; }
	int GetMaxHealth() const { return myEndurance * 5 + myStrength * 6 + myAgility * 3; }
	int GetCurrentHealth() const { return myCurrentHealth; }
	int GetDefense() const { return myEndurance + myAgility; }
	int GetInventoryCap() const { return myStrength + myAgility / 3; }

	int GetCurrentRoom() const { return myCurrentRoom; }
	void SetCurrentRoom(int aRoom) { myCurrentRoom = aRoom; }

private:
	int myStrength = BaseValue_Strength;
	int myAgility = BaseValue_Agility;
	int myEndurance = BaseValue_Endurance;

	int myCurrentHealth = GetMaxHealth();
	int myCurrentRoom = BaseValue_FirstRoom;

	enum BaseValue
	{
		BaseValue_FirstRoom = 0,
		BaseValue_Strength = 10,
		BaseValue_Agility = 5,
		BaseValue_Endurance = 5,
		
		BaseValue_Damage = 10
	};
};
