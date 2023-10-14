#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Material
{
public:
    Material() = default;

    static void move_to(int x, int y, int target_x, int target_y);
    sf::Texture* get_texture();

    virtual void update(int x, int y) = 0;
    virtual bool can_move_to(int x, int y, int target_x, int target_y) = 0;
    virtual int get_id() = 0;
    virtual std::string get_name() = 0;
};

#endif