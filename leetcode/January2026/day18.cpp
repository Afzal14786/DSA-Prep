#include <iostream>
#include <vector>

class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j, int k) {
    int target = 0;

    // first row
    for (int c = j; c < j + k; c++) {
        target += grid[i][c];
    }

    // rows
    for (int r = i; r < i + k; r++) {
        int sum = 0;
        for (int c = j; c < j + k; c++) sum += grid[r][c];
        if (sum != target) return false;
    }

    // columns
    for (int c = j; c < j + k; c++) {
        int sum = 0;
        for (int r = i; r < i + k; r++) sum += grid[r][c];
        if (sum != target) return false;
    }

    // main diagonal
    int sum = 0;
    for (int p = 0; p < k; p++) sum += grid[i + p][j + p];
    if (sum != target) return false;

    // anti diagonal
    sum = 0;
    for (int p = 0; p < k; p++) sum += grid[i + p][j + k - 1 - p];
    if (sum != target) return false;

    return true;
}


    int largestMagicSquare(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int maxi = 1;

        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= m - k; j++) {
                    if (check(grid, i, j, k)) {
                        maxi = max(k,maxi);
                        
                    }
                }
            }
        }
        return maxi;
    }
};