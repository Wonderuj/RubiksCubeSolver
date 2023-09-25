#include <iostream>
#include "Model/RubiksCube3d.cpp"
//#include "Model/RubiksCube1D.cpp"
//#include "Model/RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "Pattern Databases/CornerPatternDatabase.h"
#include "Pattern Databases/CornerDBMaker.h"


int main() {

//    --------------------------- 3D Cube testing-----------------------
//    RubiksCube3d obj3dArray;


//    obj3dArray.print();
//    if(obj3dArray.isSolved()) cout<<"Solved\n";
//    else cout<<"Not solved\n";

//
//    vector<RubiksCube3d::MOVE>moveShufflelist= obj3dArray.randomShuffleCube(3);
//    for(auto x:moveShufflelist) cout<< obj3dArray.getMove(x)<<" ";
//    cout<<'\n';
//
//    obj3dArray.print();
//    if(obj3dArray.isSolved()) cout<<"Solved\n";
//    else cout<<"Not solved\n";

//    obj3dArray.l();
//    if(obj3dArray.isSolved()) cout<<"Solved\n";
//    else cout<<"Not solved\n";
//    obj3dArray.print();

//    obj3dArray.lPrime();
//    if(obj3dArray.isSolved()) cout<<"Solved\n";
//    else cout<<"Not solved\n";
//    obj3dArray.print();


//------------------ 1D cube testing---------------------

//    RubiksCube1d obj3dArray;
//        obj3dArray.print();
//    if(obj3dArray.isSolved()) cout<<"Solved\n";
//    else cout<<"Not solved\n";
//
//    vector<RubiksCube1d::MOVE>moveShufflelist= obj3dArray.randomShuffleCube(5);
//    for(auto x:moveShufflelist) cout<< obj3dArray.getMove(x)<<" ";
//    cout<<'\n';
//
//    obj3dArray.print();
//    if(obj3dArray.isSolved()) cout<<"Solved\n";
//    else cout<<"Not solved\n";

// --------------------- BitBoard Cube testing-------------------

//-------------------DFS Solver testing----------------------
//    RubiksCube3d cube;
////    cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    DFSSolver<RubiksCube3d, Hash3d> dfsSolver(cube, 7);
//    vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
//
//    if(dfsSolver.rubiksCube.isSolved()) cout<<"Solved\n";
//    else cout<<"Not solved\n";
//
//    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    dfsSolver.rubiksCube.print();


//--------------------------------BFS SOLVER TESTING-----------------
//    RubiksCubeBitboard cube;
//    cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
//    for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube);
//    vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
//
//    for(auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    bfsSolver.rubiksCube.print();


//-----------------------------IDDFS SOLVER TESTING---------------------
//    RubiksCubeBitboard cube;
//    cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube, 8);
//    vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();
//
//    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    iddfsSolver.rubiksCube.print();

//---------------------------- IDA* Solver Testing-------------------
//    RubiksCubeBitboard cube;
//    cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cube);
//    vector<RubiksCube::MOVE> solve_moves = idAstarSolver.solve();
//    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    idAstarSolver.rubiksCube.print();

//---------------------------Corner DB testing---------------
//
//    CornerPatternDatabase cornerDB;
//    RubiksCubeBitboard cube;
//    cube.print();
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cornerDB.setNumMoves(cube, 5);
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cube.randomShuffleCube(1);
//    cube.print();
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cornerDB.setNumMoves(cube, 6);
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";

//---------------------CornerDB-------------------------

string fileName= "D:\\UJ code\\Rubiks\\Database\\cornerDepth5V1.txt";
    //    Code to create Corner Database
//    cout<<"here1"<<endl;
//    CornerDBMaker dbMaker(fileName, 0x99);
//    dbMaker.bfsAndStore();
//    cout<<"here2\n";

    RubiksCubeBitboard cube;
    auto shuffleMoves = cube.randomShuffleCube(14);
//    auto shuffleMoves = cube.randomShuffleCube(13);
    cube.print();
    for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    cout << "\n";

    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    auto moves = idaStarSolver.solve();

    idaStarSolver.rubiksCube.print();
    for (auto move: moves) cout << cube.getMove(move) << " ";
    cout << "\n";


    return 0;

}
