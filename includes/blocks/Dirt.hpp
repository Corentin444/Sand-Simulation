#pragma once

#include <iostream>
#include "Block.hpp"

using namespace std;

class Dirt : public Block
{
public:
    int get_id() override;
    std::string get_name() override;
    void update(int x, int y) override;
};