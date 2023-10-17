#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;

class Material
{
public:
    Material();
    ~Material() = default;

    void move_to(int x, int y, int target_x, int target_y);
    bool can_move_to(int x, int y, int target_x, int target_y);

    sf::Texture* get_texture();
    sf::SoundBuffer* get_sound();

    virtual void update(int x, int y) = 0;
    virtual int get_id() = 0;
    virtual std::string get_name() = 0;

    void update_dust(int x, int y);
    void update_liquid(int x, int y);
    void update_solid(int x, int y);
    void update_gaz(int x, int y);

    int r;
    bool updated;
};

#endif