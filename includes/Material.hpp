#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Material
{
public:
    Material() = default;

    static void update(int x, int y);
    static void move_to(int x, int y, int target_x, int target_y);
    static bool can_move_to(int x, int y, int target_x, int target_y);
    
    virtual int get_id() = 0;
    virtual sf::Color get_color() = 0;
};

#endif