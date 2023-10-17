#include "../includes/Fire.hpp"
#include "../includes/Simulation.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int Fire::get_id()
{
    return 5;
}

std::string Fire::get_name()
{
    return "fire";
}

void Fire::update(int x, int y)
{
    update_solid(x, y);
}