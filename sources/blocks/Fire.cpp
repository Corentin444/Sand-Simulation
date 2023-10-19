#include "blocks/Fire.hpp"

using namespace std;

int Fire::get_id()
{
    return 1;
}

std::string Fire::get_name()
{
    return "fire";
}

void Fire::update(int x, int y)
{
    update_solid(x, y);
}