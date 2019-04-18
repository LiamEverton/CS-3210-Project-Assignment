//
// Created by liam on 4/10/19.
//

#include "Organism.h"

void Organism::setEnergy(int energy) {
    this->energy = energy;
}

void Organism::setPosition(Position position) {
    this->position = position;
}

int Organism::getEnergy() {
    return this->energy;
}

Position Organism::getPosition() {
    return this->position;
}

int Organism::getID() {
    return this->id;
}