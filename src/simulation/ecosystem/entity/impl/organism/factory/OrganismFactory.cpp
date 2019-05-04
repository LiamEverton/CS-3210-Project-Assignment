#include <input/InputProcessor.h>
#include <simulation/ecosystem/entity/Entity.h>
#include <simulation/ecosystem/entity/impl/organism/impl/animal/Animal.h>
#include <simulation/ecosystem/entity/impl/organism/impl/plant/Plant.h>
#include "OrganismFactory.h"

OrganismFactory::OrganismFactory(const list<Species> &species) {
    this->species = species;
}

const shared_ptr<Organism>
OrganismFactory::createOrganism(const int &id, const char &letterID, shared_ptr<Position> pos) {

    //Iterate over each possible Species.
    for (const Species &specie : this->species) {

        //Check if the species is equal.
        if (specie.letterID == letterID) {

            //Create entity based on type.
            if (specie.type == EntityType::OMNIVORE ||
                specie.type == EntityType::HERBIVORE) {

                //Create Animal.
                return make_shared<Animal>(id, specie.letterID, specie.type, pos, specie.foodchain, specie.maxEnergy,
                                           specie.maxEnergy);

            } else if (specie.type == EntityType::PLANT) {

                //Create Plant.
                return make_shared<Plant>(id, specie.letterID, specie.type, pos, specie.foodchain,
                                          specie.characteristics[1],
                                          specie.characteristics[1],
                                          specie.characteristics[0]);
            }
        }
    }

    //If the character isn't an organism/species, it's a tile.
    return nullptr;
}

OrganismFactory::~OrganismFactory() {
}
