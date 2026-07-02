/**
 * @brief Determines if there exists a path from the top-left to the bottom-right
 *        corner of a binary grid such that the remaining health stays positive.
 *
 * @details
 * **Problem Statement:**
 * You are given an `m x n` binary matrix `grid` and an integer `health`.
 * Starting at `(0, 0)`, you can move in four directions (up, down, left, right)
 * to adjacent cells. Every time you step into a cell with `grid[i][j] == 1`
 * (unsafe), your health decreases by 1. You must ensure your health remains
 * **positive** (≥ 1) at all times, including after reaching the target
 * `(m-1, n-1)`. Return `true` if such a path exists, otherwise `false`.
 *
 * ---
 * **Solution Approach (0‑1 BFS):**
 * - The graph is unweighted, but each cell has a cost of either `0` (safe) or `1` (unsafe).
 * - We want to **minimize the total number of unsafe cells** encountered along any path.
 * - This is a shortest‑path problem on a grid with edge weights `0` or `1`, solvable by
 *   **0‑1 Breadth‑First Search** (0‑1 BFS) using a deque.
 *
 * **Algorithm Steps:**
 * 1. Initialize a `distance` matrix with a large value (`INF`) to track the minimal
 *    unsafe count from `(0, 0)` to each cell.
 * 2. Set `distance[0][0] = grid[0][0]` (cost of the starting cell).
 * 3. Push `(0, 0)` to the front of the deque.
 * 4. While the deque is not empty:
 *    - Pop the front cell `(i, j)`.
 *    - If `(i, j)` is the target `(m-1, n-1)`, return `distance[i][j] < health`
 *      (because we need strictly more health than the unsafe count).
 *    - Explore all 4 neighbours `(ni, nj)`.
 *    - Skip out‑of‑bounds neighbours.
 *    - Let `wt = grid[ni][nj]` (cost of stepping into the neighbour).
 *    - If `distance[i][j] + wt < distance[ni][nj]`:
 *        - Update the neighbour’s distance.
 *        - If `wt == 0`, push the neighbour to the **front** of the deque.
 *        - Else (`wt == 1`), push it to the **back** of the deque.
 * 5. If the loop ends, return `distance[m-1][n-1] < health` (fallback, though the
 *    target would have been checked when popped).
 *
 * **Why 0‑1 BFS works:**
 * - It maintains the deque in non‑decreasing order of distances, ensuring that when
 *   a node is popped, its distance is final (like Dijkstra for 0/1 weights).
 * - Pushing 0‑weight edges to the front and 1‑weight edges to the back gives O(V+E)
 *   performance, which is optimal for this grid size.
 *
 * ---
 * @param grid  A 2D binary matrix (`m x n`) where `grid[i][j] == 1` denotes an unsafe cell.
 * @param health The initial health value (must remain ≥ 1 throughout the walk).
 *
 * @return `true`  if a path exists such that the final health is ≥ 1,
 *         `false` otherwise.
 *
 * @par Complexity Analysis
 * - **Time Complexity:** O(m * n)  
 *   Each cell is processed at most once, and each edge (up to 4 per cell) is examined once.
 *   The 0‑1 BFS runs in linear time with respect to the number of cells.
 * - **Auxiliary Space:** O(m * n)  
 *   The `distance` matrix and the deque can hold up to all cells in the worst case.
 *   (The deque size is at most O(m*n).)
 *
 * @par Examples
 * - Example 1:  
 *   `grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]`, `health = 1` → Returns `true`.  
 *   Explanation: A path through the gray (safe) cells exists, keeping health ≥ 1.
 *
 * - Example 2:  
 *   `grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]]`, `health = 3` → Returns `false`.  
 *   Explanation: The minimum unsafe cells on any path is 4, which is not < 3.
 *
 * - Example 3:  
 *   `grid = [[1,1,1],[1,0,1],[1,1,1]]`, `health = 5` → Returns `true`.  
 *   Explanation: The centre cell `(1,1)` is safe, and going straight through it
 *   costs 1 unsafe cell (only the start cell is unsafe if we start on 1? Actually
 *   the solution counts the starting cell cost; if starting is unsafe, it's included.
 *   In this grid, any path not using `(1,1)` goes through five 1's, costing 5,
 *   which would make health 0 (not allowed). Using `(1,1)` reduces the cost to 1,
 *   so health 5 is enough.
 *
 * @note The problem guarantees `1 ≤ m, n ≤ 50`, `2 ≤ m*n`, and `1 ≤ health ≤ m + n`.
 *       This solution works for all such inputs.
 *
 * @see https://leetcode.com/problems/find-a-safe-walk-through-a-grid/?envType=daily-question&envId=2026-07-02
 */

#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    /**
     * @brief Finds whether a safe walk exists using 0‑1 BFS.
     * 
     * @param grid  Binary matrix (1 = unsafe, 0 = safe)
     * @param health Initial health (must remain > 0)
     * @return true if a path reaches (rows-1, cols-1) with health ≥ 1
     */
    bool findSafeWalk(std::vector<std::vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();

        // minimal number of unsafe cells encountered to reach each cell
        std::vector<std::vector<int>> minUnsafe(rows, std::vector<int>(cols, 1e9));
        
        // deque for 0‑1 BFS: front for 0‑cost moves, back for 1‑cost moves
        std::deque<std::pair<int, int>> cellQueue;

        // 4 directional offsets: up, down, left, right
        std::vector<std::vector<int>> neighborOffsets = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        // initialize the starting cell – its cost is grid[0][0]
        minUnsafe[0][0] = grid[0][0];
        cellQueue.push_front({0, 0});

        while (!cellQueue.empty()) {
            auto [row, col] = cellQueue.front();
            cellQueue.pop_front();

            // if we reach the target, check if health can survive
            if (row == rows - 1 && col == cols - 1) {
                // need strictly more health than the number of unsafe cells
                return minUnsafe[row][col] < health;
            }

            // explore all neighbours
            for (const auto& offset : neighborOffsets) {
                int newRow = row + offset[0];
                int newCol = col + offset[1];

                // bounds check
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                    continue;
                }

                // cost to step into this neighbour (0 or 1)
                int cellCost = grid[newRow][newCol];

                // relaxation step
                if (minUnsafe[row][col] + cellCost < minUnsafe[newRow][newCol]) {
                    minUnsafe[newRow][newCol] = minUnsafe[row][col] + cellCost;

                    // 0‑1 BFS: push 0‑cost neighbours to front, 1‑cost to back
                    if (cellCost == 0) {
                        cellQueue.push_front({newRow, newCol});
                    } else {
                        cellQueue.push_back({newRow, newCol});
                    }
                }
            }
        }

        // fallback (will be unreachable if target was processed, but kept for safety)
        return minUnsafe[rows - 1][cols - 1] < health;
    }
};