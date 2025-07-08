#include <iostream>
using namespace std;

/**
 * Given a "2 x n" board and tiles of size "2 x 1", the task is to count the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. 
 * 
 * Input: n = 4
    Output: 5
    Explanation: For a 2 x 4 board, there are 5 ways

    All 4 vertical (1 way)
    All 4 horizontal (1 way)
    2 vertical and 2 horizontal (3 ways)

    The idea is to explore two possible ways to place tiles on a 2 x n board: either placing a vertical tile (2 x 1) which reduces the problem to filling a 2 x (n-1) board, or placing two horizontal tiles (1 x 2) which reduces the problem to filling a 2 x (n-2) board. At each step, we sum these two possibilities, creating a recursive solution where the total number of ways to tile the board is the sum of ways for the smaller subproblems. 

    Mathematically the recurrence relation will look like the following:
        numberOfWays(n) = numberOfWays(n-1) + numberOfWays(n-2).

    Base Cases:
        numberOfWays(n) = 1, if n = 0.
        numberOfWays(n) = 0, if n < 0.

 */

int tilingProblem(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return tilingProblem(n-1) + tilingProblem(n-2);
}

int main() {
    cout << "possible ways : " << tilingProblem(1) << endl;       // possible ways 1
    cout << "possible ways : " << tilingProblem(2) << endl;       // possible ways 2
    cout << "possible ways : " << tilingProblem(3) << endl;       // possible ways 3
    cout << "possible ways : " << tilingProblem(4) << endl;       // possible ways 5
    cout << "possible ways : " << tilingProblem(5) << endl;       // possible ways 8
    cout << "possible ways : " << tilingProblem(6) << endl;       // possible ways 13
    cout << "possible ways : " << tilingProblem(7) << endl;       // possible ways 21
    return 0;
}