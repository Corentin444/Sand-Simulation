#ifndef AIR_H
#define AIR_H

#include <iostream>
#include "../includes/Material.hpp"

using namespace std;

class Air : public Material
{
public:
    void move_to(int x, int y, int target_x, int target_y);
    bool can_move_to(int x, int y, int target_x, int target_y);
    int get_id();
};

#endif