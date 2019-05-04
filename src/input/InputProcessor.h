#ifndef CS_3210_PROJECT_ASSIGNMENT_INPUTPROCESSOR_H
#define CS_3210_PROJECT_ASSIGNMENT_INPUTPROCESSOR_H

#include <string>
#include <list>
#include <memory>

#include <fstream>
#include <iostream>
#include <simulation/ecosystem/entity/type/EntityType.h>
#include <vector>

using namespace std;

class EcoSystem;

/**
 * Represents a Species.
 */
struct Species {

    //The EntityType.
    EntityType type;

    //The letter id.
    char letterID;

    //The characteristics of the Species.
    vector<int> characteristics;

    //The food chain of the Species.
    list<char> foodchain;

    //The species max energy.
    int maxEnergy;
};

/**
 * InputProcessor, represents the module used to interpret input files.
 */
class InputProcessor {

private:

    //The Map's input file name.
    string mapFileName;

    //The Species' input filename.
    string speciesFileName;

    //The possible tiles allowed in the Map.
    list<char> possibleTiles;

    //The Map's height.
    int mapHeight = 0;

    //The Map's width.
    int mapWidth = 0;

public:

    /**
     * Default constructor.
     */
    InputProcessor();

    /**
     * Constructs a new InputProcessor.
     *
     * @param possibleTiles - the Map's possible tile values.
     * @param mapFileName - the Map's input file name.
     * @param speciesFileName - the Species' input file name.
     */
    InputProcessor(list<char> possibleTiles, const string &mapFileName, const string &speciesFileName);

    /**
     * Reads the Map's input file.
     *
     * @return a two dimensional char pointer array containing read Map values.
     */
    char **readMap(const list<Species> &species);

    /**
     * Reads the Species' input file.
     *
     * @return a list of Species.
     */
    list<Species> readSpecies();

    /**
     * Saves the specified EcoSystem's map to file.
     *
     * @param ecoSystem - the specified EcoSystem.
     */
    void saveMap(EcoSystem ecoSystem);

    /**
     * Checks whether the given value is valid within the EcoSystem.
     *
     * @param species - a list of possible Species in the EcoSystem.
     * @param mapValue - the letter value.
     *
     * @return whether or not the given value is a registered Entity/Tile.
     */
    bool isValidMapValue(const list<Species> &species, const char &mapValue);

    /**
     * Calculates the File's width.
     *
     * @param fileName - the specified file name.
     *
     * @return the file's width.
     */
    int getFileWidth(const string &fileName);

    /**
     * Calculates the File's height.
     *
     * @param fileName - the specified file name.
     *
     * @return the file's height.
     */
    int getFileHeight(const string &fileName);

    /**
     * Calculates the Map's height.
     *
     * @return the map's height.
     */
    int getMapHeight();

    /**
     * Calculates the Map's width.
     *
     * @return the map's width.
     */
    int getMapWidth();
};


#endif //CS_3210_PROJECT_ASSIGNMENT_INPUTPROCESSOR_H
