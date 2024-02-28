//
// Created by Navaneeth Shaji on 23/02/24.
//

#ifndef RUBIKSSOLVER_RUBIKSCUBE_H
#define RUBIKSSOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"
using namespace std;


class RubiksCube {
public :
    enum class FACE{
    UP,
    LEFT,
    FRONT,
    RIGHT,
    BACK,
    DOWN
    };

    enum class COLOR{
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE{
        L,LPRIME,L2,
        R,RPRIME,R2,
        U,UPRIME,U2,
        D,DPRIME,D2,
        F,FPRIME,F2,
        B,BPRIME,B2
        };

    // function to get color of the cell at the ith row and jth column in face
    // row and columns numbers are 0indexed
    virtual COLOR getColor(FACE face,int row ,int col) const = 0;

    // function to get first letter of a color
    static char getColorLetter(COLOR color) ;

    virtual bool isSolved() const = 0 ;

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
     * rx -> row numbering
     * cx -> column numbering
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
    void print() const ;

    // function to shuffle the cube using a fixed number of moves and returns the moves performed to shuffle the cube
    vector<MOVE> randomShuffleCube(unsigned int times) ;

    // function to perform moves on the cube
    RubiksCube &move(MOVE ind);

    // invert a move
    RubiksCube &invert(MOVE ind);

    // rotational moves on the cube

    virtual RubiksCube &f() = 0 ;
    virtual RubiksCube &fprime() = 0 ;
    virtual RubiksCube &f2() = 0 ;
    virtual RubiksCube &u() = 0 ;
    virtual RubiksCube &uprime() = 0 ;
    virtual RubiksCube &u2() = 0 ;
    virtual RubiksCube &l() = 0 ;
    virtual RubiksCube &lprime() = 0 ;
    virtual RubiksCube &l2() = 0 ;
    virtual RubiksCube &r() = 0 ;
    virtual RubiksCube &rprime() = 0 ;
    virtual RubiksCube &r2() = 0 ;
    virtual RubiksCube &d() = 0 ;
    virtual RubiksCube &dprime() = 0 ;
    virtual RubiksCube &d2() = 0 ;
    virtual RubiksCube &b() = 0 ;
    virtual RubiksCube &bprime() = 0 ;
    virtual RubiksCube &b2() = 0 ;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;

};


#endif //RUBIKSSOLVER_RUBIKSCUBE_H
