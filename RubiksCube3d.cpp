//
// Created by Navaneeth Shaji on 26/02/24.
//

#include "RubiksCube.h"

class RubiksCube3d : public RubiksCube {
public:
    char cube[6][3][3] ;

    RubiksCube3d(){
        // make a solved cube initially

        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    bool isSolved() const override{
        // checking
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(cube[i][j][k] != getColorLetter(COLOR(i))) return false;
                }
            }
        }
        return true;
    }

    COLOR getColor(FACE face,int row ,int col) const override{
        COLOR f ;
        switch (cube[(int)face][row][col]) {
            case 'W' :
                return  COLOR::WHITE;
            case 'Y' :
                return  COLOR::YELLOW ;
            case 'G':
                return COLOR:: GREEN;
            case 'B' :
                return  COLOR::BLUE;
            case 'R' :
                return COLOR::RED;
            case 'O' :
                return  COLOR::ORANGE;
        }
    }

    RubiksCube &l() override{
        char temp[3] ;
        temp[0] = cube[1][0][0] ;
        temp[1] = cube[1][1][0] ;

        cube[1][0][0] = cube[1][2][0] ;
        cube[1][2][0] = cube[1][2][2] ;
        cube[1][2][2] = cube[1][0][2] ;
        cube[1][0][2] = temp[0] ;

        cube[1][1][0] = cube[1][2][1] ;
        cube[1][2][1] = cube[1][1][2] ;
        cube[1][1][2] = cube[1][0][1] ;
        cube[1][0][1] = temp[1] ;

        temp[0] = cube[0][0][0] ;
        temp[1] = cube[0][1][0] ;
        temp[2] = cube[0][2][0] ;

        cube[0][0][0] = cube[4][2][2] ;
        cube[4][2][2] = cube[5][0][0] ;
        cube[5][0][0] = cube[2][0][0] ;
        cube[2][0][0] = temp[0] ;

        cube[0][1][0] = cube[4][1][2] ;
        cube[4][1][2] = cube[5][1][0] ;
        cube[5][1][0] = cube[2][1][0] ;
        cube[2][1][0] = temp[1] ;

        cube[0][2][0] = cube[4][0][2] ;
        cube[4][0][2] = cube[5][2][0] ;
        cube[5][2][0] = cube[2][2][0] ;
        cube[2][2][0] = temp[2] ;

        return *this;
    }

    RubiksCube &lprime() override{
        this->l();
        this->l();
        this->l();
        return *this;
    }

    RubiksCube &l2() override{
        this->l();
        this->l();
        return *this;
    }

    RubiksCube &u() override{
        char temp[3] ;
        temp[0] = cube[0][0][0] ;
        temp[1] = cube[0][0][1] ;

        cube[0][0][0] = cube[0][2][0] ;
        cube[0][2][0] = cube[0][2][2] ;
        cube[0][2][2] = cube[0][0][2] ;
        cube[0][0][2] = temp[0] ;

        cube[0][0][1] = cube[0][1][0] ;
        cube[0][1][0] = cube[0][2][1] ;
        cube[0][2][1] = cube[0][1][2] ;
        cube[0][1][2] = temp[1];

        temp[0] = cube[1][0][0];
        temp[1] = cube[1][0][1];
        temp[2] = cube[1][0][2];

        cube[1][0][0] = cube[2][0][0] ;
        cube[2][0][0] = cube[3][0][0] ;
        cube[3][0][0] = cube[4][0][0] ;
        cube[4][0][0] = temp[0] ;

        cube[1][0][1] = cube[2][0][1] ;
        cube[2][0][1] = cube[3][0][1] ;
        cube[3][0][1] = cube[4][0][1] ;
        cube[4][0][1] = temp[1] ;

        cube[1][0][2] = cube[2][0][2] ;
        cube[2][0][2] = cube[3][0][2] ;
        cube[3][0][2] = cube[4][0][2] ;
        cube[4][0][2] = temp[2] ;
        return *this;
    }

    RubiksCube &uprime() override{
        this->u();
        this->u();
        this->u();
        return *this;
    }

    RubiksCube &u2() override{
        this->u();
        this->u();
        return *this;
    }

    RubiksCube &f() override{
        char temp[3] ;

        temp[0] = cube[2][0][0] ;
        temp[1] = cube[2][0][1] ;

        cube[2][0][0] = cube[2][2][0] ;
        cube[2][2][0] = cube[2][2][2] ;
        cube[2][2][2] = cube[2][0][2] ;
        cube[2][0][2] = temp[0] ;

        cube[2][0][1] = cube[2][1][0] ;
        cube[2][1][0] = cube[2][2][1] ;
        cube[2][2][1] = cube[2][1][2] ;
        cube[2][1][2] = temp[1] ;

        temp[0] = cube[0][2][0];
        temp[1] = cube[0][2][1];
        temp[2] = cube[0][2][2];

        cube[0][2][0] = cube[1][2][2] ;
        cube[1][2][2] = cube[5][0][2] ;
        cube[5][0][2] = cube[3][0][0] ;
        cube[3][0][0] = temp[0] ;

        cube[0][2][1] = cube[1][1][2] ;
        cube[1][1][2] = cube[5][0][1] ;
        cube[5][0][1] = cube[3][1][0] ;
        cube[3][1][0] = temp[1] ;

        cube[0][2][2] = cube[1][0][2] ;
        cube[1][0][2] = cube[5][0][0] ;
        cube[5][0][0] = cube[3][2][0] ;
        cube[3][2][0] = temp[2] ;

        return *this;
    }

    RubiksCube &fprime() override{
        this->f();
        this->f();
        this->f();
        return *this;
    }

    RubiksCube &f2() override{
        this->f();
        this->f();
        return *this;
    }

    RubiksCube &r() override{
        char temp[3] ;

        temp[0] = cube[3][0][0] ;
        temp[1] = cube[3][1][0] ;

        cube[3][0][0] = cube[3][2][0] ;
        cube[3][2][0] = cube[3][2][2] ;
        cube[3][2][2] = cube[3][0][2] ;
        cube[3][0][2] = temp[0] ;

        cube[3][1][0] = cube[3][2][1] ;
        cube[3][2][1] = cube[3][1][2] ;
        cube[3][1][2] = cube[3][0][1] ;
        cube[3][0][1] = temp[1] ;

        temp[0] = cube[2][0][2] ;
        temp[1] = cube[2][1][2] ;
        temp[2] = cube[2][2][2] ;

        cube[2][0][2] = cube[5][0][2] ;
        cube[5][0][2] = cube[4][2][0] ;
        cube[4][2][0] = cube[0][0][2] ;
        cube[0][0][2] = temp[0] ;

        cube[2][1][2] = cube[5][1][2] ;
        cube[5][1][2] = cube[4][1][0] ;
        cube[4][1][0] = cube[0][1][2] ;
        cube[0][1][2] = temp[1] ;

        cube[2][2][2] = cube[5][2][2] ;
        cube[5][2][2] = cube[4][0][0] ;
        cube[4][0][0] = cube[0][2][2] ;
        cube[0][2][2] = temp[2] ;

        return *this;
    }

    RubiksCube &rprime() override{
        this->r();
        this->r();
        this->r();
        return *this;
    }

    RubiksCube &r2() override{
        this->r();
        this->r();
        return *this;
    }

    RubiksCube &b() override{
        char temp[3] ;

        temp[0] = cube[4][0][0] ;
        temp[1] = cube[4][1][0] ;

        cube[4][0][0] = cube[4][2][0] ;
        cube[4][2][0] = cube[4][2][2] ;
        cube[4][2][2] = cube[4][0][2] ;
        cube[4][0][2] = temp[0] ;

        cube[4][1][0] = cube[4][2][1] ;
        cube[4][2][1] = cube[4][1][2] ;
        cube[4][1][2] = cube[4][0][1] ;
        cube[4][0][1] = temp[1] ;

        temp[0] = cube[3][0][2] ;
        temp[1] = cube[3][1][2] ;
        temp[2] = cube[3][2][2] ;

        cube[3][0][2] = cube[5][2][2] ;
        cube[5][2][2] = cube[1][2][0] ;
        cube[1][2][0] = cube[0][0][0] ;
        cube[0][0][0] = temp[0] ;

        cube[3][1][2] = cube[5][2][1] ;
        cube[5][2][1] = cube[1][1][0] ;
        cube[1][1][0] = cube[0][0][1] ;
        cube[0][0][1] = temp[1] ;

        cube[3][2][2] = cube[5][2][0] ;
        cube[5][2][0] = cube[1][0][0] ;
        cube[1][0][0] = cube[0][0][2] ;
        cube[0][0][2] = temp[2] ;

        return *this;
    }

    RubiksCube &bprime() override{
        this->b();
        this->b();
        this->b();
        return *this;
    }

    RubiksCube &b2() override{
        this->b();
        this->b();
        return *this;
    }

    RubiksCube &d() override{
        char temp[3] ;

        temp[0] = cube[5][0][0] ;
        temp[1] = cube[5][0][1] ;

        cube[5][0][0] = cube[5][2][0] ;
        cube[5][2][0] = cube[5][2][2] ;
        cube[5][2][2] = cube[5][0][2] ;
        cube[5][0][2] = temp[0] ;

        cube[5][0][1] = cube[5][1][0] ;
        cube[5][1][0] = cube[5][2][1] ;
        cube[5][2][1] = cube[5][1][2] ;
        cube[5][1][2] = temp[1] ;

        temp[0] = cube[2][2][0] ;
        temp[1] = cube[2][2][1] ;
        temp[2] = cube[2][2][2] ;


        cube[2][2][0] = cube[1][2][0] ;
        cube[1][2][0] = cube[4][2][0] ;
        cube[4][2][0] = cube[3][2][0] ;
        cube[3][2][0] = temp[0] ;

        cube[2][2][1] = cube[1][2][1] ;
        cube[1][2][1] = cube[4][2][1] ;
        cube[4][2][1] = cube[3][2][1] ;
        cube[3][2][1] = temp[1] ;

        cube[2][2][2] = cube[1][2][2] ;
        cube[1][2][2] = cube[4][2][2] ;
        cube[4][2][2] = cube[3][2][2] ;
        cube[3][2][2] = temp[2] ;

        return *this;


    }

    RubiksCube &dprime() override{
        this->d();
        this->d();
        this->d();
        return *this;
    }

    RubiksCube &d2() override{
        this->d();
        this->d();
        return *this;
    }

    bool operator==(const RubiksCube3d &r1)const {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(r1.cube[i][j][k]!=cube[i][j][k])return false;
                }
            }
        }
        return true;
    }

    RubiksCube3d &operator=(const RubiksCube3d &r1) {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }

        return *this;
    }
};

struct hash3d {

};