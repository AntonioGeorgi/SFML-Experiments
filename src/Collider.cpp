#include "Collider.h"

Collider::Collider()
{
}

bool Collider::tryAddEntity(const Moving& entity)
{
    sf::Vector2i pos = entity.getPosition();
    if (isOccupied(pos))
        return false;
    mapMovingEntities[pos] = entity;
    return true;
}
bool Collider::tryAddEntity(const Immovable& entity)
{
    sf::Vector2i pos = entity.getPosition();
    if (isOccupied(pos))
        return false;
    mapImmovableEntities[pos] = entity;
    return true;
}
bool Collider::tryMoveEntity(const sf::Vector2i& fromPos, const sf::Vector2i& toPos)
{
    if (!isOccupiedByMoving(fromPos) || isOccupied(toPos))
        return false;
    auto entity = mapMovingEntities[fromPos];
    mapMovingEntities.erase(fromPos);
    mapMovingEntities[toPos] = entity;
    return true;
}

bool Collider::isOccupied(const sf::Vector2i& position) const
{
    return isOccupiedByMoving(position) || isOccupiedByImmovable(position);
}
bool Collider::isOccupiedByMoving(const sf::Vector2i& position) const
{
    return mapMovingEntities.contains(position);
}
bool Collider::isOccupiedByImmovable(const sf::Vector2i& position) const
{
    return mapImmovableEntities.contains(position);
}

bool Collider::removeEntityAt(const sf::Vector2i& position)
{
    return removeMovingAt(position) || removeImmovableAt(position);
}
bool Collider::removeMovingAt(const sf::Vector2i& position)
{
    return mapMovingEntities.erase(position) > 0;
}
bool Collider::removeImmovableAt(const sf::Vector2i& position)
{
    return mapImmovableEntities.erase(position) > 0;
}