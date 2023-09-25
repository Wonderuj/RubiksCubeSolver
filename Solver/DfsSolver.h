//
// Created by Uddhav on 24-09-2023.
//
#include<bits/stdc++.h>
#include "../Model/GenericRubiksCube.h"

#ifndef RUBIKS_DFSSOLVER_H
#define RUBIKS_DFSSOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class DFSSolver {
private:

    vector<RubiksCube::MOVE> moves;
    int max_search_depth;


//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        //if the cube is solved of not : BASE CASE
        if (rubiksCube.isSolved()) return true;

        //Pruning: If the depth is reached
        if (dep > max_search_depth) return false;

        //18 different operations of moves (l,l',l2, u....)
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {   //default max search depth is 8
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    //this solve function returns series of moves to be performed to solve the cube
    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};

#endif //RUBIKS_DFSSOLVER_H
