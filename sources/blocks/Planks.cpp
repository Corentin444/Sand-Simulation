#include "blocks/Planks.hpp"

using namespace std;

int Planks::get_id()
{
    return 4;
}

std::string Planks::get_name()
{
    return "planks";
}

void Planks::update(int x, int y)
{
    update_solid(x, y);
}