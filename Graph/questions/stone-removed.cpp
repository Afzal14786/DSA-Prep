/**
 * @brief Computes the maximum number of stones that can be removed from the
 *        plane, given that a stone can be removed if it shares the same row
 *        or column with another stone that has not been removed.
 *
 * @details
 * **Problem Understanding:**
 * We have n stones at distinct integer coordinates. Removing a stone is allowed
 * if there exists at least one other stone (still on the plane) in the same row
 * or same column. We can remove stones one by one, and after each removal the
 * plane updates. The goal is to maximise the total number of removals.
 *
 * **Key Observation:**
 * Stones that are **connected** via rows/columns (i.e., they form a connected
 * component in a graph where edges exist between stones sharing a row or column)
 * can be reduced to a single stone. Within any connected component, we can
 * remove all but one stone. This is because we can always find an order to
 * remove stones as long as at least one remains in that component.
 *
 * **Why:** In a connected component, we can repeatedly pick a stone that has a
 * neighbour still present and remove it, until only one stone is left.
 * Therefore, the **maximum removals** = total stones - number of connected components.
 *
 * **Solution Approach:**
 * 1. Treat each stone as a node in an undirected graph.
 * 2. Two nodes are connected if they share the same row (x-coordinate) or same
 *    column (y-coordinate).
 * 3. Use Depth‑First Search (DFS) to find all connected components.
 * 4. For each component, we count one stone that must remain.
 * 5. Answer = n - (number of components).
 *
 * **Algorithm Steps:**
 * - Initialise a `visited` boolean array of size n.
 * - Iterate over every stone index `i`.
 * - If `i` is unvisited, start a DFS from `i` to mark all stones in its component.
 * - Increment the component counter after each DFS.
 * - Return `n - componentCount`.
 *
 * **Why this works:**
 * This is a classic graph problem. The minimum number of stones that must remain
 * equals the number of connected components because in each component we can
 * keep exactly one stone (the "last survivor"). All other stones in the component
 * can be removed, and stones in different components are independent.
 *
 * @param stones  A 2D vector where stones[i] = {x, y} represents the coordinates.
 * @return int    The maximum number of stones that can be removed.
 *
 * @par Complexity
 * - **Time:** O(n²) in the worst case, where n is the number of stones.
 *   The DFS visits each stone once, and for each stone we iterate over all other
 *   stones to find neighbours (O(n) per stone) → O(n²). With n ≤ 1000, this is acceptable.
 *   *Note:* The graph is dense because a stone shares row/column with many others.
 * - **Auxiliary Space:** O(n) for the `visited` array and the recursion stack
 *   (which in worst case can go up to n).
 *
 * @par Examples
 * - Example 1: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]] → output 5.
 * - Example 2: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]] → output 3.
 * - Example 3: stones = [[0,0]] → output 0.
 *
 * @see https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 */

#include <iostream>
#include <vector>

class Solution {
private:
    /**
     * @brief Depth‑First Search to mark all stones in the same connected component.
     *
     * @param idx      Current stone index.
     * @param stones   Reference to the stones array.
     * @param visited  Boolean array marking visited stones.
     */
    void dfsComponent(int idx, const std::vector<std::vector<int>>& stones,
                      std::vector<bool>& visited) {
        visited[idx] = true;  // mark current stone as visited

        // Explore all other stones
        for (int j = 0; j < (int)stones.size(); ++j) {
            // Skip already visited and self
            if (!visited[j]) {
                // If they share the same row (x) or same column (y) → they are connected
                if (stones[j][0] == stones[idx][0] || stones[j][1] == stones[idx][1]) {
                    dfsComponent(j, stones, visited);
                }
            }
        }
    }

public:
    int removeStones(std::vector<std::vector<int>>& stones) {
        int totalStones = stones.size();
        std::vector<bool> visited(totalStones, false);

        int componentCount = 0;

        // Iterate over every stone
        for (int i = 0; i < totalStones; ++i) {
            if (!visited[i]) {
                // New component found: DFS from stone i
                dfsComponent(i, stones, visited);
                componentCount++;
            }
        }

        // In each component, one stone must remain; the rest can be removed.
        return totalStones - componentCount;
    }
};