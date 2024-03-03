#include <iostream>
#include "RubiksCube3d.cpp"
#include "dfs.h"
#include "bfs.h"
#include "IDDFS.h"

int main() {
    RubiksCube3d CUBE ;

    vector<RubiksCube::MOVE> moves = CUBE.randomShuffleCube(7);
    CUBE.print();




    cout << "Solving the cube using IDDFS" << endl;


//    CUBE.r();
//    CUBE.print();


    // BFS SOLVER
//    BFS<RubiksCube3d,Hash3d> bfs(CUBE);
//    vector<RubiksCube3d::MOVE> path =  bfs.solver();

    //IDDFS SOLVER
    IDDFS<RubiksCube3d,Hash3d> iddfs(CUBE,7);
    vector<RubiksCube3d::MOVE> path = iddfs.solver();


    for(auto move:path)
    {
        CUBE.move(move);
        cout << CUBE.getMove(move) << endl;
    }
    CUBE.print();

    if(path.empty()) cout << "NO MOVES\n";

}   
