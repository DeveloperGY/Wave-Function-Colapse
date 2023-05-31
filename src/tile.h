#ifndef TILE_H
#define TILE_H

#include <array>

#include <termDisplay.h>

class Tile
{
    private:
        std::array<bool, 9> arr;

    public:
        Tile(std::array<bool, 9> arr);
        Tile() = default;

        void print(int x_off, int y_off) const;

        static const Tile BLANK;
        static const Tile UP;
        static const Tile DOWN;
        static const Tile LEFT;
        static const Tile RIGHT;
        static const Tile HORIZONTAL;
        static const Tile VERTICAL;
        static const Tile UR;
        static const Tile RD;
        static const Tile DL;
        static const Tile LU;
        static const Tile CROSS;
};

#endif