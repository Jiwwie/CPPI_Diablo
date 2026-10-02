#pragma once
#include <iostream>
#include <random>

class Random
{
public:
    void InitRandomEngine();
    
    int GetRandomInt(int aMin, int aMax);

private:

    std::mt19937 mySeed = std::mt19937(std::random_device{}());
};

