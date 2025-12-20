#include "Wall.h"

Wall::Wall(sf::Vector2i pos, sf::Color color)
    : Immovable(pos, color)
{
}

Wall::Wall(int x, int y, sf::Color color)
    : Wall(sf::Vector2i(x, y), color)
{
}
