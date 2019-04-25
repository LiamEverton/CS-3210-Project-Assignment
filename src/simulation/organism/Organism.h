//
// Created by liam on 4/10/19.
//

#ifndef CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H
#define CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H

#include <Position.h>
#include <src/simulation/entity/Entity.h>

class Organism : public Entity {

private:

    // The current energy level of the organism.
    int energy;

public:

    /**
     * Default Constructor.
     */
    virtual Organism() = 0;

    /**
     * Constructor cannot be virtual
     */
    Organism(int id, int energy, Position &position) = 0;

    virtual Organism(int energy) = 0;

    /**
     * Deconstructor.
     */
    virtual ~Organism();

    /**
     * Moves the organism.
     *
     * @return whether or not the organism successfully moved or not.
     */
    virtual bool move() = 0;

    /**
     * Grows the organism.
     *
     * @return whether or not the organism successfully grew or not.
     */
    virtual bool grow() = 0;

    /**
     * Consumes the specified organism.
     *
     * @param target - the organism to eat.
     *
     * @return whether or not the target organism has been successfully eaten.
     */
    virtual bool consume(Organism target) = 0;

    /**
     * Sets the current energy level.
     *
     * @param energy - the current energy level.
     */
    virtual void setEnergy(int energy) = 0;

    /**
     * Gets the current energy level.
     *
     * @return energy - the current energy level.
     */
    virtual int getEnergy() = 0;
};


#endif //CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H
