#pragma once

#include "Immovable.h"

class Wall : public Immovable
{
public:
    Wall(sf::Vector2i pos, sf::Color color = sf::Color::White);
    Wall(int x, int y, sf::Color color = sf::Color::White);

private:
};
