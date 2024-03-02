//
// Created by Navaneeth Shaji on 29/02/24.
//

#ifndef RUBIKSSOLVER_BFS_H
#define RUBIKSSOLVER_BFS_H
#include "RubiksCube.h"

template<typename T,typename H>
class BFS{
private:
    vector<RubiksCube::MOVE> moves ;
    unordered_map<T,int,H> vis ;
    unordered_map<T,RubiksCube::MOVE,H> mov_to_get_here ;

    T bfs()
    {
        queue<T> q;
        vis[CUBE] = 1 ;
        q.push(CUBE);

        while(!q.empty())
        {
            T x = q.front();
            q.pop();

            if(x.isSolved())return x;

            for(int i=0;i<18;i++)
            {
                auto move = RubiksCube::MOVE(i);
                x.move(move);
                if(!vis[x])
                {
                    vis[x] = 1;
                    q.push(x);
                    mov_to_get_here[x]=move;
                }
                x.invert(move);
            }
        }
        return CUBE ;

    }

public:
    T CUBE ;

    BFS(T cube)
    {
        CUBE = cube;
    }

    vector<RubiksCube::MOVE> solver()
    {
        T solved = this->bfs();
        while(!(solved == CUBE))
        {
            moves.push_back(mov_to_get_here[solved]);
            solved.invert(mov_to_get_here[solved]);
        }
        reverse(moves.begin(),moves.end());
        return moves;
    }


};

#endif //RUBIKSSOLVER_BFS_H
