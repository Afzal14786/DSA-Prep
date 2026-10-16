/**
 * Problem: Nearest Exit from Entrance in Maze
 * -------------------------------------------------
 * Given an m x n maze grid with empty cells ('.') and walls ('+'), and an entrance cell,
 * find the shortest path (in steps) to any exit (an empty border cell) that is not the entrance.
 * Return -1 if no exit is reachable.
 *
 * Approach: BFS (Breadth-First Search)
 * ------------------------------------
 * Since we need the shortest number of steps to reach any exit, BFS is ideal.
 * We start from the entrance cell, and explore its neighboring cells level by level.
 * The first border cell we encounter (excluding the entrance) is the nearest exit.
 * We mark visited cells as walls ('+') to avoid revisiting and to save space.
 *
 * Time Complexity  : O(m * n) - In the worst case, we might visit every cell once.
 * Space Complexity : O(m * n) - The queue can hold up to all cells in the worst case.
 *
 * @see https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    // All four possible movement directions: right, left, down, up
    std::vector<std::vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        int entranceRow = entrance[0];
        int entranceCol = entrance[1];

        // Queue for BFS: stores pairs (row, col)
        std::queue<std::pair<int, int>> queue;
        queue.push({entranceRow, entranceCol});

        // Mark the entrance as visited by turning it into a wall.
        // This also prevents counting the entrance itself as an exit.
        maze[entranceRow][entranceCol] = '+';

        int steps = 0;  // Number of steps taken from the entrance

        while (!queue.empty()) {
            int levelSize = queue.size();   // Number of cells at the current distance

            // Process all cells at this distance level
            for (int i = 0; i < levelSize; ++i) {
                auto [row, col] = queue.front();
                queue.pop();

                // Check if the current cell is on the border AND it is NOT the entrance.
                // (The entrance was marked as '+', but we also explicitly check coordinates.)
                if ((row == 0 || row == rows - 1 || col == 0 || col == cols - 1) &&
                    !(row == entranceRow && col == entranceCol)) {
                    return steps;   // First exit found -> shortest path
                }

                // Explore all four neighbors
                for (const auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    // Check if neighbor is inside the grid and is an empty cell (not a wall)
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                        maze[newRow][newCol] == '.') {
                        // Mark as visited (treat as wall) and add to queue
                        maze[newRow][newCol] = '+';
                        queue.push({newRow, newCol});
                    }
                }
            }
            // Increment steps after finishing one BFS level
            ++steps;
        }

        // No exit reachable from the entrance
        return -1;
    }
};