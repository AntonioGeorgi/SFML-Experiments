#pragma once
#include <SFML/Graphics.hpp>
#include <Constants.h>

class Entity : public sf::Drawable
{
public:
    Entity(sf::Vector2i position_in_grid, sf::Color color);
    Entity(int x, int y , sf::Color color);

    void move(sf::Vector2i speed);
    void move(int dx, int dy);
    void setColor(sf::Color color);

    sf::Vector2i getPosition() const { return position; }
    sf::Color getColor() const { return circle.getFillColor(); }

private:
    sf::Vector2i position;
    sf::CircleShape circle;

    void setCirclePosition();
    void checkBounds();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
