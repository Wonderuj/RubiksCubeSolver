//
// Created by HP on 24-09-2023.
//

#ifndef RUBIKS_GENERICRUBIKSCUBE_H
#define RUBIKS_GENERICRUBIKSCUBE_H

#include "bits/stdc++.h"
using namespace std;

/*
 * A base class for all Rubik's Cube Model. There are various representation for Rubik's Cube.
 * Each one has it's own special ways of definitions. This class provides a shared functionality
 * between all models.
 * We'll benchmark all models and observe which one is better for performance.
 */

class RubiksCube {
public:

    //enums as option set for Face, color and moves.

    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {  //18 moves are set..
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    /* getColor function:
     * Returns the color of the cell at (row, col) in face.
     * The rows and columns are 0-indexed. (represented below)
     * @param Face, row, and column index
     */
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;


    /* getColorLetter:
     * Returns the first letter of the given COLOR
     * Eg: For COLOR::GREEN, it returns 'G'
     */
    static char getColorLetter(COLOR color);

    /*
      Returns true if the Rubik's Cube is solved, otherwise returns false.
     */
    virtual bool isSolved() const = 0;


    /*
     * Returns the move in the string format.
     */
    static string getMove(MOVE ind);



    /*
     * Print the Rubik Cube in Planar format.
     *
     * The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *
     * Row and Column Numberings:
     *
     * rx -> row numbering (top to bottom)
     * cx -> column numbering (left to right)
     * bx -> both row and column numbering
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
     *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
     *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     */
    void print() const;

    /*
     * Randomly shuffle the cube with 'times' moves and returns the moves performed.
     */
    vector<MOVE> randomShuffleCube(unsigned int times);

    /*
     * Perform moves on the Rubik Cube
     */
    RubiksCube &move(MOVE ind);

    /*
     * Invert a move
     */
    RubiksCube &invert(MOVE ind);

    /*
     * Rotational Moves on the Rubik Cubes
     *
     * F, F’, F2,
     * U, U’, U2,
     * L, L’, L2,
     * D, D’, D2,
     * R, R’, R2,
     * B, B’, B2
     */

    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;

    /*
     * Corner Notation Functions:
     * getCornerColorString: Get the color string for a corner piece.
     * getCornerIndex: Get the index of a corner piece.
     * getCornerOrientation: Get the orientation of a corner piece.
     */

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;
    /* Return these values accordingly
     * 0 -> WRB
     * 1 -> WRG
     * 2 -> WOB
     * 3 -> WOG
     *
     * 4 -> YRB
     * 5 -> YRG
     * 6 -> YOB
     * 7 -> YOG
     */

    uint8_t getCornerOrientation(uint8_t ind) const;
};



#endif //RUBIKS_GENERICRUBIKSCUBE_H
