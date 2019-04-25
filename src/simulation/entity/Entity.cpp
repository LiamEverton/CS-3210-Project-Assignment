#include "Entity.h"

Entity::Entity(int id, Position &position) {
    this->id = id;
    this->position = position;
}

Entity::~Entity() {
    delete &position;
}

/**
 * Sets the entity's current position.
 *
 * @param position - the position to set.
 */
void Entity::setPosition(Position position) {
    this->position = position;
}

/**
 * Gets the organism's current position.
 *
 * @return position - the current position.
 */
Position Entity::getPosition() {
    return this->position;
}

/**
 * Gets the organism's id.
 *
 * @return id - the organism's id.
 */
int Entity::getID() {
    return this->id;
}
