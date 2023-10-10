#ifndef AIR_H
#define AIR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../includes/Material.hpp"

using namespace std;

class Air : public Material
{
public:
    bool can_move_to(int x, int y, int target_x, int target_y);
    int get_id() override;
    sf::Color get_color() override;
};

#endif