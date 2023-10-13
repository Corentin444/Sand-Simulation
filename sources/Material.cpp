#include "../includes/Material.hpp"
#include "../includes/Simulation.hpp"

using namespace std;

void Material::move_to(int x, int y, int target_x, int target_y)
{
    Material* tmp = Simulation::world[target_x][target_y];
    Simulation::world[target_x][target_y] = Simulation::world[x][y];
    Simulation::world[x][y] = tmp;
}