#include "../includes/Simulation.hpp"
#include "../includes/Sand.hpp"
#include "../includes/Air.hpp"

std::vector<std::vector<Material*>>	Simulation::world;
int Simulation::width;
int Simulation::height;

void Simulation::init()
{
    Simulation::width = 500;
    Simulation::height = 500;

    Sand s1;
    Simulation::world[100][100] = &s1;

    for(int i = 0; i < Simulation::width; i++)
    {
        for(int j = 0; j < Simulation::height; j++)
        {
            Air a1;
            Simulation::world[i][j] = &a1;
        }
    }
}