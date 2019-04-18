//
// Created by liam on 4/10/19.
//

#ifndef CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H
#define CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H

#include <Position.h>

class Organism {

private:

    //The id of the organism.
    int id;

    //The current energy level of the organism.
    int energy;

    //The current position of the organism.
    Position position;

public:

    /**
     * Constructs a new Organism using the given parameters.
     * @param id - the organism's id.
     * @param energy - the organism's energy.
     * @param position - the organism's current position.
     */
    Organism(int id, int energy, Position position) {
        this->id = id;
        this->energy = energy;
        this->position = position;
    }

    ~Organism() {
        delete id;
        delete energy;
        delete position;
    }

    /**
     * Moves the organism.
     *
     * @return whether or not the organism successfully moved or not.
     */
    virtual bool move();

    /**
     * Grows the organism.
     *
     * @return whether or not the organism successfully grew or not.
     */
    virtual bool grow();

    /**
     * Consumes the specified organism.
     *
     * @param target - the organism to eat.
     *
     * @return whether or not the target organism has been successfully eaten.
     */
    virtual bool consume(Organism target);

    /**
     * Sets the current energy level.
     *
     * @param energy - the current energy level.
     */
    virtual void setEnergy(int energy);

    /**
     * Sets the organism's current position.
     *
     * @param position - the position to set.
     */
    virtual void setPosition(Position position);

    /**
     * Gets the current energy level.
     *
     * @return energy - the current energy level.
     */
    virtual int getEnergy();

    /**
     * Gets the organism's current position.
     *
     * @return position - the current position.
     */
    virtual Position getPosition();

    /**
     * Gets the organism's id.
     *
     * @return id - the organism's id.
     */
    virtual int getID();
};


#endif //CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H
