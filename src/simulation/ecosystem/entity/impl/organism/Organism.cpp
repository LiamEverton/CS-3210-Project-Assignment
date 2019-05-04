#include "Organism.h"

Organism::Organism(const int &id, const char &letterID, const EntityType &type,
                   shared_ptr<Position> position,
                   const list<char> &foodChain, int energy, int maxEnergy)
        : Entity(id, letterID, type, std::move(position)) {

    this->foodChain = foodChain;
    this->energy = energy;
    this->maxEnergy = maxEnergy;
}

bool Organism::canBeKilledBy(const shared_ptr<Organism> &killer) {

    for (char speciesID: killer->getFoodChain()) {
        if (speciesID == this->getLetterID()) {

            return true;
        }
    }

    return false;
}

bool Organism::canEat(const shared_ptr<Organism> &organism) {
    for (char currentPrey: this->getFoodChain()) {
        if (currentPrey == organism->getLetterID()) {

            return true;
        }
    }

    return false;
}

Organism::~Organism() {
}

void Organism::setEnergy(int energy) {
    this->energy = energy;
}

int Organism::getEnergy() {
    return this->energy;
}

void Organism::setMaxEnergy(int maxEnergy) {
    this->maxEnergy = maxEnergy;
}

int Organism::getMaxEnergy() {
    return this->maxEnergy;
}

const list<char> &Organism::getFoodChain() {
    return this->foodChain;
}
