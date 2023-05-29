#include "grid.h"

#include <random>
#include <ctime>
#include <iostream>
#include <termDisplay.h>

const int GRID_WIDTH  = 45; // max 159 (balance 45)
const int GRID_HEIGHT = 27; // max 49 (balance 27)

const int TILE_WIDTH  = 3;
const int TILE_HEIGHT = 3;

int main(void)
{
    std::srand(std::time(nullptr));

    if (!td_initialize(GRID_WIDTH * TILE_WIDTH, GRID_HEIGHT * TILE_HEIGHT))
    {
        return -1;
    }



    Grid<GRID_WIDTH, GRID_HEIGHT> grid;

    while(!grid.is_solved())
    {
        grid.step();
        // grid.generate();

        grid.print();

        td_display();
    }

    getchar();

    td_terminate(1);

    return 0;
}