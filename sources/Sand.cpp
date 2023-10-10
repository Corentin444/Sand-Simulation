#include "../includes/Sand.hpp"

using namespace std;

void Sand::move_to(int x, int y, int target_x, int target_y)
{
    this->y += 1;
}

bool Sand::can_move_to(int x, int y, int target_x, int target_y)
{
    return true;
}

int get_id()
{
    return 1;
}