// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

// Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

// Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

// Example 1:

// Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
// Output: 1

// Example 2:

// Input: grid = [[8]]
// Output: 0

// Constraints:

//     row == grid.length
//     col == grid[i].length
//     1 <= row, col <= 10
//     0 <= grid[i][j] <= 15

// Question Link : https://leetcode.com/problems/magic-squares-in-grid/?envType=daily-question&envId=2025-12-30

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<int> s;
        vector<int> row(3, 0);
        vector<int> col(3, 0);
        for (int k = i; k < i + 3; k++) {
            for (int l = j; l < j + 3; l++) {
                if (grid[k][l] > 9 || s.find(grid[k][l]) != s.end() ||grid[k][l] <1) {
                    return false;
                }
                s.insert(grid[k][l]);
                row[k - i] += grid[k][l];
                col[l - j] += grid[k][l];
            }
        }

        int sum = row[0];

        for (int i = 0; i < 3; i++) {

            if (row[i] != sum || col[i] != sum) {
                return false;
            }
        }
        int diagonal = 0;
        for (int k = 0; k < 3; k++) {
            diagonal += grid[k + i][k + j];
        }
        if (sum != diagonal) {
            return false;
        }
        diagonal = 0;
        for (int k = 0; k < 3; k++) {
            diagonal += grid[i + 2 - k][k + j];
        }

        if (sum != diagonal) {
            return false;
        }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (check(i, j, grid)) {
                    count++;
                }
            }
        }

        return count;
    }
};