#include "Random.h"

int Random::GetRandomInt(int aMin, int aMax)
{
    std::uniform_int_distribution<int> rndDist(aMin, aMax);
    return rndDist(mySeed);
}

void Random::InitRandomEngine()
{
    std::random_device randomDevice;
    mySeed = std::mt19937(randomDevice());
}
