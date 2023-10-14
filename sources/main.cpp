#include <SFML/Graphics.hpp>
#include <vector>

#include "../includes/Simulation.hpp"

int main()
{
    Simulation simulation;
    simulation.init_textures();
    simulation.init_world();
    simulation.loop();
    return 0;
}