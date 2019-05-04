#include <utility>

#include <algorithm>
#include <sstream>
#include <boost/format.hpp>
#include <regex>
#include <simulation/ecosystem/EcoSystem.h>

#include "InputProcessor.h"

InputProcessor::InputProcessor() = default;

InputProcessor::InputProcessor(list<char> possibleTiles, const string &mapFileName,
                               const string &speciesFileName) {

    this->possibleTiles = std::move(possibleTiles);
    this->mapFileName = mapFileName;
    this->speciesFileName = speciesFileName;
}

char **InputProcessor::readMap(list<Species> *species) {
    //Calculate the Map's dimensions.
    this->mapWidth = getFileWidth(this->mapFileName);
    this->mapHeight = getFileHeight(this->mapFileName);

    //Allocate memory to read map.
    char **map = new char *[mapHeight];
    ifstream inputFile(this->mapFileName);

    //Check if the input file can be read.
    if (inputFile.good()) {

        int currentX = 0;

        //Iterate through each line in the file.
        for (string line; getline(inputFile, line);) {

            //Allocate enough memory for a new row.
            map[currentX] = new char[mapWidth];

            int currentY = 0;

            //Iterate through each character/tile in mp.
            for (char character: line) {

                //Check if a new line isn't present.
                if (character != '\n') {
                    if (isValidMapValue(species, character)) {
                        map[currentX][currentY] = character;

                        //Continue to process the next tile in the row.
                        currentY = currentY + 1;
                    } else {
                        throw runtime_error(
                                boost::str(boost::format("Unexpected Map Value: %c at X: %d Y: %d.") % character %
                                           currentX %
                                           currentY));
                    }
                }
            }

            //Pad the end of the line values with open spaces.
            while (currentY < mapWidth) {
                map[currentX][currentY] = ' ';

                currentY = currentY + 1;
            }

            //Move onto the next line.
            currentX = currentX + 1;
        }
    } else {
        throw runtime_error("Cannot find valid map file using: " + mapFileName);
    }

    //Return the generated map.
    return map;
}

list<Species> InputProcessor::readSpecies() {
    list<Species> species;

    ifstream inputFile(this->speciesFileName);

    if (inputFile.good()) {

        //Iterate over each line in the Species' input file.
        for (string line; getline(inputFile, line);) {

            string type;

            stringstream lineStream(line);
            getline(lineStream, type, ' ');

            //Check if it's a valid EntityType.
            // Interpret for a plant species type.
            if (type == "plant") {

                //Check if the input arguments are formatted correctly.
                if (!regex_match(line, regex(R"([\S]+\s[a-zA-Z]+\s\d+\s\d+)"))) {
                    throw runtime_error(
                            boost::str(boost::format("Invalid argument format for Specie: %s") % line));
                }

                Species plant = Species();

                char letterID;
                int regrowthCoefficient;
                int energyPoints;

                // Read the values using the operator >>
                lineStream >> letterID >> regrowthCoefficient >> energyPoints;

                plant.type = EntityType::PLANT;
                plant.letterID = letterID;

                plant.characteristics.push_back(regrowthCoefficient);
                plant.characteristics.push_back(energyPoints);

                //Add plant to species list.
                species.push_back(plant);
            } else if (type == "herbivore" || type == "omnivore") {

                //Check if the input arguments are formatted correctly.
                if (!regex_match(line, regex(R"([\S]+\s[a-zA-Z]+\s[\[](\S(([,]\s)|[\]]))+\s\d+)"))) {
                    throw runtime_error(
                            boost::str(boost::format("Invalid argument format for Specie: %s") % line));
                }

                //Interpret for both animal species.
                Species animal = Species();

                char letterID;

                // Store the letter representation.
                lineStream >> letterID;

                //Remove all spaces from list, so we can separate by comma.
                line.erase(remove(line.begin(), line.end(),
                                  ' '), line.end());

                //Get the index of the initialize of list.
                int startIndex = line.find_first_of('[');
                //Get the index of the end of list.
                int endIndex = line.find_first_of(']');

                //Get values between brackets.
                string foodchainValues = line.substr(startIndex + 1, (endIndex - startIndex) - 1);

                //Add all values to the Animal's foodchain.
                stringstream stream(foodchainValues);
                for (string value; getline(stream, value, ',');) {
                    animal.foodchain.push_back(value[0]);
                }

                //Store Animal Type.
                if (type == "herbivore") {
                    animal.type = EntityType::HERBIVORE;
                } else if (type == "omnivore") {
                    animal.type = EntityType::OMNIVORE;
                }

                //Store Animal representation.
                animal.letterID = letterID;

                //Get max energy value, by getting the substring of after the end of list, to the end of the line.
                animal.maxEnergy = atoi(line.substr(endIndex + 1, line.length()).c_str());

                //Add animal to species list.
                species.push_back(animal);
            } else {
                throw runtime_error(
                        boost::str(boost::format("Invalid Specie Type: %s") % type));
            }
        }

        inputFile.close();
    } else {
        throw runtime_error("Cannot find valid species file using: " + speciesFileName);
    }

    return species;
}

void InputProcessor::saveMap(EcoSystem ecoSystem) {
    ofstream mapFile(this->mapFileName);

    if (mapFile.good()) {
        for (int x = 0; x < this->mapHeight; x++) {
            for (int y = 0; y < this->mapWidth; y++) {
                mapFile << ecoSystem.getMap()[x][y];
            }
            mapFile << endl;
        }
    }

    mapFile.close();
}

bool InputProcessor::isValidMapValue(list<Species> *species, const char &mapValue) {

    //Check if it is a possible map tile.
    if (mapValue == ' ' || mapValue == '#' || mapValue == '~') {
        return true;
    }

    //Check if it is a possible Species.
    for (Species specie: *species) {

        if (specie.letterID == mapValue) {
            return true;
        }
    }

    return false;
}

int InputProcessor::getFileWidth(const string &fileName) {
    ifstream inputFile(fileName);

    int highestX = 0;

    if (inputFile.good()) {
        string currentLine;

        int currentX = 0;
        while (getline(inputFile, currentLine)) {

            currentX = currentLine.length();

            if (currentX > highestX) {
                highestX = currentX;
            }
        }
    } else {
        throw runtime_error("Cannot find valid file using: " + fileName);
    }

    inputFile.close();

    return highestX;
}

int InputProcessor::getFileHeight(const string &fileName) {
    ifstream inputFile(fileName);

    int fileY = 0;

    if (inputFile.good()) {
        string currentLine;

        while (getline(inputFile, currentLine)) {
            fileY = fileY + 1;
        }
    } else {
        throw runtime_error("Cannot find valid file using: " + fileName);
    }

    inputFile.close();

    return fileY;
}

int InputProcessor::getMapHeight() {
    return this->mapHeight;
}

int InputProcessor::getMapWidth() {
    return this->mapWidth;
}
