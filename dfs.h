//
// Created by Navaneeth Shaji on 27/02/24.
//

#ifndef RUBIKSSOLVER_DFS_H
#define RUBIKSSOLVER_DFS_H

#include "RubiksCube.h"

template<typename T,typename H>
class DFS{
private:
    vector<RubiksCube::MOVE> path ;
    int max_depth ;

    int dfs(int depth)
    {
        if(cube.isSolved())return 1 ;
        if(depth>max_depth)return 0 ;

        for(int i=0;i<18;i++)
        {
            cube.move(RubiksCube::MOVE(i));
            path.push_back(RubiksCube::MOVE(i));
            if(dfs(depth+1))return 1;
            path.pop_back();
            cube.invert(RubiksCube::MOVE(i));
        }
        return 0 ;
    }
public :
    T cube ;

    DFS(T _cube,int _max_depth)
    {
        cube = _cube;
        max_depth = _max_depth;
        path.clear();
    }

    vector<RubiksCube::MOVE> solver()
    {
        dfs(1);
        return path ;

    }

};

#endif //RUBIKSSOLVER_DFS_H
