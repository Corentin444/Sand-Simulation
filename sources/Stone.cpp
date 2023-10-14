#include "../includes/Stone.hpp"
#include "../includes/Simulation.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

bool Stone::can_move_to(int x, int y, int target_x, int target_y)
{
    return false;
}

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
    return;
}