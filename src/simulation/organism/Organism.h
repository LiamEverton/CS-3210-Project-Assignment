//
// Created by liam on 4/10/19.
//

#ifndef CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H
#define CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H


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
     * Moves the organism.
     *
     * @return whether or not the organism successfully moved or not.
     */
    bool move();

    /**
     * Grows the organism.
     *
     * @return whether or not the organism successfully grew or not.
     */
    bool grow();

    /**
     * Consumes the specified organism.
     *
     * @param target - the organism to eat.
     *
     * @return whether or not the target organism has been successfully eaten.
     */
    bool consume(Organism target);

    /**
     * Sets the current energy level.
     *
     * @param energy - the current energy level.
     */
    void setEnergy(int energy) {
        this->energy = energy;
    }

    /**
     * Sets the organism's current position.
     *
     * @param position - the position to set.
     */
    void setPosition(Position position) {
        this->position = position;
    }

    /**
     * Gets the current energy level.
     *
     * @return energy - the current energy level.
     */
    int getEnergy() {
        return this->energy;
    }

    /**
     * Gets the organism's current position.
     *
     * @return position - the current position.
     */
    Position getPosition() {
        return this->position;
    }

    /**
     * Gets the organism's id.
     *
     * @return id - the organism's id.
     */
    int getID() {
        return this->id;
    }
};


#endif //CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H
