#include "blocks/Grass.hpp"
#include "Block.hpp"

using namespace std;

int Grass::get_id()
{
    return 2;
}

std::string Grass::get_name()
{
    return "grass";
}

void Grass::update(int x, int y)
{
    update_solid(x, y);
}