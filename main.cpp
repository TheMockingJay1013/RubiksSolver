#include <iostream>
#include "RubiksCube3d.cpp"
#include "dfs.h"

int main() {
    RubiksCube3d CUBE ;

    CUBE.move(RubiksCube::MOVE(0));
    CUBE.move(RubiksCube3d::MOVE(3));
    CUBE.move(RubiksCube::MOVE(6));

    CUBE.print();



    cout << "Solving the cube using DFS" << endl;


//    CUBE.r();
//    CUBE.print();

    DFS<RubiksCube3d,int> dfs(CUBE,5);
    vector<RubiksCube3d::MOVE> path = dfs.solver();
    for(auto move:path)
    {
        CUBE.move(move);
        cout << (int)move << endl;
    }
    CUBE.print();

    if(path.empty()) cout << "NO MOVES\n";

}   
