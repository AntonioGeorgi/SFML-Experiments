#include "Moving.h"

Moving::Moving(sf::Vector2i pos, sf::Color color)
    : position(pos)  // delegates to the main constructor
{
    float radius = TILE_SIZE / 2.0f;
    circle.setRadius(radius);
    circle.setOrigin({radius, radius});
    circle.setFillColor(color);
    setCirclePosition();
}

Moving::Moving(int x, int y, sf::Color color)
    : Moving(sf::Vector2i(x, y), color)
{
}

void Moving::move(int dx, int dy) 
// Speed in tiles per frame
{
    move({dx, dy});
}

void Moving::move(sf::Vector2i speed)
// Speed in tiles per frame
{
    position += checkBounds(speed);
    setCirclePosition();
}

void Moving::setColor(sf::Color color)
{
    circle.setFillColor(color);
}

sf::Vector2i Moving::checkBounds(sf::Vector2i speed)
{
    sf::Vector2i newPosition = position + speed;
    if (ENDLESS_MAP)
    {
        if (newPosition.x < 0)
            newPosition.x += MAP_WIDTH;
        else if (newPosition.x >= MAP_WIDTH)
            newPosition.x -= MAP_WIDTH;

        if (newPosition.y < 0)
            newPosition.y += MAP_HEIGHT;
        else if (newPosition.y >= MAP_HEIGHT)
            newPosition.y -= MAP_HEIGHT;
    } 
    else
    {
        if (newPosition.x < 0)
            newPosition.x = 0;
        else if (newPosition.x >= MAP_WIDTH)
            newPosition.x = MAP_WIDTH - 1;

        if (newPosition.y < 0)
            newPosition.y = 0;
        else if (newPosition.y >= MAP_HEIGHT)
            newPosition.y = MAP_HEIGHT - 1;
    }
    return newPosition - position;
}

void Moving::setCirclePosition()
{
    circle.setPosition({static_cast<float>((position.x + 0.5) * TILE_SIZE), static_cast<float>((position.y + 0.5) * TILE_SIZE)});
}

void Moving::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle, states);
}
