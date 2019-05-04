#include <utility>

#include "Simulation.h"

#include <cstddef>
#include <simulation/ecosystem/entity/Entity.h>
#include <simulation/ecosystem/EcoSystem.h>
#include <simulation/ecosystem/entity/impl/organism/factory/OrganismFactory.h>
#include <input/InputProcessor.h>

Simulation::Simulation(list<char> possibleTiles, const string &mapFileName,
                       const string &speciesFileName) {
    this->inputProcessor = InputProcessor(std::move(possibleTiles), mapFileName, speciesFileName);
}

EcoSystem Simulation::createEcoSystem() {

    //Unique id counter.
    int currentIDCounter = 0;

    //Read input files.
    list<Species> species = this->inputProcessor.readSpecies();
    char **map = this->inputProcessor.readMap(&species);

    OrganismFactory organismFactory = OrganismFactory(&species);
    list<shared_ptr<Organism>> organisms;

    //Iterate over each possible position in the map.
    for (int x = 0; x < this->inputProcessor.getMapHeight(); x++) {
        for (int y = 0; y < this->inputProcessor.getMapWidth(); y++) {

            //Create Organism.
            shared_ptr<Organism> organism = organismFactory.createOrganism(
                    currentIDCounter,
                    map[x][y],
                    make_shared<Position>(x, y));

            //Successfully created an organism.
            if (organism != nullptr) {
                organisms.push_back(organism);

                //Increment the entity counter.
                currentIDCounter = currentIDCounter + 1;
            }
        }
    }

    //Create EcoSystem using the generated map and organisms.
    EcoSystem ecoSystem = EcoSystem(currentIDCounter, this->inputProcessor.getMapHeight(),
                                    this->inputProcessor.getMapWidth(),
                                    map,
                                    make_shared<list<shared_ptr<Organism>>>(organisms));

    return ecoSystem;
}

InputProcessor Simulation::getInputProcesor() {
    return this->inputProcessor;
}