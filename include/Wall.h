#pragma once
#include <SFML/Graphics.hpp>
#include <Constants.h>

class Wall : public sf::Drawable
{
public:
    Wall(sf::Vector2i pos, sf::Color color = sf::Color::White);
    Wall(int x, int y , sf::Color color = sf::Color::White);
    void setColor(sf::Color color);

    sf::Vector2i getPosition() const { return position; }
    sf::Color getColor() const { return square.getFillColor(); }

private:
    sf::Vector2i position;
    sf::RectangleShape square;

    void setSquarePosition();
    void checkBounds();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
