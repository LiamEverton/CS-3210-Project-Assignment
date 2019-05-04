#include "Iteration.h"

#include  <simulation/ecosystem/EcoSystem.h>
#include <simulation/ecosystem/entity/impl/organism/impl/plant/Plant.h>
#include <simulation/ecosystem/entity/impl/organism/impl/animal/Animal.h>
#include  <simulation/ecosystem/entity/type/EntityType.h>

Iteration::Iteration(EcoSystem *ecosystem) {
    this->ecosystem = ecosystem;
}

void Iteration::run() {
    shared_ptr<list<shared_ptr<Organism>>> organisms = this->ecosystem->getOrganisms();

    //Allow for all Plants to go first.
    for (auto it = organisms->begin(); it != organisms->end(); it++) {
        const shared_ptr<Organism> &organism = *it;

        if (organism->getType() == EntityType::PLANT) {

            auto plant = dynamic_cast< Plant * > (organism.get());

            //Check if the plant has grown.
            if (plant->grow(make_shared<Iteration>(*this))) {
                //The plant has grown, so let's update the map.
                ecosystem->updateTile(plant->getLetterID(), plant->getPosition()->getX(), plant->getPosition()->getY());
            }
        }
    }

    //Allow for all Herbivores t o go second.
    for (auto it = organisms->begin(); it != organisms->end();) {
        const shared_ptr<Organism> &organism = *it;

        if (organism->getType() == EntityType::HERBIVORE) {

            auto herbivore = dynamic_cast< Animal *> (organism.get());

            //Cache previous position.
            int cachedX = herbivore->getPosition()->getX();
            int cachedY = herbivore->getPosition()->getY();

            //Check if it is dead already.
            if (herbivore->getEnergy() == 0) {
                //Remove current letter from map location, if it was a natural death.
                if (ecosystem->getMap()
                    [herbivore->getPosition()->getX()][herbivore->getPosition()->getY()] == herbivore->getLetterID()) {
                    ecosystem->updateTile(' ', herbivore->getPosition()->getX(), herbivore->getPosition()->getY());
                }

                it = organisms->erase(it);
            } else {

                const shared_ptr<Iteration> iterationPointer = make_shared<Iteration>(*this);

                //Check if organism has successfully moved.
                if (herbivore->move(iterationPointer)) {
                    //Update map of our movement.
                    ecosystem->moveTile(herbivore->getPosition()->getX(), herbivore->getPosition()->getY(), cachedX,
                                        cachedY);
                }

                //Try to consume an animal.
                if (herbivore->consume(iterationPointer)) {
                    ecosystem->updateTile(herbivore->getLetterID(),
                                          herbivore->getPosition()->getX(),
                                          herbivore->getPosition()->getY());
                }

                //Try to reproduce with another animal.
                herbivore->reproduce(iterationPointer);

                //Reduce energy points by 1.
                herbivore->setEnergy(herbivore->getEnergy() - 1);

                //Increment iterator.
                it++;
            }
        } else {
            //Increment iterator.
            it++;
        }
    }

    //Allow for all Omnviores to go third.
    for (auto it = organisms->begin(); it != organisms->end();) {
        const shared_ptr<Organism> &organism = *it;
        if (organism->getType() == EntityType::OMNIVORE) {

            auto omnivore = dynamic_cast< Animal *> (organism.get());

            //Cache previous position.
            int cachedX = omnivore->getPosition()->getX();
            int cachedY = omnivore->getPosition()->getY();

            if (omnivore->getEnergy() == 0) {
                //Kill animal.

                //Remove current letter from map location, if it was a natural death.
                if (ecosystem->getMap()
                    [omnivore->getPosition()->getX()][omnivore->getPosition()->getY()] == omnivore->getLetterID()) {
                    ecosystem->updateTile(' ', omnivore->getPosition()->getX(), omnivore->getPosition()->getY());
                }

                //Remove from EcoSystem.
                it = organisms->erase(it);
            } else {

                const shared_ptr<Iteration> iterationPointer = make_shared<Iteration>(*this);

                //Check if organism has successfully moved.
                if (omnivore->move(iterationPointer)) {
                    //Update map of our movement.
                    ecosystem->moveTile(omnivore->getPosition()->getX(), omnivore->getPosition()->getY(), cachedX,
                                        cachedY);
                }

                //Try to consume an animal.
                if (omnivore->consume(iterationPointer)) {
                    // cout << "consumed!" << endl;
                    ecosystem->updateTile(omnivore->getLetterID(),
                                          omnivore->getPosition()->getX(),
                                          omnivore->getPosition()->getY());
                }

                //Try to reproduce with another animal.
                omnivore->reproduce(iterationPointer);

                //Reduce energy points by 1.
                omnivore->setEnergy(omnivore->getEnergy() - 1);

                //Increment iterator.
                it++;
            }
        } else {
            //Increment iterator.
            it++;
        }
    }
}

EcoSystem *Iteration::getEcoSystem() {
    return this->ecosystem;
}


