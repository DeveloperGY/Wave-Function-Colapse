#include "tile.h"

Tile::Tile(std::array<bool, 9> arr):
    arr(arr)
{
    return;
}

void Tile::print(int x_off, int y_off) const
{
    for (int r=0; r<3; r++)
    {
        for (int c=0; c<3; c++)
        {
            td_drawPoint(x_off*3 + c, y_off*3 + r, ' ', TD_COLOR_BLACK, (this->arr[r*3 + c]) ? TD_COLOR_WHITE : TD_COLOR_BLACK);
        }
    }
}

const Tile Tile::BLANK({
    0, 0, 0,
    0, 0, 0,
    0, 0, 0
});

const Tile Tile::UP({
    0, 1, 0,
    1, 1, 1,
    0, 0, 0
});

const Tile Tile::DOWN({
    0, 0, 0,
    1, 1, 1,
    0, 1, 0
});

const Tile Tile::LEFT({
    0, 1, 0,
    1, 1, 0,
    0, 1, 0
});

const Tile Tile::RIGHT({
    0, 1, 0,
    0, 1, 1,
    0, 1, 0
});

const Tile Tile::HORIZONTAL({
    0, 0, 0,
    1, 1, 1,
    0, 0, 0
});

const Tile Tile::VERTICAL({
    0, 1, 0,
    0, 1, 0,
    0, 1, 0
});

const Tile Tile::UR({
    0, 1, 0,
    0, 1, 1,
    0, 0, 0
});

const Tile Tile::RD({
    0, 0, 0,
    0, 1, 1,
    0, 1, 0
});

const Tile Tile::DL({
    0, 0, 0,
    1, 1, 0,
    0, 1, 0
});

const Tile Tile::LU({
    0, 1, 0,
    1, 1, 0,
    0, 0, 0
});

const Tile Tile::CROSS({
    0, 1, 0,
    1, 1, 1,
    0, 1, 0
});