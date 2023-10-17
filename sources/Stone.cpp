#include "../includes/Stone.hpp"
#include "../includes/Simulation.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int Stone::get_id()
{
    return 2;
}

std::string Stone::get_name()
{
    return "stone";
}

void Stone::update(int x, int y)
{
    update_solid(x, y);
}