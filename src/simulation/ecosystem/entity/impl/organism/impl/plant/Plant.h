#ifndef CS_3210_PROJECT_ASSIGNMENT_PLANT_H
#define CS_3210_PROJECT_ASSIGNMENT_PLANT_H

#include "simulation/ecosystem/entity/impl/organism/Organism.h"

/**
 * Plant, represents an implementation of the Organism, similar to the Animal class.
 */
class Plant : public Organism {
private:

    //The Plant's current growth stage.
    int growthStage = 0;

    //The Plant's regrowth coefficient.
    int regrowthCoefficient;

public:

    /**
     * Constructs a new Plant using the given parameters.
     *
     * @param id - the Plant's id.
     * @param type - the Plant's type.
     * @param position - the Plant's position.
     * @param foodChain - the Plant's food chain.
     * @param energy - the Plant's energy.
     * @param maxEnergy - the Plant's maximum energy.
     */
    Plant(const int &id, const char &letterID, const EntityType &entityType, shared_ptr<Position> position,
          const list<char> &foodChain, int energy, int maxEnergy, int regrowthCoefficient);

    /**
     * Attempts to move the Plant.
     *
     * @param iteration - the specified Iteration this Plant currently functions in.
     *
     * @return whether or not the Plant successfully moved or not.
     */
    bool move(const shared_ptr<Iteration> &iteration);

    /**
     * Attempts to grow the Plant.
     *
     * @param iteration - the specified Iteration this Plant currently functions in.
     *
     * @return whether or not the Plant successfully grew or not.
     */
    bool grow(const shared_ptr<Iteration> &iteration);

    /**
     * Attempts to consume another Plant.
     *
     * @param iteration - the specified Iteration this Plant currently functions in.

     * @return whether or not the Plant has successfully consumed another or not.
     */
    bool consume(const shared_ptr<Iteration> &iteration);

    /**
     * Gets the Plant's regrowth coefficient.
     *
     * @return the Plant's regrowth coefficient.
     */
    int getRegrowthCoefficient();
};


#endif //CS_3210_PROJECT_ASSIGNMENT_PLANT_H
