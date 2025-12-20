#pragma once

#include <SFML/Graphics.hpp>
#include <moving.h>
#include <immovable.h>
#include <Constants.h>

class Collider
{
public:
    Collider();
    // return false if position is occupied and entity could not be added
    bool tryAddEntity(const Moving& entity);
    // return false if position is occupied and entity could not be added
    bool tryAddEntity(const Immovable& entity);
    /* this only accepts objects inheriting from moving class
    It returns true if the movement is allowed*/
    bool tryMoveEntity(const sf::Vector2i& fromPos, const sf::Vector2i& toPos);
    
    bool isOccupied(const sf::Vector2i& position) const;
    bool isOccupiedByMoving(const sf::Vector2i& position) const;
    bool isOccupiedByImmovable(const sf::Vector2i& position) const;

    Moving& getMovingEntityAt(const sf::Vector2i& position) const;
    Immovable& getImmovableEntityAt(const sf::Vector2i& position) const;
    
    //returns true if an entity was removed at the given position
    bool removeEntityAt(const sf::Vector2i& position);
    //returns true if an moving entity was removed at the given position
    bool removeMovingAt(const sf::Vector2i& position);
    //returns true if an immovable entity was removed at the given position
    bool removeImmovableAt(const sf::Vector2i& position);

private:
    std::unordered_map<sf::Vector2i, Moving&> mapMovingEntities;
    std::unordered_map<sf::Vector2i, Immovable&> mapImmovableEntities;
};
