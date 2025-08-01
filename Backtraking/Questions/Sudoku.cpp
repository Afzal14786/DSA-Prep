#include <iostream>
#include <vector>
using namespace std;

// global vector for 9x9 sudoku grid
vector<vector<int>> grid = {
                        {0,0,8,0,0,0,0,0,0},
                        {4,9,0,1,5,7,0,0,2},
                        {0,0,3,0,0,4,1,9,0},
                        {1,8,5,0,6,0,0,2,0},
                        {0,0,0,0,2,0,0,6,0},
                        {9,6,0,4,0,5,3,0,0},
                        {0,3,0,0,7,2,0,0,4},
                        {0,4,9,0,3,0,0,5,7},
                        {8,2,7,0,0,9,0,1,3}
                        };

void printGrid(vector<vector<int>> &grid) {
    for (auto &row : grid) {
        for (int cellValue : row) {
            cout << cellValue << " ";
        }
        cout << endl;
    }
}

bool isValid(int row, int col, int value) {
    // check horizontaly
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == value) {
            return false;
        }
    }

    // check for verticlly
    for (int j = 0; j < 9; ++j) {
        if (grid[j][col] == value) {
            return false;
        }
    }

    // check for 3x3 subgrid
    int startRow = row-row%3;
    int startCol = col-col%3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == value) {
                return false;
            }
        }
    }

    return true;
}


bool SudokuSolver(int row, int col) {
    // base case 
    if (row == 9) {
        // print row
        printGrid(grid);
        return true;
    }

    // check for the nextRow and nextCol ? what if col is reached till end : then
    int nextRow = row;
    int nextCol = col + 1;

    if (col + 1 == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (grid[row][col] != 0) {
        return SudokuSolver(nextRow, nextCol);
    }

    for (int digit = 1; digit <= 9; ++digit) {
        if (isValid(row, col, digit)) {
            grid[row][col] = digit;
            if (SudokuSolver(nextRow, nextCol)) {
                return true;
            }
            grid[row][col] = 0;     // backtracking
        }
    }
    return false;
}

int main() {
    cout << "Before : \n";
    printGrid(grid);

    cout << "After : \n";
    SudokuSolver(0,0);
    return 0;
}