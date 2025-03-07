# Maze-Generator
This C++ program generates a randomized maze using a depth-first search algorithm. The maze is represented as a grid with walls represented by numbers, and the output is saved to a file.

## Features
- Generates a random maze bazed on input dimensions.
- Uses depth-first search (DFS) with backtracking to carve paths.
- Allows custom seed input for reproducibility.
- Saves the generated maze to a specified output file.

## Usage
### ***Compile the program***
```sh
g++ -o maze_generator main.cpp maze.cpp
```
### ***Run the Program***
```sh
./maze_generator <seed> <rows> <cols> <output_file>
```

## File Format
- output.txt (or user-specified file): Contains the numerical representation of the maze, where each cell's numerical value represents its walls and open paths.

## Project Structure
```sh
├── main.cpp        # Entry point of the program
├── maze.cpp        # Maze generation logic
├── maze.h          # Header file with class definition
└── output-stu.txt  # Sample generated maze file
```

## Technologies Used
- C++
- Standard Library (vector, fstream,ctime,cstdlib)

## Author 
Alyana Barbosa

