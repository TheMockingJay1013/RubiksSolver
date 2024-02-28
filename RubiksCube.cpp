//
// Created by Navaneeth Shaji on 23/02/24.
//

#include "RubiksCube.h"

char RubiksCube::getColorLetter(RubiksCube::COLOR color) {
    switch (color) {
        case COLOR::WHITE :
            return 'W';
        case COLOR:: BLUE :
            return 'B';
        case COLOR::GREEN :
            return 'G';
        case COLOR::ORANGE :
            return 'O';
        case COLOR:: RED :
            return 'R';
        case COLOR::YELLOW :
            return 'Y';
    }
}

string RubiksCube::getMove(RubiksCube::MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UPRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::B2:
            return "B2";
    }

}

RubiksCube &RubiksCube::move(RubiksCube::MOVE ind) {
    switch (ind) {
        case MOVE::L :
            return this->l() ;
        case MOVE::LPRIME :
            return this->lprime();
        case MOVE::L2 :
            return this->l2() ;
        case MOVE::U :
            return this->u() ;
        case MOVE::UPRIME :
            return this->uprime() ;
        case MOVE::U2 :
            return this->u2();
        case MOVE::F :
            return this->f();
        case MOVE::FPRIME :
            return this->fprime();
        case MOVE::F2 :
            return this->f2() ;
        case MOVE::R :
            return this->r() ;
        case MOVE::RPRIME :
            return this->rprime();
        case MOVE::R2 :
            return this->r2() ;
        case MOVE::D :
            return this->d();
        case MOVE::DPRIME :
            return this->dprime() ;
        case MOVE::D2 :
            return this->d2();
        case MOVE::B :
            return this->b();
        case MOVE::BPRIME :
            return this->bprime() ;
        case MOVE::B2 :
            return this->b2();
    }
}

RubiksCube &RubiksCube::invert(RubiksCube::MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->lprime();
        case MOVE::LPRIME:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rprime();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uprime();
        case MOVE::UPRIME:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dprime();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fprime();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bprime();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();
    }
}

void RubiksCube::print() const {
    cout << "Rubiks Cube layout : \n";
    for(int i=0;i<3;i++)
    {
        cout << "       ";
        for(int j=0;j<3;j++)
        {
            cout << getColorLetter(getColor(FACE::UP,i,j)) << " " ;
        }
        cout << endl;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << getColorLetter(getColor(FACE::LEFT,i,j)) << " ";
        }
        cout << " ";
        for(int j=0;j<3;j++)
        {
            cout << getColorLetter(getColor(FACE::FRONT,i,j)) << " ";
        }
        cout << " ";
        for(int j=0;j<3;j++)
        {
            cout << getColorLetter(getColor(FACE::RIGHT,i,j)) << " ";
        }
        cout << " ";
        for(int j=0;j<3;j++)
        {
            cout << getColorLetter(getColor(FACE::BACK,i,j)) << " ";
        }
        cout << endl;
    }
    for(int i=0;i<3;i++)
    {
        cout << "       ";
        for(int j=0;j<3;j++)
        {
            cout << getColorLetter(getColor(FACE::DOWN,i,j)) << " " ;
        }
        cout << endl;
    }

}

vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int times) {
    vector<RubiksCube::MOVE> moves ;
    srand(time(0));
    for(unsigned int i =0 ;i<times;i++)
    {
        unsigned int m = rand()%18 ;
        moves.push_back(static_cast<RubiksCube::MOVE>(m));
        this->move(static_cast<RubiksCube::MOVE>(m));
    }
    return moves;
}

