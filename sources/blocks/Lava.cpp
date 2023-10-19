#include "blocks/Lava.hpp"

using namespace std;

int Lava::get_id()
{
    return 3;
}

std::string Lava::get_name()
{
    return "lava";
}

void Lava::update(int x, int y)
{
    update_liquid(x, y);
}