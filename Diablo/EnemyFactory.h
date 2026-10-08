#pragma once
#include "Enemy.h"
#include "EnemyType.h"
#include <array>

enum class EnemyId
{
	Enemy,

	Count
};

class EnemyFactory
{
public:

	void Init();
	Enemy Create(const EnemyId anEnemyId) const;

private:
	std::array<EnemyType, static_cast<int>(EnemyId::Count)> myEnemyTypes;

};

