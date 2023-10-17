#ifndef FIRE_H
#define FIRE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../includes/Material.hpp"

using namespace std;

class Fire : public Material
{
public:
    int get_id() override;
    std::string get_name() override;
    void update(int x, int y) override;
};

#endif