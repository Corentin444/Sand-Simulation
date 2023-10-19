#include "Block.hpp"
#include "Simulation.hpp"

using namespace std;

Block::Block()
{
    this->r = (rand() % 2) * 2 - 1;
    this->updated = false;
}

void Block::move_to(int x, int y, int target_x, int target_y)
{
    Block *tmp = Simulation::world[target_x][target_y];
    Simulation::world[target_x][target_y] = Simulation::world[x][y];
    Simulation::world[x][y] = tmp;
}

bool Block::can_move_to(int x, int y, int target_x, int target_y)
{
    if (target_x < 0 || target_x >= Simulation::width || target_y < 0 || target_y >= Simulation::height)
        return false;
    if (Simulation::world[target_x][target_y]->get_id() == -1)
        return true;
    if (Simulation::world[target_x][target_y]->get_id() == 0 && Simulation::world[x][y]->get_id() == 1)
        return true;
    return false;
}

sf::Texture *Block::get_texture()
{
    return &Simulation::textures[this->get_id()];
}

sf::SoundBuffer *Block::get_sound()
{
    return &Simulation::sounds[this->get_id()];
}

void Block::update_dust(int x, int y)
{
    std::vector<std::pair<int, int>> directions = {{0, 1}, {r, 1}, {-r, 1}};
    for (auto direction : directions)
    {
        if (Block::can_move_to(x, y, x + direction.first, y + direction.second))
        {
            this->move_to(x, y, x + direction.first, y + direction.second);
            break;
        }
    }
}

void Block::update_liquid(int x, int y)
{
    std::vector<std::pair<int, int>> directions = {{0, 1}, {r, 1}, {-r, 1}, {r, 0}, {-r, 0}};
    for (auto direction : directions)
    {
        if (Block::can_move_to(x, y, x + direction.first, y + direction.second))
        {
            this->move_to(x, y, x + direction.first, y + direction.second);
            break;
        }
    }
}

void Block::update_solid(int x, int y)
{
    return;
}

void Block::update_gaz(int x, int y)
{
    std::vector<std::pair<int, int>> directions = {{0, -1}, {r, -1}, {-r, -1}};
    for (auto direction : directions)
    {
        if (Block::can_move_to(x, y, x + direction.first, y + direction.second))
        {
            this->move_to(x, y, x + direction.first, y + direction.second);
            break;
        }
    }
}
