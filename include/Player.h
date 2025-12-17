#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
    Player(sf::Vector2i pos, sf::Color color = sf::Color::Blue);

    // Polls keyboard state and moves the player by one tile per call when a key is pressed
    void handleInput(sf::Keyboard::Scancode keyPressedScancode);

    // Placeholder for future per-frame updates
    void update(float dt);
};
