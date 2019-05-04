#include <utility>


#include <simulation/ecosystem/entity/impl/organism/impl/plant/Plant.h>
#include <simulation/ecosystem/entity/impl/organism/impl/animal/Animal.h>
#include <simulation/ecosystem/iteration/Iteration.h>
#include "EcoSystem.h"

EcoSystem::EcoSystem(int idCounter, int mapWidth, int mapHeight, char **map,
                     shared_ptr<list<shared_ptr<Organism>>> organisms) {
    this->idCounter = idCounter;
    this->mapHeight = mapHeight;
    this->mapWidth = mapWidth;

    this->map = map;
    this->organisms = std::move(organisms);
}

void EcoSystem::run(int iterations) {
    for (int iterationCounter = 0; iterationCounter < iterations; iterationCounter++) {
        auto iteration = Iteration(this);
        iteration.run();
    }
}

void EcoSystem::printState() {
    //Iterate over each possible position in the map.
    for (int x = 0; x < this->getMapWidth(); x++) {
        for (int y = 0; y < this->getMapHeight(); y++) {
            cout << map[x][y];
        }
        cout << endl;
    }


    cout << "Organisms: " << organisms->size() << endl;
}


void EcoSystem::updateTile(char letter, int x, int y) {
    map[x][y] = letter;
}

void EcoSystem::moveTile(int newX, int newY, int oldX, int oldY) {
    char value = map[oldX][oldY];

    map[oldX][oldY] = ' ';

    map[newX][newY] = value;
}

bool EcoSystem::isValidMove(Animal *animal, int x, int y) {
    //Check whether we are still in the map boundary.
    if (isWithinMap(x, y)) {
        //Check if we are moving into an open space.
        if (map[x][y] == ' ') {
            return true;
        } else {
            //Check if we are moving ontop of valid prey target.
            for (char prey: animal->getFoodChain()) {
                if (map[x][y] == prey) {

                    //A valid prey target must satisfy rule #9.
                    //Killer should not have max energy.
                    if (animal->getEnergy() < animal->getMaxEnergy()) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool EcoSystem::isWithinMap(int x, int y) {
    return (x < mapWidth && x > 0) &&
           y < mapHeight && y > 0;

}

list<shared_ptr<Organism>> EcoSystem::getNearbyOrganisms(const shared_ptr<Organism> &organism, int xDistanceOffSet, int yDistanceOffSet) {
    list<shared_ptr<Organism>> found;

    //Iterate over each organism in the simulation.
    for (const shared_ptr<Organism> &currentOrganism: *this->organisms) {

        //Iterate through each nearby x, y position combination, to see if the organism's position matches.
        for (int possibleX = organism->getPosition()->getX() - xDistanceOffSet;
             possibleX <= organism->getPosition()->getX() + xDistanceOffSet;
             possibleX++) {

            for (int possibleY = organism->getPosition()->getY() - yDistanceOffSet;
                 possibleY <= organism->getPosition()->getY() + yDistanceOffSet;
                 possibleY++) {

                if (this->isWithinMap(possibleX, possibleY)) {

                    //Check if the currentOrganism is equal to our possible positions.
                    if (currentOrganism->getPosition()->getX() == possibleX &&
                        currentOrganism->getPosition()->getY() == possibleY) {

                        //Check if it is not equal to our current position (make sure it's not ourselves).
                        if (organism->getPosition()->getX() != possibleX &&
                            organism->getPosition()->getY() != possibleY) {

                            //Check if current organism is currently alive.
                            if (currentOrganism->getEnergy() > 0) {
                                found.push_back(currentOrganism);
                            }
                        }
                    }
                }
            }
        }
    }

    return found;
}

void EcoSystem::setIDCounter(int idCounter) {
    this->idCounter = idCounter;
}

shared_ptr<list<shared_ptr<Organism>>> EcoSystem::getOrganisms() {
    return this->organisms;
}

char **EcoSystem::getMap() {
    return this->map;
}

int EcoSystem::getMapWidth() {
    return this->mapWidth;
}

int EcoSystem::getMapHeight() {
    return this->mapHeight;
}

int EcoSystem::getIDCounter() {
    return this->idCounter;
}

EcoSystem::~EcoSystem() {
    delete[] map;
}
