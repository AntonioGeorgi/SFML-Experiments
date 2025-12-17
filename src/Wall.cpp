#include "Wall.h"

Wall::Wall(sf::Vector2i pos, sf::Color color)
    : position(pos)
{
    // Replace circle with square for walls
    float size = static_cast<float>(TILE_SIZE);
    square.setSize({size, size});
    square.setFillColor(color);
    setSquarePosition();
}

void Wall::setColor(sf::Color color)
{
    square.setFillColor(color);
}

void Wall::setSquarePosition()
{
    square.setPosition({static_cast<float>(position.x * TILE_SIZE), static_cast<float>(position.y * TILE_SIZE)});
}

void Wall::checkBounds()
{
    if (ENDLESS_MAP)
    {
        if (position.x < 0)
            position.x += MAP_WIDTH;
        else if (position.x >= MAP_WIDTH)
            position.x -= MAP_WIDTH;

        if (position.y < 0)
            position.y += MAP_HEIGHT;
        else if (position.y >= MAP_HEIGHT)
            position.y -= MAP_HEIGHT;
    } else
    {
        if (position.x < 0)
            position.x = 0;
        else if (position.x >= MAP_WIDTH)
            position.x = MAP_WIDTH - 1;

        if (position.y < 0)
            position.y = 0;
        else if (position.y >= MAP_HEIGHT)
            position.y = MAP_HEIGHT - 1;
    }
}

void Wall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(square, states);
}
