#include <simulation/ecosystem/EcoSystem.h>
#include <simulation/ecosystem/iteration/Iteration.h>
#include <simulation/ecosystem/entity/type/EntityType.h>
#include <simulation/ecosystem/entity/comp/Position.h>
#include <simulation/ecosystem/entity/impl/organism/Organism.h>
#include "Plant.h"

Plant::Plant(const int &id, const char &letterID, const EntityType &entityType,
             shared_ptr<Position> position,
             const list<char> &foodChain,
             int energy, int maxEnergy, int regrowthCoefficient)
        : Organism(id, letterID, entityType, std::move(position), foodChain, energy, maxEnergy) {

    this->regrowthCoefficient = regrowthCoefficient;
}

bool Plant::move(const shared_ptr<Iteration> &iteration) {
    return false;
}

bool Plant::grow(const shared_ptr<Iteration> &iteration) {
    //Plant can only grow if it is dead.
    if (this->getEnergy() == 0) {
        //Increment the growth stage by 1.
        this->growthStage = growthStage + 1;

        //Check if it's ready to grow.
        if (this->growthStage >= this->regrowthCoefficient) {

            //Check if there isn't anything currently occupying this tile.
            if (iteration->getEcoSystem()->getMap()
                [this->getPosition()->getX()]
                [this->getPosition()->getY()] == ' ') {


                //Sets the Plant's current energy.
                this->setEnergy(this->getMaxEnergy());

                //Reset growth stage.
                this->growthStage = 0;

                //We have successfully grown the plant!
                return true;
            }
        }

    }

    return false;
}

bool Plant::consume(const shared_ptr<Iteration> &iteration) {
    return false;
}

int Plant::getRegrowthCoefficient() {
    return this->regrowthCoefficient;
}