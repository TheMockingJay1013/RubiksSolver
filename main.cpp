#include <iostream>
#include "RubiksCube3d.cpp"
#include "dfs.h"
#include "bfs.h"

int main() {
    RubiksCube3d CUBE ;

    vector<RubiksCube::MOVE> moves = CUBE.randomShuffleCube(7);
    CUBE.print();



    cout << "Solving the cube using DFS" << endl;


//    CUBE.r();
//    CUBE.print();

    BFS<RubiksCube3d,Hash3d> bfs(CUBE);
    vector<RubiksCube3d::MOVE> path =  bfs.solver();
    for(auto move:path)
    {
        CUBE.move(move);
        cout << CUBE.getMove(move) << endl;
    }
    CUBE.print();

    if(path.empty()) cout << "NO MOVES\n";

}   
