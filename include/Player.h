#pragma once

#include "Moving.h"
#include <Collider.h>

class Player : public Moving
{
public:
    Player(sf::Vector2i pos, Collider& collider, sf::Color color = sf::Color::Blue);

    // Polls keyboard state and moves the player by one tile per call when a key is pressed
    void handleInput(sf::Keyboard::Scancode keyPressedScancode);

    // Placeholder for future per-frame updates
    void update(float dt);

    private:
        Collider& collider;
};
