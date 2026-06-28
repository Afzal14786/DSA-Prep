#include <iostream>
#include <vector>
#include <queue>

class Solution {
  public:
    const std::vector<std::vector<int>> coordinates = {{-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    
    int helper(int src_x, int src_y, int target_x, int target_y, int n) {
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n));
        std::queue<std::pair<int, int>> que;

        // Push the knight's starting coordinates into the queue and mark as visited
        que.push({src_x, src_y});
        visited[src_x][src_y] = true;

        int steps = 0;

        // Start level-by-level BFS traversal
        while (!que.empty()) {
            int qSize = que.size();

            while (qSize > 0) {
                // Extract coordinates for the current level
                auto [x, y] = que.front();
                que.pop();

                // Check if the target is reached
                if (x == target_x && y == target_y) return steps;

                // Traverse the 8 possible Knight moves
                for (int k = 0; k < coordinates.size(); ++k) {
                    int new_x = x + coordinates[k][0];
                    int new_y = y + coordinates[k][1];

                    // If the new move is within bounds and has not been visited
                    if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < n && !visited[new_x][new_y]) {
                        visited[new_x][new_y] = true;
                        que.push({new_x, new_y});
                    }
                }
                qSize--;
            }
            steps++; // Increment steps after finishing the current level
        }

        return -1;
    }

    /**
     * @brief Finds the minimum steps a Knight must take to reach a target position on an N x N board.
     *
     * @details
     * ### Approach: Breadth-First Search (BFS)
     * This problem is a classic unweighted shortest-path graph problem. Because every move 
     * costs exactly 1 step, a Breadth-First Search (BFS) is the optimal strategy. BFS guarantees 
     * that the first time we encounter the target cell, we have found the absolute shortest 
     * path to it. 
     * * 1. **Coordinate Transformation**: The input uses 1-based Cartesian coordinates (x, y), 
     * but standard 2D arrays use 0-based (row, col) indexing. The code safely transforms 
     * the input coordinates to matrix indices before running the BFS.
     * 2. **Level-by-Level Traversal**: A queue tracks the positions layer by layer. The `qSize` 
     * variable ensures we process all moves at the current depth (`steps`) before incrementing 
     * the step counter.
     * 3. **Visited Array**: A boolean matrix prevents the Knight from visiting the same square 
     * twice, effectively stopping infinite loops and redundant calculations.
     *
     * @param knightPos Initial 1-based [x, y] coordinates of the Knight.
     * @param targetPos Target 1-based [x, y] coordinates for the Knight.
     * @param n         The dimensions of the chessboard (n x n).
     * @return int      The minimum number of moves to reach the target, or -1 if unreachable.
     * * @complexity
     * - **Time Complexity**: $O(N^2)$. In the worst-case scenario, the Knight might have to 
     * traverse the entire $N \times N$ chessboard. Since each cell is pushed to the queue 
     * and processed at most once, the time scales linearly with the number of cells.
     * - **Space Complexity**: $O(N^2)$. The space is dominated by the $N \times N$ boolean 
     * `visited` matrix. Additionally, the BFS queue can hold up to $O(N^2)$ elements in 
     * the worst case.
     * 
     * @see https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
     * @see https://www.interviewbit.com/problems/knight-on-chess-board/
     */
    int minStepToReachTarget(std::vector<int>& knightPos, std::vector<int>& targetPos, int n) {
        
        // Convert 1-based Cartesian inputs (x, y) into 0-based Matrix indices (row, col)
        int src_x = n - knightPos[1];
        int src_y = knightPos[0] - 1;
        
        int target_x = n - targetPos[1];
        int target_y = targetPos[0] - 1;
        
        return helper(src_x, src_y, target_x, target_y, n);
    }
};