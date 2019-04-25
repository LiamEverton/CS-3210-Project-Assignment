//
// Created by liam on 4/10/19.
//

#ifndef CS_3210_PROJECT_ASSIGNMENT_ANIMAL_H
#define CS_3210_PROJECT_ASSIGNMENT_ANIMAL_H


#include <src/simulation/entity/Entity.h>

class Animal : public Organism {
private:
    int maxEnergy;

public:

    Animal(int id, int energy, int maxEnergy, Position &position);

    virtual void setMaxEnergy(int maxEnergy) = 0;

    virtual int getMaxEnergy() = 0;
};


#endif //CS_3210_PROJECT_ASSIGNMENT_ANIMAL_H
