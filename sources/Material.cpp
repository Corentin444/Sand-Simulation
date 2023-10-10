#include "../includes/Material.hpp"

using namespace std;

void Material::move_to(int x, int y, int target_x, int target_y)
{
    this->y += 1;
}

bool Material::can_move_to(int x, int y, int target_x, int target_y)
{
    return true;
}

int get_id() {
    return 0;
}

void update(int x, int y)
{
    if(Material::can_move_to(x, y, x, y + 1))
    
}
