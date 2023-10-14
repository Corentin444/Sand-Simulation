#include "../includes/Sand.hpp"
#include "../includes/Simulation.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

bool Sand::can_move_to(int x, int y, int target_x, int target_y)
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

int Sand::get_id()
{
    return 0;
}

std::string Sand::get_name()
{
    return "sand";
}

void Sand::update(int x, int y)
{
    if (Sand::can_move_to(x, y, x, y + 1))
    {
        Sand::move_to(x, y, x, y + 1);
    } else if (Sand::can_move_to(x, y, x + 1, y + 1))
    {
        Sand::move_to(x, y, x + 1, y + 1);
    } else if (Sand::can_move_to(x, y, x - 1, y + 1))
    {
        Sand::move_to(x, y, x - 1, y + 1);
    }
    
}