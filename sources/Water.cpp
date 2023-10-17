#include "../includes/Water.hpp"
#include "../includes/Simulation.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int Water::get_id()
{
    return 1;
}

std::string Water::get_name()
{
    return "water";
}

void Water::update(int x, int y)
{
    update_liquid(x, y);
}