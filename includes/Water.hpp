#ifndef WATER_H
#define WATER_H

#include <iostream>
#include "../includes/Material.hpp"

using namespace std;

class Water : public Material
{
public:
    int get_id() override;
    std::string get_name() override;
    void update(int x, int y) override;
};

#endif