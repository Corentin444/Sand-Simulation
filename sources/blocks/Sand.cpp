#include "blocks/Sand.hpp"

using namespace std;

int Sand::get_id()
{
    return 5;
}

std::string Sand::get_name()
{
    return "sand";
}

void Sand::update(int x, int y)
{
    update_dust(x, y);
}