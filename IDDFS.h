//
// Created by Navaneeth Shaji on 02/03/24.
//

#ifndef RUBIKSSOLVER_IDDFS_H
#define RUBIKSSOLVER_IDDFS_H
#include "dfs.h"

template<typename T,typename H>
class IDDFS{
private:
    vector<RubiksCube::MOVE > moves ;

public:
    T CUBE ;
    int max_depth ;

    IDDFS(T _cube,int _depth)
    {
        CUBE = _cube;
        max_depth = _depth;

    }

    vector<RubiksCube::MOVE> solver(){
        for(int limit = 0;limit <=max_depth;limit++)
        {
            DFS<T,H> dfs(CUBE,limit);
            moves = dfs.solver();

            if(dfs.cube.isSolved())
            {
                CUBE = dfs.cube;
                return moves;
            }
        }
    }


};

#endif //RUBIKSSOLVER_IDDFS_H
