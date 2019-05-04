#include <boost/lexical_cast.hpp>

#include <input/InputProcessor.h>
#include <simulation/Simulation.h>

/**
 * The entry point to utilize the system.
 */
int main() {

    //Declare which characters are valid tiles.
    list<char> tiles;

    tiles.push_back(' ');
    tiles.push_back('#');
    tiles.push_back('~');

    //Get Inputs.
    string speciesFile;
    cout << "Please specify the Species input file." << endl;
    getline(cin, speciesFile);

    string mapFile;
    cout << "Please specify the Map input file." << endl;
    getline(cin, mapFile);

    //Initialize a Simulation by specifying the input files.
    Simulation simulation = Simulation(tiles,
                                       mapFile,
                                       speciesFile);

    try {
        EcoSystem ecoSystem = simulation.createEcoSystem();

        //Print initial state.
        ecoSystem.printState();

        bool hasRanIterations = false;

        bool isSimulating = true;
        while (isSimulating) {

            bool validInput = false;
            while (!validInput) {
                try {
                    cout << "Specify how many iterations would you like to run?" << endl;
                    cout << "Alternatively, typing 'exit' to exit the simulation. " << endl;

                    //Get valid numeric input.
                    string option;
                    getline(cin, option);

                    if (option == "exit") {
                        isSimulating = false;
                        validInput = true;
                    } else {

                        int iterations = boost::lexical_cast<int>(option);

                        //Run the iterations.
                        ecoSystem.run(iterations);

                        hasRanIterations = true;

                        //Print State.
                        ecoSystem.printState();

                        validInput = true;
                    }
                } catch (boost::bad_lexical_cast &) {
                    cout << "Please provide a valid number of iterations." << endl;
                }
            }
        }

        if (hasRanIterations) {
            cout << "Would you like to save? (y/n)" << endl;

            //Get input.
            string option;
            getline(cin, option);

            if (option == "y") {
                simulation.getInputProcesor().saveMap(ecoSystem);
            }
        }

    } catch (runtime_error &error) {
        cout << "Error: " << error.what() << endl;
    }

    return 0;
}