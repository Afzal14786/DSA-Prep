// Question Link : https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/?envType=daily-question&envId=2026-04-27

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int m, n;
    std::unordered_map<int, std::vector<std::vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{-1, 0}, {0, 1}}}
    };

    bool dfs(std::vector<std::vector<int>>& grid, int row, int col, std::vector<std::vector<bool>> &visited) {
        if (row == m-1 && col == n-1) return true;
        visited[row][col] = true;

        for (auto &dir : directions[grid[row][col]]) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n || visited[new_row][new_col])  continue;
            for (auto &back_dir : directions[grid[new_row][new_col]]) {
                if (new_row + back_dir[0] == row && new_col + back_dir[1] == col) {
                    if (dfs(grid, new_row, new_col, visited)) return true;
                }
            }
        }

        return false;

    }

    bool hasValidPath(std::vector<std::vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        return dfs(grid, 0, 0, visited);
    }
};