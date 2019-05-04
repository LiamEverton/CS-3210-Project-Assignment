#include "Animal.h"

#include <simulation/ecosystem/EcoSystem.h>
#include <simulation/ecosystem/iteration/Iteration.h>

#include <simulation/ecosystem/entity/comp/Position.h>
#include <simulation/ecosystem/entity/type/EntityType.h>
#include <simulation/ecosystem/entity/Entity.h>
#include <simulation/ecosystem/entity/impl/organism/Organism.h>

Animal::Animal(const int &id, const char &letterID, const EntityType &type,
               shared_ptr<Position> position,
               const list<char> &foodChain, int energy, int maxEnergy)
        : Organism(id, letterID, type, std::move(position), foodChain, energy, maxEnergy) {
    //Empty
}

bool Animal::move(const shared_ptr<Iteration> &iteration) {

    //MODE: ENDANGERED.

    //Iterate through each possible attacker nearby.
    for (const shared_ptr<Organism> &organism: *iteration->getEcoSystem()->getOrganisms()) {

        //Check if organism is still alive (could be dead).
        if (organism->getEnergy() > 0) {

            //Check if we can be killed by organism.
            if (this->canBeKilledBy(organism)) {
                int distance = abs(organism->getPosition()->getX() - this->getPosition()->getX())
                               + abs(organism->getPosition()->getY() - this->getPosition()->getY());

                //As close as we will allow to attackers.
                if (distance <= 4) {

                    //Found attacker, lets move away from it, based on current position.
                    int xDifference = organism->getPosition()->getX() - this->getPosition()->getX();
                    int yDifference = organism->getPosition()->getY() - this->getPosition()->getY();

                    //Check if we are on the correct X.
                    if (xDifference > 0) {
                        if (iteration->getEcoSystem()->isValidMove(this, this->getPosition()->getX() - 1,
                                                                   this->getPosition()->getY())) {
                            this->getPosition()->setX(this->getPosition()->getX() - 1);
                            return true;
                        }
                    }

                    if (xDifference < 0) {
                        if (iteration->getEcoSystem()->isValidMove(this, this->getPosition()->getX() + 1,
                                                                   this->getPosition()->getY())) {
                            this->getPosition()->setX(this->getPosition()->getX() + 1);
                            return true;
                        }
                    }

                    //Otherwise, we are not on the correct Y.
                    if (yDifference > 0) {
                        if (iteration->getEcoSystem()->isValidMove(this, this->getPosition()->getX(),
                                                                   this->getPosition()->getY() - 1)) {
                            this->getPosition()->setY(this->getPosition()->getY() - 1);
                            return true;
                        }
                    }

                    if (yDifference < 0) {
                        if (iteration->getEcoSystem()->isValidMove(this, this->getPosition()->getX(),
                                                                   this->getPosition()->getY() + 1)) {
                            this->getPosition()->setY(this->getPosition()->getY() + 1);
                            return true;
                        }
                    }
                }
            }
        }
    }

    //MODE: Need to eat!
    if (this->getEnergy() != this->getMaxEnergy()) {
        //Target closest food source!

        shared_ptr<Organism> closestFood = nullptr;
        int closestDistance = 0;

        for (const shared_ptr<Organism> &organism: *iteration->getEcoSystem()->getOrganisms()) {

            //Check if organism is still alive (could be a dead plant).
            if (organism->getEnergy() > 0) {
                //Check if position contains preys.
                if (this->canEat(organism)) {

                    int distance = abs(organism->getPosition()->getX() - this->getPosition()->getX())
                                   + abs(organism->getPosition()->getY() - this->getPosition()->getY());

                    //Check if closest distance is not equal to default, or is better than our current closest.
                    if (distance < closestDistance || closestDistance == 0) {

                        closestFood = organism;
                        closestDistance = distance;
                    }
                }
            }
        }

        //We found some food!
        if (closestFood != nullptr) {

            //Found target, lets move towards it, based on current position.
            int xDifference = closestFood->getPosition()->getX() - this->getPosition()->getX();
            int yDifference = closestFood->getPosition()->getY() - this->getPosition()->getY();

            //Check if we are on the correct X.
            if (xDifference > 0) {
                //Move if it's valid, if not move onto another valid move.
                if (iteration->getEcoSystem()->isValidMove(this, this->getPosition()->getX() + 1,
                                                           this->getPosition()->getY())) {
                    this->getPosition()->setX(this->getPosition()->getX() + 1);
                    return true;
                }
            }

            if (xDifference < 0) {
                //Move if it's valid, if not move onto another valid move.
                if (iteration->getEcoSystem()->isValidMove(this, this->getPosition()->getX() - 1,
                                                           this->getPosition()->getY())) {
                    this->getPosition()->setX(this->getPosition()->getX() - 1);
                    return true;
                }
            }

            //Otherwise, we are not on the correct Y.
            if (yDifference > 0) {
                //Move if it's valid, if not move onto another valid move.
                if (iteration->getEcoSystem()->isValidMove(this, this->getPosition()->getX(),
                                                           this->getPosition()->getY() + 1)) {
                    this->getPosition()->setY(this->getPosition()->getY() + 1);
                    return true;
                }
            }

            if (yDifference < 0) {
                //Move if it's valid, if not move onto another valid move.
                if (iteration->getEcoSystem()->isValidMove(this, this->getPosition()->getX(),
                                                           this->getPosition()->getY() - 1)) {
                    this->getPosition()->setY(this->getPosition()->getY() - 1);
                    return true;
                }
            }
        }
    }

    //No valid move (obstacles/animals in the way).

    //Otherwise, nothing can be found, why move?
    return false;
}

