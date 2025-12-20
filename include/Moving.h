#pragma once
#include <SFML/Graphics.hpp>
#include <Constants.h>

class Moving : public sf::Drawable
{
public:
    Moving(sf::Vector2i position_in_grid, sf::Color color = sf::Color::Blue);
    Moving(int x, int y, sf::Color color = sf::Color::Blue);

    void move(sf::Vector2i speed);
    void move(int dx, int dy);
    void setColor(sf::Color color);

    sf::Vector2i getPosition() const { return position; }
    sf::Color getColor() const { return circle.getFillColor(); }

protected:
    sf::Vector2i position;
    sf::CircleShape circle;

    void setCirclePosition();
    /* return the adjusted speed after checking bounds
    the speed will not preserve direction or length and just points to new position*/
    sf::Vector2i checkBounds(sf::Vector2i speed);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
