/**
 * In Grid way question . We have to find the number of ways to reach from top left corner to bottom right corner of a grid.
 * The only allowed moves are right and down.
 */

 #include <iostream>
 #include <vector>
 using namespace std;

int Grid (int row, int col, int n, int m) {
    if (row == n && col == m) {
        return 1;
    } else {
        int way = Grid(row, col+1, n, m);
        int way2 = Grid(row+1, col, n, m);
        return way + way2;
    }
}

 int main() {
    int n = 4, m = 4; // Grid size (n x m)
    int totalWays = Grid(1, 1, n-1, m-1); // Start from (1, 1) to (n, m)
    cout << "Total ways to reach from (1, 1) to (" << n << ", " << m << ") is: " << totalWays << endl;

    return 0;
 }