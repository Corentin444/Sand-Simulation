#include "../includes/Water.hpp"
#include "../includes/Simulation.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

bool Water::can_move_to(int x, int y, int target_x, int target_y)
{
    if (target_y < Simulation::height && target_y >= 0 && target_x < Simulation::width && target_x >= 0)
    {
        if (Simulation::world[target_x][target_y]->get_id() == -1)
        {
            return true;
        }
    }
    return false;
}

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
    if (Water::can_move_to(x, y, x, y + 1))
    {
        Water::move_to(x, y, x, y + 1);
    } else if (Water::can_move_to(x, y, x + 1, y + 1))
    {
        Water::move_to(x, y, x + 1, y + 1);
    } else if (Water::can_move_to(x, y, x - 1, y + 1))
    {
        Water::move_to(x, y, x - 1, y + 1);
    } else if (Water::can_move_to(x, y, x + 1, y))
    {
        Water::move_to(x, y, x + 1, y);
    } else if (Water::can_move_to(x, y, x - 1, y))
    {
        Water::move_to(x, y, x - 1, y);
    }
    
}