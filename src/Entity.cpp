#include "Entity.h"

Entity::Entity(sf::Vector2i pos, sf::Color color)
    : position(pos)  // delegates to the main constructor
{
    float radius = TILE_SIZE / 2.0f;
    float doubleRadius = radius + radius;
    circle.setRadius(radius);
    circle.setOrigin({radius, radius});
    circle.setFillColor(color);
    setCirclePosition();
}

Entity::Entity(int x, int y, sf::Color color)
    : Entity(sf::Vector2i(x, y), color)
{
}

void Entity::move(int dx, int dy) 
// Speed in tiles per frame
{
    move({dx, dy});
}

void Entity::move(sf::Vector2i speed)
// Speed in tiles per frame
{
    position += speed;
    checkBounds();    
    setCirclePosition();
}

void Entity::setColor(sf::Color color)
{
    circle.setFillColor(color);
}

void Entity::checkBounds()
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

void Entity::setCirclePosition()
{
    circle.setPosition({static_cast<float>((position.x + 0.5) * TILE_SIZE), static_cast<float>((position.y + 0.5) * TILE_SIZE)});
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle, states);
}


