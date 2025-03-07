//preprocessor directive: check if MAZE_H has been defined.
#ifndef MAZE_H
//define macro name: MAZE_H.
#define MAZE_H

//include iostream library: for debugging and console output.
#include <iostream>
//include fstream library: for file output.
#include <fstream>
//include ctime library: for std:: time, to seed the RNG.
#include <ctime>
//include cstdlib library: for std::rand and std::srand.
#include <cstdlib>
//include vector library: for std::vector.
#include <vector>

class Maze {
//for all private attributes and methods of the maze class.
private:

    //Private variables int row and int cols.
    unsigned int seed;
    int rows;
    int cols;
    //vector for generating grid.
    std::vector<std::vector<int>> grid;

    //vector for visited cells.
    std::vector<std::vector<bool>> visited;

//for all public attributes and methods.
public:
    
    //constructor
    Maze(unsigned int seed,int rows, int cols);

    std::vector<std::pair<int,int>> getValidNeighbors(int row, int col);
    
    //private abstract  static method: remove wall between current cell and neighbor cell.
    void removeWall(int currentRow, int currentCol, int nextRow, int nextCol);

    //private abstract method: return bool true if cell is in bounds
    bool inBounds(int row, int col);
    //public abstract static method: call other functions and generate maze through loop.
    void mazeGenerator();
    //public abstract static method: format maze text to file.
    void exportFile(const std::string& filename);

};
//closing directive
#endif // MAZE_H
