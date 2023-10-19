#include "blocks/Water.hpp"

using namespace std;

int Water::get_id()
{
    return 7;
}

std::string Water::get_name()
{
    return "water";
}

void Water::update(int x, int y)
{
    update_liquid(x, y);
}