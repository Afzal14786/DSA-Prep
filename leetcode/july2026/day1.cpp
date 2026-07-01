// Question Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/**
 * @class Solution
 * @brief Solves the "Find the Safest Path in a Grid" problem using Multi-Source BFS and Binary Search.
 */
class Solution {
private:
    size_t n;
    // Standard 4-directional movement vectors (Up, Down, Left, Right)
    const std::vector<std::vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    /**
     * @brief Checks if a valid path exists from (0,0) to (n-1, n-1) with a minimum safeness factor.
     * * @param manhattanDistance 2D grid containing the shortest distance to any thief.
     * @param safe_threshold The safeness factor we are currently testing.
     * @return true If a path exists where every cell has a safeness >= safe_threshold.
     * @return false Otherwise.
     */
    bool hasValidPath(const std::vector<std::vector<int>>& manhattanDistance, int safe_threshold) {
        // Base case: If start or end cell itself has a safeness strictly less than the threshold, path is impossible.
        if (manhattanDistance[0][0] < safe_threshold || manhattanDistance[n-1][n-1] < safe_threshold) {
            return false;
        }

        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        std::queue<std::pair<int, int>> searchQueue;

        searchQueue.push({0, 0});
        visited[0][0] = true;

        while (!searchQueue.empty()) {
            auto [curr_i, curr_j] = searchQueue.front();
            searchQueue.pop();

            // Target reached
            if (curr_i == n - 1 && curr_j == n - 1) {
                return true;
            }

            // Explore adjacent cells
            for (const auto& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                // Boundary check and visited check
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !visited[new_i][new_j]) {
                    // Only traverse if the cell meets the safeness threshold
                    if (manhattanDistance[new_i][new_j] >= safe_threshold) {
                        searchQueue.push({new_i, new_j});
                        visited[new_i][new_j] = true;
                    }
                }
            }
        }

        return false;
    }

public:
    /**
     * @brief Computes the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
     * * @param grid A 0-indexed 2D matrix where 1 represents a thief and 0 represents an empty cell.
     * @return int The maximum safeness factor.
     */
    int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
        n = grid.size();
        
        // Step 1: Multi-Source BFS to compute minimum Manhattan distance to nearest thief for every cell
        std::vector<std::vector<int>> manhattanDistances(n, std::vector<int>(n, -1));
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        std::queue<std::pair<int, int>> searchQueue;

        // Initialize the queue with all thieves (multiple sources)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    searchQueue.push({i, j});
                    visited[i][j] = true; 
                }
            }
        }

        int distance_level = 0;
        
        // Process the grid radially outward from all thieves simultaneously
        while (!searchQueue.empty()) {
            int level_size = searchQueue.size();
            
            while (level_size--) {
                auto [curr_i, curr_j] = searchQueue.front();
                searchQueue.pop();

                // Assign the distance for the current cell
                manhattanDistances[curr_i][curr_j] = distance_level;

                for (const auto& dir : directions) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    
                    // Boundary check
                    if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j]) {
                        continue;
                    }

                    searchQueue.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
            distance_level++;
        }

        // Step 2: Binary Search on the answer (safeness factor)
        // The maximum possible distance in an N x N grid is roughly 2N
        int low = 0, high = 2 * n; 
        int max_safeness = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (hasValidPath(manhattanDistances, mid)) {
                max_safeness = mid; // A valid path was found, try for a higher safeness factor
                low = mid + 1;
            } else {
                high = mid - 1;     // The threshold was too high, reduce it
            }
        }

        return max_safeness;
    }
};