bool Animal::grow(const shared_ptr<Iteration> &iteration) {
    return false;
}

bool Animal::consume(const shared_ptr<Iteration> &iteration) {

    //Iterate over all Organisms in the EcoSystem.
    for (const shared_ptr<Organism> &possiblePrey: *iteration->getEcoSystem()->getOrganisms()) {

        //Check if organism is still alive (could be a dead plant).
        if (possiblePrey->getEnergy() > 0) {

            //Make sure we can't eat our self.
            if (possiblePrey.get() != this) {

                //Check if we are on the same tile, so we can consume them.
                //We know if we are on the same tile, they must be our prey, since we just moved on top of them.
                if (possiblePrey->getPosition()->getX() == this->getPosition()->getX() &&
                    possiblePrey->getPosition()->getY() == this->getPosition()->getY()) {

                    //Check if we will stay under our maximum energy when consuming target.
                    if (this->getMaxEnergy() <= this->getMaxEnergy() + possiblePrey->getEnergy()) {
                        //Get the energy we could absorb.
                        int preyEnergy = possiblePrey->getEnergy();

                        //We can't surpass the killer's max energy.
                        if (preyEnergy > this->getMaxEnergy()) {
                            this->setEnergy(this->getMaxEnergy());
                        } else {
                            this->setEnergy(this->getEnergy() + preyEnergy);
                        }

                        //Kill prey.
                        possiblePrey->setEnergy(0);
                        return true;
                    }
                }
            }
        }
    }

    //An Animal has not been successfully consumed.
    return false;
}

bool Animal::reproduce(const shared_ptr<Iteration> &iteration) {
    list<shared_ptr<Organism>> adjacentOrganisms =
            iteration->getEcoSystem()->getNearbyOrganisms(make_shared<Animal>(*this), 1, 1);

    //Iterate through each possible attacker nearby.
    for (const shared_ptr<Organism> &possiblePartner: adjacentOrganisms) {
        // Check if organism is the same type of animal.
        if (this->getLetterID() == possiblePartner->getLetterID()) {

            auto *animalPartner = dynamic_cast<Animal *>(possiblePartner.get());

            // Check if we have the energy to mate.
            if (this->getEnergy() >= this->getMaxEnergy() / 2) {

                // Check if the target Animal has the energy to mate.
                if (animalPartner->getEnergy() >= animalPartner->getMaxEnergy() / 2) {

                    //Iterate through each nearby x, y position combination.

                    //Check if there's space around either of them to place the offspring.
                    for (int possibleX = min(animalPartner->getPosition()->getX(), this->getPosition()->getX()) - 1;
                         possibleX != max(animalPartner->getPosition()->getX(), this->getPosition()->getX()) + 1;
                         possibleX++) {

                        for (int possibleY =
                                min(animalPartner->getPosition()->getY(), this->getPosition()->getY()) - 1;
                             possibleY !=
                             max(animalPartner->getPosition()->getY(), this->getPosition()->getY()) + 1;
                             possibleY++) {


                            if (iteration->getEcoSystem()->isWithinMap(possibleX, possibleY)) {

                                //Check if there's open space.
                                if (iteration->getEcoSystem()->getMap()[possibleX][possibleY] == ' ') {

                                    //There's space!
                                    //We can reproduce!

                                    //Add animal to map.
                                    iteration->getEcoSystem()->updateTile(possiblePartner->getLetterID(), possibleX,
                                                                          possibleY);

                                    //Add new animal to organisms.
                                    iteration->getEcoSystem()->getOrganisms()->push_back(
                                            make_shared<Animal>(iteration->getEcoSystem()->getIDCounter() + 1,
                                                                this->getLetterID(),
                                                                possiblePartner->getType(),
                                                                make_shared<Position>(possibleX, possibleY),
                                                                possiblePartner->getFoodChain(),
                                                                possiblePartner->getEnergy(),
                                                                possiblePartner->getEnergy()));

                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // The animals found wasn't an appropriate partner.
    return false;
}