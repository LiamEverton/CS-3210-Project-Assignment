

#ifndef CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H
#define CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H

#include <list>
#include <simulation/ecosystem/entity/Entity.h>
#include <simulation/ecosystem/entity/comp/Position.h>

using namespace std;

//Forward declaration.
class Iteration;

/**
 * Organism, represents a living Entity within the EcoSystem.
 */
class Organism : public Entity {

private:

    // The current energy level of the organism.
    int energy;

    // The maximum possible energy level of the organism.
    int maxEnergy;

    // The food chain of the organism.
    list<char> foodChain;

public:

    /**
     * Constructs a new Organism using the given parameters.
     *
     * @param id - the Organism's id.
     * @param type - the Organism's type.
     * @param position - the Organism's position.
     * @param energy - the Organism's energy.
     * @param foodChain - the Organism's food chain.
     */
    Organism(const int &id, const char &letterID, const EntityType &type,
             shared_ptr<Position> position,
             const list<char> &foodChain, int energy, int maxEnergy);

    /**
     * Checks whether or not this Organism can be killed by the specified Organism.
     *
     * @param killer - the possible killer Organism.
     *
     * @return whether or not the target organism can kill this Organism.
     */
    bool canBeKilledBy(const shared_ptr<Organism> &killer);

    /**
     * Checks whether it possible to eat the given Organism.
     *
     * @param organism - the specified Organism.
     *
     * @return whether or not the specified Organism can be eaten.
     */
    bool canEat(const shared_ptr<Organism> &organism);

    /**
     * Attempts to move the Organism.
     *
     * @param iteration - the specified Iteration this Organism currently functions in.
     *
     * @return whether or not the Organism successfully moved or not.
     */
    virtual bool move(const shared_ptr<Iteration> &iteration) = 0;

    /**
     * Attempts to grow the Organism.
     *
     * @param iteration - the specified Iteration this Organism currently functions in.
     *
     * @return whether or not the Organism successfully grew or not.
     */
    virtual bool grow(const shared_ptr<Iteration> &iteration) = 0;

    /**
     * Attempts to consume another Organism.
     *
     * @param iteration - the specified Iteration this Organism currently functions in.

     * @return whether or not the Organism has successfully consumed another or not.
     */
    virtual bool consume(const shared_ptr<Iteration> &iteration) = 0;

    /**
     * Deconstructor.
     */
    virtual ~Organism();

    /**
     * Sets the Organism's current energy level.
     *
     * @param energy - the current energy level.
     */
    void setEnergy(int energy);

    /**
     * Sets the Organism's maximum energy level.
     *
     * @param maxEnergy - the specified maximum energy.
     */
    void setMaxEnergy(int maxEnergy);

    /**
     * Gets the Organism's current energy level.
     *
     * @return energy - the current energy level.
     */
    int getEnergy();

    /**
     * Gets the Organism's maximum energy.
     *
     * @return maxEnergy - the maximum energy level.
     */
    int getMaxEnergy();

    /**
     * Gets the Organism's food chain.
     *
     * @return foodchain - the Organism's food chain.
     */
    const list<char> &getFoodChain();
};


#endif //CS_3210_PROJECT_ASSIGNMENT_ORGANISM_H
