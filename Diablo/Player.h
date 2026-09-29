#pragma once
class Enemy;

class Player
{
public:
	void TakeDamage(int someDamage);
	void DoDamage(Enemy& anEnemy) const;

	void ShowStats() const;
	
	bool isAlive() const { return myCurrentHealth > 0; }

	int GetDamageValue() const { return myBaseDamage + myStrength / 2; }
	int GetMaxHealth() const { return myEndurance * 5 + myStrength * 6 + myAgility * 3; }
	int GetCurrentHealth() const { return myCurrentHealth; }
	int GetDefense() const { return myEndurance + myAgility; }
	int GetInventoryCap() const { return myStrength + myAgility / 3; }
	int GetAgility() const { return myAgility; }
	int GetStrength() const { return myStrength; }

	int GetCurrentRoom() const { return myCurrentRoom; }
	void SetCurrentRoom(int aRoom) { myCurrentRoom = aRoom; }

	void SetUndead() { myUndead = true; }
	void SetGiantsStrength() { myGiantsStrength = true; }

private:
	enum class myStats
	{
		FirstRoom = 0,
		Strength = 10,
		Agility = 6,
		Endurance = 3,
		BaseDamage = 10
	};

	int myStrength = static_cast<int>(myStats::Strength);
	int myAgility = static_cast<int>(myStats::Agility);
	int myEndurance = static_cast<int>(myStats::Endurance);

	int myBaseDamage = static_cast<int>(myStats::BaseDamage);

	int myCurrentHealth = GetMaxHealth();
	int myCurrentRoom = static_cast<int>(myStats::FirstRoom);

	bool myUndead = false;
	bool myGiantsStrength = false;

};
