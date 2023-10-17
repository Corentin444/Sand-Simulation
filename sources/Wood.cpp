#include "../includes/Wood.hpp"
#include "../includes/Simulation.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int Wood::get_id()
{
    return 3;
}

std::string Wood::get_name()
{
    return "wood";
}

void Wood::update(int x, int y)
{
    update_solid(x, y);
}