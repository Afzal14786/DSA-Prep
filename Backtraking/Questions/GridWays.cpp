/**
 * In Grid way question . We have to find the number of ways to reach from top left corner to bottom right corner of a grid.
 * The only allowed moves are right and down.
 */

 #include <iostream>
 #include <vector>
 using namespace std;

int Grid (int row, int col, int n, int m, string ans) {
    if (row == n-1 && col == m-1) {
        cout << ans << endl;
        return 1;
    }

    if (row >= n || col >= m) {
        return 0;
    }

    int way = Grid(row, col+1, n, m, ans + "Right-> ");
    int way2 = Grid(row+1, col, n, m, ans + "Down-> ");
    return way + way2;
}

// Optimize Solution //
 
int fact(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * fact(n-1);
}

int Grid2(int n, int m) {
    int ans = fact(n-1 + m-1) / (fact(n-1) * fact(m-1));
    return ans;
}


 int main() {
    int n = 3, m = 3; // Grid size (n x m)
    string ans = "";
    // int ways = Grid(0, 0, n, m, ans);
    // cout << "Total No Of Ways = " << ways << endl;

    cout << Grid2(3, 3) << endl;
    return 0;
 }