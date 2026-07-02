/**
 * @brief Detects whether a cycle exists in a given **directed** graph.
 *
 * This solution uses Depth‑First Search (DFS) with a **recursion stack** (also
 * called the "on‑stack" or "in‑current‑path" array) to detect back edges,
 * which indicate a cycle in a directed graph.
 *
 * @details
 * **Algorithm Steps:**
 * 1. Build an adjacency list from the directed edges (only `u -> v`).
 * 2. Maintain two arrays:
 *    - `visited` : marks vertices already fully processed.
 *    - `inRecursion` : marks vertices that are currently in the DFS recursion stack
 *      (i.e., part of the current path).
 * 3. For every unvisited vertex, start a DFS.
 * 4. During DFS for a `currentNode`:
 *    - Mark `currentNode` as visited and add it to the recursion stack.
 *    - For each `neighbor` of `currentNode`:
 *      - If `neighbor` is not visited, recursively call DFS on it.
 *        If that call returns `true`, a cycle exists → propagate `true`.
 *      - Else if `neighbor` is already visited **and** `inRecursion[neighbor]` is `true`,
 *        then it is a back edge → cycle found → return `true`.
 *    - After exploring all neighbours, remove `currentNode` from the recursion stack
 *      (backtrack) and return `false`.
 * 5. If no back edge is found in any component, return `false`.
 *
 * @note The graph is directed. A back edge is an edge from a node to an ancestor
 *       in the DFS tree, which only forms a cycle if the ancestor is currently
 *       on the recursion stack.
 *
 * @param V      Number of vertices (labelled 0 to V-1).
 * @param edges  A 2D vector where each element `edges[i] = [u, v]` represents a
 *               **directed** edge from vertex `u` to vertex `v`.
 *
 * @return `true`  if the graph contains at least one directed cycle,
 *         `false` otherwise.
 *
 * @par Complexity Analysis
 * - **Time Complexity:** O(V + E)
 *   Every vertex is visited once, and every edge is examined once.
 * - **Space Complexity:** O(V + E)
 *   - O(V + E) to store the adjacency list.
 *   - **Auxiliary Space:** O(V) for the `visited` array, `inRecursion` array,
 *     and the recursion call stack (worst‑case depth O(V) for a skew graph).
 *
 * @par Examples
 * - Input: V = 4, edges = [[0, 1], [1, 2], [2, 0], [2, 3]]
 *   Output: `true` (Cycle: 0 → 1 → 2 → 0)
 * - Input: V = 4, edges = [[0, 1], [0, 2], [1, 2], [2, 3]]
 *   Output: `false` (No cycle)
 *
 * @par Constraints
 * - 1 ≤ V ≤ 10^5
 * - 0 ≤ E ≤ 10^5
 * - 0 ≤ edges[i][0], edges[i][1] < V
 *
 * @see https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
 */

#include <iostream>
#include <vector>

class Solution {
private:
    /**
     * @brief DFS helper to detect a cycle starting from a given node.
     *
     * @param currentNode  The vertex currently being explored.
     * @param adjacency    Adjacency list of the directed graph.
     * @param isVisited    Array marking vertices already fully processed.
     * @param inRecursion  Array marking vertices currently in the recursion stack.
     * @return `true` if a cycle is found, `false` otherwise.
     */
    bool dfs(int currentNode,
             const std::vector<std::vector<int>>& adjacency,
             std::vector<bool>& isVisited,
             std::vector<bool>& inRecursion) {

        isVisited[currentNode] = true;
        inRecursion[currentNode] = true;

        // Explore all neighbours
        for (int neighbor : adjacency[currentNode]) {
            if (!isVisited[neighbor]) {
                // Recurse on unvisited neighbour
                if (dfs(neighbor, adjacency, isVisited, inRecursion)) {
                    return true;
                }
            } else if (inRecursion[neighbor]) {
                // Back edge found → cycle
                return true;
            }
        }

        // Backtrack: remove current node from recursion stack
        inRecursion[currentNode] = false;
        return false;
    }

public:
    /**
     * @brief Entry point to detect a directed cycle in the graph.
     *
     * @param V      Number of vertices.
     * @param edges  List of directed edges.
     * @return `true` if the graph contains a cycle, `false` otherwise.
     */
    bool isCyclic(int V, const std::vector<std::vector<int>>& edges) {
        // Build directed adjacency list (only u → v)
        std::vector<std::vector<int>> adjacency(V);
        for (const auto& edge : edges) {
            int from = edge[0];
            int to   = edge[1];
            adjacency[from].push_back(to);
        }

        std::vector<bool> isVisited(V, false);
        std::vector<bool> inRecursion(V, false);

        // Process every vertex (handles disconnected components)
        for (int i = 0; i < V; ++i) {
            if (!isVisited[i]) {
                if (dfs(i, adjacency, isVisited, inRecursion)) {
                    return true;
                }
            }
        }

        return false;
    }
};