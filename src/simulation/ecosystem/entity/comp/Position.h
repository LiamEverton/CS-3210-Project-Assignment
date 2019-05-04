#ifndef CS_3210_PROJECT_ASSIGNMENT_POSITION_H
#define CS_3210_PROJECT_ASSIGNMENT_POSITION_H

/**
 * Position, represents an X, Y mapping that can be changed through mutators.
 */
class Position {

private:
    //The x and y values of the Position.
    int x, y;

public:
    /**
     * Constructs a new Position, with the default values of x = 0, y = 0 ;
     */
    Position();

    /**
     * Constructs a new Position using the given values.
     *
     * @param x - the X value.
     * @param y - the Y value.
     */
    Position(int x, int y);

    /**
     * Sets the X value to the specified value.
     *
     * @param x - the specified x value.
     */
    void setX(int x);

    /**
     * Sets the Y value to the specified value.
     *
     * @param y - the specified y value.
     */
    void setY(int y);

    /**
     * Gets the X value for this Position.
     *
     * @return the current X value.
     */
    int getX();


    /**
     * Gets the Y value for this Position.
     *
     * @return the current Y value.
     */
    int getY();
};

#endif //CS_3210_PROJECT_ASSIGNMENT_POSITION_H
