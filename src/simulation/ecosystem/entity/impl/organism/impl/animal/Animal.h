#ifndef CS_3210_PROJECT_ASSIGNMENT_ANIMAL_H
#define CS_3210_PROJECT_ASSIGNMENT_ANIMAL_H

#include <simulation/ecosystem/entity/impl/organism/Organism.h>
#include <simulation/ecosystem/entity/type/EntityType.h>
#include <simulation/ecosystem/entity/comp/Position.h>

/**
 * Animal, represents an implementation of Organism to represent an Animal in the EcoSystem.
 */
class Animal : public Organism {

public:
    /**
     * Constructs a new Animal.
     *
     * @param id - the unique identifier of the Animal in the EcoSystem.
     * @param letterID - the Species of the Animal.
     * @param type - the EntityType of the Animal.
     * @param position - the Position of the Animal.
     * @param foodChain - the Animal's food chain.
     * @param energy - the Animal's current energy.
     * @param maxEnergy - the Animal's maximum energy.
     */
    Animal(const int &id, const char &letterID, const EntityType &type, shared_ptr<Position> position,
           const list<char> &foodChain, int energy,
           int maxEnergy);

    /**
     * Attempts to move the Animal.
     *
     * @param iteration - the specified Iteration this Animal currently functions in.
     *
     * @return whether or not the Animal successfully moved or not.
     */
    bool move(const shared_ptr<Iteration> &iteration);

    /**
     * Attempts to grow the Animal.
     *
     * @param iteration - the specified Iteration this Animal currently functions in.
     *
     * @return whether or not the Animal successfully grew or not.
     */
    bool grow(const shared_ptr<Iteration> &iteration);

    /**
     * Attempts to consume another Animal.
     *
     * @param iteration - the specified Iteration this Animal currently functions in.

     * @return whether or not the Animal has successfully consumed another or not.
     */
    bool consume(const shared_ptr<Iteration> &iteration);

    /**
     * Attempts to reproduce with another Animal.
     *
     * @param iteration - the specified Iteration this Animal currently functions in.

     * @return whether or not the Animal has successfully reproduced with another or not.
     */
    bool reproduce(const shared_ptr<Iteration> &iteration);
};


#endif //CS_3210_PROJECT_ASSIGNMENT_ANIMAL_H
