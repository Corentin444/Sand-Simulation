#include "blocks/Stone.hpp"

using namespace std;

int Stone::get_id()
{
    return 6;
}

std::string Stone::get_name()
{
    return "stone";
}

void Stone::update(int x, int y)
{
    update_solid(x, y);
}