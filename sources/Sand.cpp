#include "../includes/Sand.hpp"
#include "../includes/Simulation.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

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
    update_dust(x, y);
}