//
// Created by liam on 4/10/19.
//

#ifndef CS_3210_PROJECT_ASSIGNMENT_POSITION_H
#define CS_3210_PROJECT_ASSIGNMENT_POSITION_H

#include <src/simulation/organism/Organism.h>

class Position {
private:
    int x, y;

public:
    Position() {
        this->x = 0;
        this->y = 0;
    }

    Position(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int virtual setX(int x);

    int virtual setY(int y);

    int virtual getX();

    int virtual getY();
};

#endif //CS_3210_PROJECT_ASSIGNMENT_POSITION_H
