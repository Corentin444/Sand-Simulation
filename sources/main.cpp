#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Simulation.hpp"

int main()
{
    Simulation simulation;
    simulation.init_textures();
    simulation.init_sounds();
    simulation.init_world();
    simulation.loop();
    return 0;
}