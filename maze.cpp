//implement maze.h
#include "maze.h"
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

//contructor
Maze::Maze(unsigned int s, int n, int m): seed(s), rows(n), cols(m) {
    //initialize variables seed, rows and cols.
    this->seed = s;
    this->rows = n;
    this->cols = m;
    std::srand(this->seed);
    //initialize grid vector with 15 (all walls).
    this->grid = std::vector<std::vector<int>>(this->rows, std::vector<int>(this->cols, 15));
    //Initialize visited vector with false (all unvisited).
    this->visited = std::vector<std::vector<bool>>(this->rows, std::vector<bool>(this->cols, false));
    //remove north wall of first cell.
    grid[0][0] -= 8;
    //remove south wall of last cell.
    grid[this->rows - 1][this->cols - 1] -= 4;
}

//inBounds method: check if row and col are in bounds, if in bounds return true, else false.
bool Maze::inBounds(int row, int col) {
    if (row >= 0 && row < this->rows && col >= 0 && col < this->cols && visited[row][col] == false){
        return true;
    }
    
        return false;
    
}   

//getValidNeighbor method: check if neighbor is in bounds and not visited,
// if not true put neighbor in validNeighrbors vector.
std::vector<std::pair<int,int>> Maze::getValidNeighbors(int row, int col) {
    //vector for neighbors
    std::vector<std::pair<int,int>> validNeighbors;

    if (inBounds(row - 1, col) && !this->visited[row-1][col]) {
        validNeighbors.push_back({row - 1,col});
    }

    if (inBounds(row + 1, col) && !this->visited[row + 1][col]) {
        validNeighbors.push_back({row + 1,col});
    }

    if (inBounds(row, col + 1) && !this->visited[row][col + 1]) {
        validNeighbors.push_back({row,col + 1});
    }
    if (inBounds(row, col - 1) && !this->visited[row][col - 1]) {
        validNeighbors.push_back({row,col - 1});
    }

    return validNeighbors;
}
//removeWall method: remove wall between currrent and neighbor cells.
void Maze::removeWall(int currentRow, int currentCol, int nextRow, int nextCol) {
    if (currentRow == nextRow - 1 && currentCol == nextCol) {

        this->grid[currentRow][currentCol] -= 4;
        this->grid[nextRow][nextCol] -= 8;
    }
    else if (currentRow == nextRow + 1 && currentCol == nextCol) {

        this->grid[currentRow][currentCol] -= 8;
        this->grid[nextRow][nextCol] -= 4;
    }
    else if (currentRow == nextRow && currentCol == nextCol + 1) {

        this->grid[currentRow][currentCol] -= 1;
        this->grid[nextRow][nextCol] -= 2;
    }
    else if (currentRow == nextRow && currentCol == nextCol -1) {
        this->grid[currentRow][currentCol] -= 2;
        this->grid[nextRow][nextCol] -= 1;
    }
}
//mazeGenerator method: generate maze. 
void Maze::mazeGenerator() {
    //vector to keep track of path during maze generation
    std::vector<std::pair<int,int>> a_path;
    //mark cell [0,0] as visited
    visited[0][0] = true;
    //insert cell [0,0] at the end of a_path
    a_path.push_back(std::make_pair(0,0));
    //while a_path is not empty
    while (!a_path.empty()) {

        //store element in current variable
        std::pair<int,int> current = a_path.back();

        //remove last element from a_path
        a_path.pop_back();
        //create neighbors vector
        std::vector<std::pair<int,int>> neighbors;
        //store valid unvisited neighbors in neighbors vector
        neighbors = getValidNeighbors(current.first, current.second);

        //if neighbors is not empty
        if (!neighbors.empty()) {
            //insert current at the end of a_path
            a_path.push_back(current);
            //pick a random neighbor from neighbors
            int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
            //store random neighbor in neigh variable
            std::pair<int,int> neigh = neighbors[idx];
            //call remove wall method: remove wall between current and neigh
            removeWall(current.first, current.second, neigh.first, neigh.second);
            //call visited method: mark neigh as visited
            this->visited[neigh.first][neigh.second] = true;
            //insert neigh at the end of a_path
            a_path.push_back(neigh);  
        }
    }
}
//exportFile method: write file.
void Maze::exportFile(const std::string& filename) {
    //open a file to create.
   std::ofstream outfile(filename);
    //loop through rows and columns and export to file.
   for (int i = 0; i < this->rows; ++i) {
    for (int j = 0; j < this->cols; ++j) {
        outfile << this->grid[i][j];
    //for every column, put a space after it.
        if (j < this->cols - 1) {
            outfile << " ";
        }
    }
    //output nextline after each loop.
    outfile << "\n";

   }
    //close file.
    outfile.close();
}
    




