//
// Created by liam on 4/10/19.
//

#include "Plant.h"

Plant::Plant(int id, Position &position, int energy, int regrowthCoefficient) : Organism(id, energy, position) {
    this->regrowthCoefficient = regrowthCoefficient;
}

int Plant::getRegrowthCoefficient() {
    return this->regrowthCoefficient;
}

void Plant::setRegrowthCoefficient(int coefficient) {
    this->regrowthCoefficient = coefficient;
}