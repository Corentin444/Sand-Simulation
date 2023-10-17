#include "../includes/Smoke.hpp"
#include "../includes/Simulation.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int Smoke::get_id()
{
    return 5;
}

std::string Smoke::get_name()
{
    return "smoke";
}

void Smoke::update(int x, int y)
{
    update_gaz(x, y);
}