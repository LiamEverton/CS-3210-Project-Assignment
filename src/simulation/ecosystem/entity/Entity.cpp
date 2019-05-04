#include "simulation/ecosystem/entity/comp/Position.h"
#include "Entity.h"

Entity::Entity(const int &id, const char &letterID, const EntityType &type,
               std::shared_ptr<Position> position) {
    this->id = id;
    this->letterID = letterID;
    this->type = type;
    this->position = position;
}

Entity::~Entity() {
}

std::shared_ptr<Position> Entity::getPosition() {
    return this->position;
}

const int &Entity::getID() {
    return this->id;
}

const EntityType &Entity::getType() {
    return this->type;
}

const char &Entity::getLetterID() {
    return this->letterID;
}