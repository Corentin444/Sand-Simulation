#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

#include "../includes/Simulation.hpp"

int main()
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile("../../resources/sounds/sand.ogg");
    sf::Sound sound;
    sound.setBuffer(buffer);
    Simulation simulation;
    simulation.init_textures();
    simulation.init_sounds();
    simulation.init_world();
    simulation.loop();
    return 0;
}