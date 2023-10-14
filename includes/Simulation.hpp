#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "../includes/Material.hpp"

class Simulation
{
public:
    static unsigned int width;
    static unsigned int height;
    static std::vector<std::vector<Material*>> world;
    static std::vector<sf::Texture> textures;
    static int brush;
    
    void loop();
    void init_textures();
    void init_world();
};

#endif
