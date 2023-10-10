#include "../includes/Material.hpp"
#include "../includes/Simulation.hpp"

using namespace std;

void Material::move_to(int x, int y, int target_x, int target_y)
{
    Material* tmp = Simulation::world[target_x][target_y];
    Simulation::world[target_x][target_y] = Simulation::world[x][y];
    Simulation::world[x][y] = tmp;
}

bool Material::can_move_to(int x, int y, int target_x, int target_y)
{
    return true;
}

void Material::update(int x, int y)
{
    if(Material::can_move_to(x, y, x, y + 1)) {
        Material::move_to(x, y, x, y + 1);
    }
    
}
