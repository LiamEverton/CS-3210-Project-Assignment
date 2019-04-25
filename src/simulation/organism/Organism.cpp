#include "Organism.h"

/**
 * Constructs a new Organism using the given parameters.
 * @param id - the organism's id.
 * @param energy - the organism's energy.
 * @param position - the organism's current position.
 */
Organism::Organism(int id, int energy, Position &position) : Entity(id, position) {
    this->energy = energy;
}

/**
 * Deconstructor.
 */
Organism::~Organism() {
}

void Organism::setEnergy(int energy) {
    this->energy = energy;
}

int Organism::getEnergy() {
    return this->energy;
}