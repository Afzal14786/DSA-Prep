/**
 * @brief Detects whether a cycle exists in a given undirected graph.
 *
 * This solution uses Depth-First Search (DFS) with a parent tracking mechanism
 * to detect cycles. The algorithm handles graphs with multiple disconnected
 * components by initiating a DFS traversal from every unvisited vertex.
 *
 * @details
 * **Algorithm Steps:**
 * 1. Build an adjacency list representation of the graph from the given edges.
 * 2. Maintain a `visited` boolean array to track explored nodes.
 * 3. For each vertex `i` from `0` to `V-1`:
 *    - If `i` is not visited, start a DFS traversal with `i` as the starting node
 *      and `-1` as its initial parent.
 * 4. During DFS for a `node`:
 *    - Mark `node` as visited.
 *    - Iterate through all its neighbors (`nbr`).
 *    - If `nbr` is not visited, recursively call DFS on `nbr` with `node` as its parent.
 *      If the recursive call returns `true`, propagate `true` upwards.
 *    - Else if `nbr` is already visited **and** `nbr` is not the parent of the current `node`,
 *      it indicates a back edge, which implies the presence of a cycle. Return `true`.
 * 5. If no back edge is found in any component, return `false`.
 *
 * @note The graph is undirected. The parent check ensures that the edge leading
 *       back to the immediate previous node in the DFS tree is ignored, as it
 *       does not constitute a cycle.
 *
 * @param V Number of vertices in the graph. (0 <= vertices < V)
 * @param edges A 2D vector where each element `edges[i] = [u, v]` represents an
 *              undirected edge between vertex `u` and vertex `v`.
 *
 * @return `true` if the graph contains at least one cycle, otherwise `false`.
 *
 * @par Complexity Analysis
 * - **Time Complexity:** O(V + E)
 *   Where `V` is the number of vertices and `E` is the number of edges.
 *   In the worst case, the algorithm visits every vertex and traverses every edge
 *   exactly once (or twice due to the undirected adjacency list, but constants are
 *   ignored in Big-O notation).
 * - **Space Complexity:** O(V + E)
 *   - O(V + E) is required to store the adjacency list representation of the graph.
 *   - **Auxiliary Space:** O(V) in the worst case.
 *     This accounts for the `visited` array and the maximum depth of the recursion
 *     call stack (which can reach O(V) in a skewed graph, e.g., a chain).
 *
 * @par Examples
 * - Input: V = 4, edges = [[0, 1], [0, 2], [1, 2], [2, 3]]
 *   Output: `true` (Cycle: 1 -> 2 -> 0 -> 1)
 * - Input: V = 4, edges = [[0, 1], [1, 2], [2, 3]]
 *   Output: `false` (No cycle)
 *
 * @par Constraints
 * - 1 ≤ V, E ≤ 10^5
 * - 0 ≤ edges[i][0], edges[i][1] < V
 *
 * @see https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
 */

#include <iostream>
#include <vector>

class Solution {
  public:
    bool dfs(int node, std::vector<std::vector<int>> &adj, std::vector<bool> &vis, int parent) {
        // visit the node
        vis[node] = true;
        
        // now process the neighbour
        for (const auto nbr : adj[node]) {
            if (!vis[nbr]) {
                if (dfs(nbr, adj, vis, node)) return true; 
            } else if (vis[nbr] && nbr != parent) return true;
        }
        
        return false;
    }
    bool isCycle(int V, std::vector<std::vector<int>>& edges) {
        // Code here
        std::vector<std::vector<int>> adj(V);
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        std::vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                // perform dfs
                if(dfs(i, adj, visited, -1)) return true;
            }
        }
        
        return false;
    }
};