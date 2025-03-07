//implement maze.h
#include "maze.h"
//include iostream library: for debugging and console output.
#include <iostream>

//main function
int main(int agrc, char* argv[]) {
    //assign unsigned integer seed with first command line arguement.
    unsigned int seed = std:: stoi(argv[1]);
    //assign integer rows with second command line arguement.
    int rows = std::stoi(argv[2]);
    //assign integer cols with third command line arguement.
    int cols = std::stoi(argv[3]);
    //store fourth command line arguement as a string for file name.
    std::string filename = argv[4];

    //create maze object with seed, rows, and cols.
    Maze maze(seed, rows, cols);
    //generate maze: call mazeGenerator function.
    maze.mazeGenerator();
    //export file: export file of created maze.
    maze.exportFile(filename);
}
