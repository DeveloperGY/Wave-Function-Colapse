#ifndef CELL_H
#define CELL_H

#include "tile.h"

#include <random>
#include <iostream>
#include <vector>

enum Tiles
{
    BLANK,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    HOR,
    VER,
    UR,
    RD,
    DL,
    LU,
    CROSS,
    NONE
};

enum Direction
{
    D_UP,
    D_DOWN,
    D_LEFT,
    D_RIGHT
};

class Cell
{
    private:
        std::vector<Tiles> possibilites;
        bool collapsed;
        Tiles value;

    public:
        Cell();
        
        void collapse();
        Tile get_tile();
        int get_entropy();
        void reset();
        bool is_collapsed();
        void update(Tiles tile, Direction direction);
        Tiles get_value();
};

#endif