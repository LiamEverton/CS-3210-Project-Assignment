#ifndef CS_3210_PROJECT_ASSIGNMENT_ENTITYFACTORY_H
#define CS_3210_PROJECT_ASSIGNMENT_ENTITYFACTORY_H

#include <simulation/ecosystem/entity/comp/Position.h>

/**
 * OrganismFactory, responsible for creation the various Organisms which are defined by the given Species.
 */
class OrganismFactory {

private:

    //The given list of different specie types.
    list<Species> species;

public:

    /**
     * Constructs a new OrganismFactory.
     *
     * @param species - the given list of Species.
     */
    OrganismFactory(const list<Species> &species);

    /**
     * Creates a new Organism, using the given values.
     *
     * @param id - the unique numeric identifier for each Entity in the EcoSystem.
     * @param letterID - the letter which represents the Species of the Organism.
     * @param pos - the Position of the Organism.
     *
     * @return the generated Organism.
     */
    const shared_ptr<Organism> createOrganism(const int &id, const char &letterID, shared_ptr<Position> pos);

    /**
     * Deconstructs the OrganismFactory.
     */
    ~OrganismFactory();
};

#endif //CS_3210_PROJECT_ASSIGNMENT_ENTITYFACTORY_H
