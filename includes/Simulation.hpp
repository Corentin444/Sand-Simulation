#pragma once

#include <vector>
#include <SFML/Audio.hpp>
#include "Block.hpp"

class Simulation
{
public:
    static unsigned int width;
    static unsigned int height;
    static std::vector<std::vector<Block*>> world;
    static std::vector<sf::Texture> textures;
    static std::vector<sf::SoundBuffer> sounds;
    static int brush;
    
    void loop();
    void init_textures();
    void init_sounds();
    void init_world();
};
