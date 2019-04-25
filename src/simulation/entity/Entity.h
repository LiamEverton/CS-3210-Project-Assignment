//
// Created by liam on 4/22/19.
//

#ifndef CS_3210_PROJECT_ASSIGNMENT_ENTITY_H
#define CS_3210_PROJECT_ASSIGNMENT_ENTITY_H

#include <src/simulation/comp/Position.h>

class Entity {
private:
    //The id of the Entity.
    int id;

    //The Position of the Entity.
    Position position;

public:

    Entity(int id, Position &position);

    virtual ~Entity() = 0;

    /**
     * Sets the entity's current position.
     *
     * @param position - the position to set.
     */
    virtual void setPosition(Position position) = 0;

    /**
     * Gets the organism's current position.
     *
     * @return position - the current position.
     */
    virtual Position getPosition() = 0;

    /**
     * Gets the organism's id.
     *
     * @return id - the organism's id.
     */
    virtual int getID() = 0;

};

#endif //CS_3210_PROJECT_ASSIGNMENT_ENTITY_H
