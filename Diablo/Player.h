#pragma once
#include <vector>
class Item;
class Boon;
class Enemy;

class Player
{
public:
	std::vector<Item> myItems;
	std::vector<Boon> myBoons;

	void TakeDamage(int someDamage);
	void DoDamage(Enemy& anEnemy) const;

	void AddItem(int anIndex, Item& anItem, std::vector<Item>& someItems);
	void AddBoon(int anIndex, Boon& anItem, std::vector<Boon>& someBoons);
	void PromptDrop(std::vector<Item>& someItems);
	void DropItem(int anItemIndex, std::vector<Item>& someItems);
	void UpdateStats(int aStat, int aStatBonus);

	void ShowStats() const;
	void ShowInventory(std::vector<Item>& someItems);
	
	bool isAlive() const { return myCurrentHealth > 0; }

	void HealPlayer(int someHealth) { myCurrentHealth = myCurrentHealth + someHealth; }

	int GetDamageValue() const { return myBaseDamage + myStrength / 2; }
	int GetMaxHealth() const { return (myEndurance * 4 + myStrength * 3 + myAgility * 3) + myHealthBonus; }
	int GetCurrentHealth() const { return myCurrentHealth; }
	int GetDefense() const { return (myEndurance + myAgility) + myDefenseBonus; }
	int GetInventoryCap() const { return (myStrength + myAgility / 3) + myInventoryBonus; }
	int GetItemWeight() const;
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

	int myHealthBonus = 0;
	int myDefenseBonus = 0;
	int myInventoryBonus = 0;

	int myBaseDamage = static_cast<int>(myStats::BaseDamage);

	int myCurrentHealth = GetMaxHealth();
	int myCurrentRoom = static_cast<int>(myStats::FirstRoom);

	bool myUndead = false;
	bool myGiantsStrength = false;

};
