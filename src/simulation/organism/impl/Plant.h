//
// Created by liam on 4/10/19.
//

#ifndef CS_3210_PROJECT_ASSIGNMENT_PLANT_H
#define CS_3210_PROJECT_ASSIGNMENT_PLANT_H


#include <src/simulation/organism/Organism.h>

class Plant : public Organism {
private:

    int regrowthCoefficient;

public:

    Plant(int id, Position &position, int energy, int regrowthCoefficient);

    virtual int getRegrowthCoefficient() = 0;

    virtual void setRegrowthCoefficient(int coefficient) = 0;

};


#endif //CS_3210_PROJECT_ASSIGNMENT_PLANT_H
