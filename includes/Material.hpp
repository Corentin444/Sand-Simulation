#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
using namespace std;

class Material
{
public:
    int x;
    int y;

    Material() = default;
    void update(int x, int y);
    void move_to(int x, int y, int target_x, int target_y);
    bool can_move_to(int x, int y, int target_x, int target_y);
    int get_id();
};

#endif