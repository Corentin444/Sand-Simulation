#include "../includes/Air.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

bool Air::can_move_to(int x, int y, int target_x, int target_y)
{
    return false;
}

int Air::get_id()
{
    return 0;
}

sf::Color Air::get_color()
{
    return sf::Color(210, 210, 210);
}