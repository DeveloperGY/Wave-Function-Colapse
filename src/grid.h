#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include <vector>
#include <iostream>

template<int WIDTH, int HEIGHT>
class Grid
{
    private:
        Cell arr[WIDTH * HEIGHT];

    public:
        Grid();

        void print();
        void step();
        void generate();
        bool is_solved();
};



template<int WIDTH, int HEIGHT>
Grid<WIDTH, HEIGHT>::Grid()
{
    for (int i=0; i<WIDTH*HEIGHT; i++)
    {
        this->arr[i] = Cell();
    }
    return;
}

template<int WIDTH, int HEIGHT>
void Grid<WIDTH,HEIGHT>::print()
{
    for (int r=0; r<HEIGHT; r++)
    {
        for(int c=0; c<WIDTH; c++)
        {
            this->arr[r*WIDTH + c].get_tile().print(c, r);
        }
    }
}

template<int WIDTH, int HEIGHT>
void Grid<WIDTH,HEIGHT>::step()
{
    std::vector<int> lowest_entropy;

    int current_lowest = INT32_MAX;

    for (int i=0; i<WIDTH*HEIGHT; i++)
    {
        int cell_entropy = this->arr[i].get_entropy();
        
        if (this->arr[i].is_collapsed())
        {
            continue;
        }
        else if (cell_entropy == current_lowest)
        {
            lowest_entropy.push_back(i);
        }
        else if(cell_entropy < current_lowest)
        {
            lowest_entropy.clear();
            lowest_entropy.push_back(i);
            current_lowest = cell_entropy;
        }
    }

    if(lowest_entropy.size() > 0)
    {
        int index = std::rand() % lowest_entropy.size();

        Cell &c = this->arr[lowest_entropy.at(index)];

        c.collapse();

        Tiles tile = this->arr[lowest_entropy.at(index)].get_value();

        // update the adjacent cells

        // top
        if (lowest_entropy.at(index) - WIDTH >= 0)
        {
            this->arr[lowest_entropy.at(index) - WIDTH].update(tile, Direction::D_DOWN);
        }

        // bottom
        if (lowest_entropy.at(index) + WIDTH < WIDTH*HEIGHT)
        {
            this->arr[lowest_entropy.at(index) + WIDTH].update(tile, Direction::D_UP);
        }

        // left
        if (lowest_entropy.at(index) - 1 >= 0)
        {
            this->arr[lowest_entropy.at(index) - 1].update(tile, Direction::D_RIGHT);
        }

        // right
        if (lowest_entropy.at(index) + 1 < WIDTH*HEIGHT)
        {
            this->arr[lowest_entropy.at(index) + 1].update(tile, Direction::D_LEFT);
        }
    }
}

template<int WIDTH, int HEIGHT>
bool Grid<WIDTH,HEIGHT>::is_solved()
{
    bool solved = true;
    
    for(int i=0; i<WIDTH*HEIGHT; i++)
    {
        if (!this->arr[i].is_collapsed())
        {
            solved = false;
            break;
        }
    }

    return solved;
}

template<int WIDTH, int HEIGHT>
void Grid<WIDTH,HEIGHT>::generate()
{
    while(!this->is_solved())
    {
        this->step();
        int collapsed_count = 0;

        for (Cell &c: this->arr)
        {
            if (c.is_collapsed())
            {
                collapsed_count++;
            }
        }

    }

    return;
}

#endif