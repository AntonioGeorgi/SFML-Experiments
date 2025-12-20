#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player(sf::Vector2i pos, sf::Color color)
    : Moving(pos, color)
{
}

void Player::handleInput(sf::Keyboard::Scancode keyPressedScancode)
{
    if (keyPressedScancode == sf::Keyboard::Scancode::A || keyPressedScancode == sf::Keyboard::Scancode::Left) {
        move(-1, 0);
    }
    else if (keyPressedScancode == sf::Keyboard::Scancode::D || keyPressedScancode == sf::Keyboard::Scancode::Right) {
        move(1, 0);
    }

    else if (keyPressedScancode == sf::Keyboard::Scancode::W || keyPressedScancode == sf::Keyboard::Scancode::Up) {
        move(0, -1);
    }
    else if (keyPressedScancode == sf::Keyboard::Scancode::S || keyPressedScancode == sf::Keyboard::Scancode::Down) {
        move(0, 1);
    }
}

void Player::update(float dt)
{
    (void)dt; // not used yet
}
