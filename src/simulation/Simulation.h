#ifndef CS_3210_PROJECT_ASSIGNMENT_SIMULATION_H
#define CS_3210_PROJECT_ASSIGNMENT_SIMULATION_H

#include <input/InputProcessor.h>
#include <simulation/ecosystem/EcoSystem.h>

/**
 * Simulation, representing the encapsulating system, which can house many EcoSystems.
 */
class Simulation {

private:

    //The InputProcessor, responsible for interpreting text files.
    InputProcessor inputProcessor;

public:

    /**
     * Constructs a new Simulation.
     *
     * @param mapFileName - the Map's input file name.
     * @param speciesFileName the Specie's input file name.
     */
    Simulation(list<char> possibleTiles, const string &mapFileName, const string &speciesFileName);

    /**
     * Creates a new EcoSystem.
     *
     * @return the created EcoSystem.
     */
    EcoSystem createEcoSystem();

    /**
     * Gets the InputProcessor.
     *
     * @return the associated InputProcessor.
     */
    InputProcessor getInputProcesor();
};


#endif //CS_3210_PROJECT_ASSIGNMENT_SIMULATION_H
