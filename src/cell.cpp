#include "cell.h"

Cell::Cell()
{
    this->reset();

    return;
}

void Cell::collapse()
{
    if (this->possibilites.size() >= 1)
    {
        int index = std::rand() % this->possibilites.size();
        Tiles t = this->possibilites.at(index);
        this->possibilites.clear();
        this->possibilites.push_back(t);
    }
    else
    {
        this->possibilites.clear();
        this->possibilites.push_back(Tiles::BLANK);
    }

    this->value = this->possibilites.at(0);
    this->collapsed = true;

    return;
}

Tile Cell::get_tile()
{
    if (this->possibilites.size() > 1 || this->possibilites.size() == 0)
    {
        return Tile::BLANK;
    }

    Tile tile;

    switch(this->possibilites.at(0))
    {
        case Tiles::BLANK:
            tile = Tile::BLANK;
            break;
        
        case Tiles::UP:
            tile = Tile::UP;
            break;
        
        case Tiles::DOWN:
            tile = Tile::DOWN;
            break;
        
        case Tiles::LEFT:
            tile = Tile::LEFT;
            break;
        
        case Tiles::RIGHT:
            tile = Tile::RIGHT;
            break;
        
        case Tiles::HOR:
            tile = Tile::HORIZONTAL;
            break;

        case Tiles::VER:
            tile = Tile::VERTICAL;
            break;
        
        case Tiles::UR:
            tile = Tile::UR;
            break;
        
        case Tiles::RD:
            tile = Tile::RD;
            break;

        case Tiles::DL:
            tile = Tile::DL;
            break;
        
        case Tiles::LU:
            tile = Tile::LU;
            break;
    }

    return tile;
}

int Cell::get_entropy()
{
    return this->possibilites.size();
}

void Cell::reset()
{
    this->possibilites.clear();

    this->possibilites.push_back(Tiles::BLANK);
    this->possibilites.push_back(Tiles::UP);
    this->possibilites.push_back(Tiles::DOWN);
    this->possibilites.push_back(Tiles::LEFT);
    this->possibilites.push_back(Tiles::RIGHT);
    this->possibilites.push_back(Tiles::HOR);
    this->possibilites.push_back(Tiles::VER);
    this->possibilites.push_back(Tiles::UR);
    this->possibilites.push_back(Tiles::RD);
    this->possibilites.push_back(Tiles::DL);
    this->possibilites.push_back(Tiles::LU);

    this->collapsed = false;

    this->value = NONE;

    return;
}

bool Cell::is_collapsed()
{
    return this->collapsed;
}

void Cell::update(Tiles tile, Direction direction)
{
    if (this->is_collapsed())
    {
        return;
    }

    std::vector<Tiles> new_possibilities;
    std::vector<Tiles> true_possibilities;

    if (direction == Direction::D_UP)
    {
        if (tile == Tiles::BLANK || tile == Tiles::UP || tile == Tiles::HOR || tile == Tiles::UR || tile == Tiles::LU)
        {
            new_possibilities.push_back(Tiles::BLANK);
            new_possibilities.push_back(Tiles::DOWN);
            new_possibilities.push_back(Tiles::HOR);
            new_possibilities.push_back(Tiles::RD);
            new_possibilities.push_back(Tiles::DL);
        }
        else
        {
            new_possibilities.push_back(Tiles::UP);
            new_possibilities.push_back(Tiles::LEFT);
            new_possibilities.push_back(Tiles::RIGHT);
            new_possibilities.push_back(Tiles::VER);
            new_possibilities.push_back(Tiles::UR);
            new_possibilities.push_back(Tiles::LU);
        }
    }
    else if (direction == Direction::D_DOWN)
    {
        if (tile == Tiles::BLANK || tile == Tiles::DOWN || tile == Tiles::HOR || tile == Tiles::RD || tile == Tiles::DL)
        {
            new_possibilities.push_back(Tiles::BLANK);
            new_possibilities.push_back(Tiles::UP);
            new_possibilities.push_back(Tiles::HOR);
            new_possibilities.push_back(Tiles::UR);
            new_possibilities.push_back(Tiles::LU);
        }
        else
        {
            new_possibilities.push_back(Tiles::DOWN);
            new_possibilities.push_back(Tiles::LEFT);
            new_possibilities.push_back(Tiles::RIGHT);
            new_possibilities.push_back(Tiles::VER);
            new_possibilities.push_back(Tiles::RD);
            new_possibilities.push_back(Tiles::DL);
        }
    }
    else if (direction == Direction::D_LEFT)
    {
        if (tile == Tiles::BLANK || tile == Tiles::LEFT || tile == Tiles::VER || tile == Tiles::DL || tile == Tiles::LU)
        {
            new_possibilities.push_back(Tiles::BLANK);
            new_possibilities.push_back(Tiles::RIGHT);
            new_possibilities.push_back(Tiles::VER);
            new_possibilities.push_back(Tiles::UR);
            new_possibilities.push_back(Tiles::RD);
        }
        else
        {
            new_possibilities.push_back(Tiles::UP);
            new_possibilities.push_back(Tiles::DOWN);
            new_possibilities.push_back(Tiles::LEFT);
            new_possibilities.push_back(Tiles::HOR);
            new_possibilities.push_back(Tiles::DL);
            new_possibilities.push_back(Tiles::LU);
        }
    }
    else
    {
        if (tile == Tiles::BLANK || tile == Tiles::RIGHT || tile == Tiles::VER || tile == Tiles::UR || tile == Tiles::RD)
        {
            new_possibilities.push_back(Tiles::BLANK);
            new_possibilities.push_back(Tiles::LEFT);
            new_possibilities.push_back(Tiles::VER);
            new_possibilities.push_back(Tiles::DL);
            new_possibilities.push_back(Tiles::LU);
        }
        else
        {
            new_possibilities.push_back(Tiles::UP);
            new_possibilities.push_back(Tiles::DOWN);
            new_possibilities.push_back(Tiles::RIGHT);
            new_possibilities.push_back(Tiles::HOR);
            new_possibilities.push_back(Tiles::UR);
            new_possibilities.push_back(Tiles::RD);
        }
    }

    for (Tiles &t: this->possibilites)
    {
        for (Tiles &_t: new_possibilities)
        {
            if (t == _t)
            {
                true_possibilities.push_back(t);
                break;
            }
        }
    }

    this->possibilites = true_possibilities;

    return;
}

Tiles Cell::get_value()
{
    return this->value;
}