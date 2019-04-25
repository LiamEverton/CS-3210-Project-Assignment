//
// Created by liam on 4/10/19.
//

#include "Animal.h"

Animal::Animal(int id, int energy, int maxEnergy, Position &position) : Organism(id, energy, position) {
}

void Animal::setMaxEnergy(int maxEnergy) {
    this->maxEnergy = maxEnergy;
}

int Animal::getMaxEnergy() {
    return this->maxEnergy;
}