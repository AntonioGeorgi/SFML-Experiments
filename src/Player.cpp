#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Player::Player(sf::Vector2i pos, Collider& collider, sf::Color color)
    : Moving(pos, color), collider(collider)
{
}

void Player::handleInput(sf::Keyboard::Scancode keyPressedScancode)
{
    if (keyPressedScancode == sf::Keyboard::Scancode::A || keyPressedScancode == sf::Keyboard::Scancode::Left) {
        if (collider.tryMoveEntity(getPosition(), getPosition() + sf::Vector2i(-1, 0))) {
            move(-1, 0);
            // std::cout << "Movement to the left!" << std::endl;
        }
        // else {
        //     std::cout << "Movement blocked to the left!" << std::endl;
        // }
    }
    else if (keyPressedScancode == sf::Keyboard::Scancode::D || keyPressedScancode == sf::Keyboard::Scancode::Right) {
        if (collider.tryMoveEntity(getPosition(), getPosition() + sf::Vector2i(1, 0))) {
            move(1, 0);
        }
    }

    else if (keyPressedScancode == sf::Keyboard::Scancode::W || keyPressedScancode == sf::Keyboard::Scancode::Up) {
        if (collider.tryMoveEntity(getPosition(), getPosition() + sf::Vector2i(0, -1))) {
            move(0, -1);
        }
    }
    else if (keyPressedScancode == sf::Keyboard::Scancode::S || keyPressedScancode == sf::Keyboard::Scancode::Down) {
        if (collider.tryMoveEntity(getPosition(), getPosition() + sf::Vector2i(0, 1))) {
            move(0, 1);
        }
    }
}

void Player::update(float dt)
{
    (void)dt; // not used yet
}
