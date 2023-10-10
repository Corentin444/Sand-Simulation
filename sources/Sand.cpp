#include "../includes/Sand.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

bool Sand::can_move_to(int x, int y, int target_x, int target_y)
{
    return false;
}

int Sand::get_id()
{
    return 1;
}

sf::Color Sand::get_color()
{
    return sf::Color(100, 100, 100);
}