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
    
    void init();
};

#endif
