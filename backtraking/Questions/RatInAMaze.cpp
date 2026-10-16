#include <iostream>
#include <vector>
using namespace std;

// in this solution we are considering some of the global vactors and variables.

// in our solution we'll getting all the possible paths 'row & col' as well as we are printing the direction as well .

// means we have two solution
// 1. In a 2D matrix where we store solution row at solution[0] and col at solution[1] . Means that in the solution matrix we have only two rows and N paths (columns). 

const int MAZE_SIZE = 4;
int path = 0;   // for tracking the solution in 2D matrix
int POSSIBLE_SOLUTION = MAZE_SIZE * MAZE_SIZE;
vector<vector<int>> SOLUTION(2, vector<int>(POSSIBLE_SOLUTION));

// now we can also declare a global vector for creating a maze where 0 means block and 1 means open

vector<vector<int>> MAZE = {
    {1,0,0,0},
    {1,1,0,1},
    {0,1,0,0},
    {1,1,1,1}
};

void findPath(int i, int j, string direction) {
    // base case : when we reached the destination
    if (i == MAZE_SIZE-1 && j == MAZE_SIZE-1) {
        SOLUTION[0][path] = i;
        SOLUTION[1][path] = j;

        cout << "Solution Path In 2D Matrix: \n";
        for (int row = 0; row < 2; ++row) {
            for (int col = 0; col <= path; ++col) {
                cout << SOLUTION[row][col] << " ";
            }
            cout << endl;
        }

        cout << "Solution In Directions : ";
        cout << direction << endl; // also print the direction : example : DDRRDDLL
        cout << "---------------------------------\n";

        return;
    } else {
        // now in this code section deside how actually the rat move in all 4 directions

        // first mark the cell as visited
        MAZE[i][j] = 0;

        // now store the solution
        SOLUTION[0][path] = i;
        SOLUTION[1][path] = j;
        // increase the path for tracking the solution
        path++;

        // now we have to check the moves 
        // right moves
        if (j+1 < MAZE_SIZE && MAZE[i][j+1] == 1) {
            findPath(i, j+1, direction+"R");
        }

        // down move
        if (i+1 < MAZE_SIZE && MAZE[i+1][j] == 1) {
            findPath(i+1,j, direction+"D");
        }

        // left move
        if (j-1 >= 0 && MAZE[i][j-1] == 1) {
            findPath(i, j-1, direction+"L");
        }

        // up move
        if (i-1 >= 0 && MAZE[i-1][j] == 1) {
            findPath(i-1, j, direction+"U");
        }

        // now after all the direction if there is no path then backtrack and mark the cell as open
        MAZE[i][j] = 1;
        // and also reduce the solution by path-- so the solution will delete from SOLUTION
        path--;
    };
}

int main() {
    string direction = "";
    findPath(0,0, direction);  // rat start from (0,0);
    return 0;
}