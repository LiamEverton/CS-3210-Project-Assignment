#ifndef CS_3210_PROJECT_ASSIGNMENT_ECOSYSTEM_H

#define CS_3210_PROJECT_ASSIGNMENT_ECOSYSTEM_H

#include <string>
#include <list>
#include <memory>
#include <input/InputProcessor.h>

class Organism;

class Animal;

using namespace std;

class EcoSystem {

private:

    int idCounter;

    int mapHeight;

    int mapWidth;

    char **map;

    shared_ptr<list<shared_ptr<Organism>>> organisms;

public:

    EcoSystem(int idCounter, int mapHeight, int mapWidth, char **map,
              shared_ptr<list<shared_ptr<Organism>>> organisms);

    void run(int iterations);

    void printState();

    void updateTile(char letter, int x, int y);

    void moveTile(int newX, int newY, int oldX, int oldY);

    bool isWithinMap(int x, int y);

    bool isValidMove(Animal *organism, int x, int y);

    list<shared_ptr<Organism>>
    getNearbyOrganisms(const shared_ptr<Organism> &organism, int xDistance, int yDistance);

    shared_ptr<list<shared_ptr<Organism>>> getOrganisms();

    void setIDCounter(int idCounter);

    char **getMap();

    int getMapWidth();

    int getMapHeight();

    int getIDCounter();

    ~EcoSystem();
};


#endif //CS_3210_PROJECT_ASSIGNMENT_ECOSYSTEM_H
