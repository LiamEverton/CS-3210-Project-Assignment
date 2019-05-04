#ifndef CS_3210_PROJECT_ASSIGNMENT_ENTITY_H
#define CS_3210_PROJECT_ASSIGNMENT_ENTITY_H

#include <memory>

#include <simulation/ecosystem/entity/type/EntityType.h>
#include <simulation/ecosystem/entity/comp/Position.h>

/**
 * Entity represents the base data model used to represent the most basic form of an object in the EcoSystem.
 */
class Entity {
private:

    //The id of the Entity.
    int id;

    //The letter that represents this Entity.
    char letterID;

    //The EntityType of the Entity.
    EntityType type;

    //The Position of the Entity.
    std::shared_ptr<Position> position;

public:

    /**
     * Constructs a new Entity.
     *
     * @param id - the Entity's unique identifier.
     * @param letterID - the Entity's letter identifier.
     * @param type - the Entity's EntityType.
     * @param position - the Entity's Position.
     */
    Entity(const int &id, const char &letterID, const EntityType &type,
           std::shared_ptr<Position> position);

    /**
     * Deconstructs the Entity.
     */
    ~Entity();

    /**
     * Gets the Entity's current Position.
     *
     * @return position - the current Position.
     */
    std::shared_ptr<Position> getPosition();

    /**
     * Gets the Entity's unique identifier.
     *
     * @return id - the Entity's unique identifier.
     */
    const int &getID();

    /**
     * Gets the Entity's Species identifier.
     *
     * @return letter - the Entity's Species identifier.
     */
    const char &getLetterID();

    /**
     * Gets the EntityType of the Entity.
     *
     * @return type - the Entity's EntityType.
     */
    const EntityType &getType();

};

#endif //CS_3210_PROJECT_ASSIGNMENT_ENTITY_H
