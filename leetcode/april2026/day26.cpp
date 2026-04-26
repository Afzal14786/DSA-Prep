// Question Link : https://leetcode.com/problems/detect-cycles-in-2d-grid/?envType=daily-question&envId=2026-04-26

#include <iostream>
#include <vector>

class Solution {
public:
    int m, n;
    std::vector<std::vector<int>> direction = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};  // DOWN UP LEFT RIGHT
    bool dfs(int row, int col, int prev_r, int prev_c, std::vector<std::vector<char>> &grid, std::vector<std::vector<bool>> &visited) {
        if (visited[row][col] == true) return true;

        visited[row][col] = true;

        for (auto &dir : direction) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && grid[new_row][new_col] == grid[row][col]) {
                if (new_row == prev_r && new_col == prev_c) continue;
                if (dfs(new_row, new_col, row, col, grid, visited)) return true;
            }
        }
        return false;
    }

    bool containsCycle(std::vector<std::vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && dfs(i, j, i, j, grid, visited)) return true;
            }
        }

        return false;
    }
};