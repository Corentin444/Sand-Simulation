#include "blocks/Dirt.hpp"

using namespace std;

int Dirt::get_id()
{
    return 0;
}

std::string Dirt::get_name()
{
    return "dirt";
}

void Dirt::update(int x, int y)
{
    update_solid(x, y);
}