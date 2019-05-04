#ifndef CS_3210_PROJECT_ASSIGNMENT_ITERATION_H
#define CS_3210_PROJECT_ASSIGNMENT_ITERATION_H

class EcoSystem;

/**
 * Iteration, representing the single 'iteration' simulation of a EcoSystem.
 */
class Iteration {

    //The owning EcoSystem.
    EcoSystem *ecosystem;

public:

    /**
     * Constructs a new Iteration.
     *
     * @param ecosystem - the owning EcoSystem.
     */
    Iteration(EcoSystem *ecosystem);

    /**
     * Runs this iteration.
     */
    void run();

    /**
     * Gets the owning EcoSystem.
     *
     * @return the owning EcoSystem.
     */
    EcoSystem *getEcoSystem();

};


#endif //CS_3210_PROJECT_ASSIGNMENT_ITERATION_H
