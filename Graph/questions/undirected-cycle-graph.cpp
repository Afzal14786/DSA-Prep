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

/**
 * @brief Detects whether a cycle exists in a given undirected graph using BFS.
 *
 * This solution uses Breadth-First Search (BFS) with a parent tracking mechanism
 * to detect cycles. The algorithm handles graphs with multiple disconnected
 * components by initiating a BFS traversal from every unvisited vertex.
 *
 * @details
 * **Algorithm Steps:**
 * 1. Build an adjacency list representation of the graph from the given edges.
 * 2. Maintain a `visited` boolean array and a `parent` array (initialised to -1)
 *    to track explored nodes and the BFS tree parent.
 * 3. For each vertex `i` from `0` to `V-1`:
 *    - If `i` is not visited, start a BFS traversal with `i` as the starting node.
 *      Set its parent to `-1`.
 * 4. During BFS from a `currentNode`:
 *    - For each `neighbor` of `currentNode`:
 *      - If `neighbor` is not visited:
 *          - Mark it visited, set its parent to `currentNode`, and enqueue it.
 *      - Else if `neighbor` is already visited **and** it is **not** the parent
 *        of `currentNode`, then a back edge is found → cycle exists. Return `true`.
 * 5. If no back edge is found in any component, return `false`.
 *
 * @note The graph is undirected. The parent check ensures that the edge leading
 *       back to the immediate previous node in the BFS tree (parent) is ignored,
 *       as that is not a cycle.
 *
 * @param V      Number of vertices in the graph. (0 ≤ vertices < V)
 * @param edges  A 2D vector where each element `edges[i] = [u, v]` represents an
 *               undirected edge between vertex `u` and vertex `v`.
 *
 * @return `true`  if the graph contains at least one cycle,
 *         `false` otherwise.
 *
 * @par Complexity Analysis
 * - **Time Complexity:** O(V + E)
 *   Where `V` is the number of vertices and `E` is the number of edges.
 *   Every vertex is enqueued once and every edge is examined once (twice for
 *   undirected adjacency, but constant factor ignored).
 * - **Space Complexity:** O(V + E)
 *   - O(V + E) to store the adjacency list.
 *   - **Auxiliary Space:** O(V) for the `visited` array, `parent` array, and BFS queue.
 *
 * @par Examples
 * - Input: V = 4, edges = [[0, 1], [0, 2], [1, 2], [2, 3]]
 *   Output: `true` (Cycle: 1 → 2 → 0 → 1)
 * - Input: V = 4, edges = [[0, 1], [1, 2], [2, 3]]
 *   Output: `false` (No cycle)
 *
 * @par Constraints
 * - 1 ≤ V, E ≤ 10^5
 * - 0 ≤ edges[i][0], edges[i][1] < V
 *
 * @see https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
 */

#include <queue>
#include <vector>

class Solution {
private:
    /**
     * @brief Performs BFS from a given start node to detect a cycle in its component.
     *
     * @param startNode  The source vertex for this BFS traversal.
     * @param adjacency  Adjacency list representation of the graph.
     * @param isVisited  Boolean array marking visited vertices.
     * @param parentNode Array storing the parent of each vertex in the BFS tree.
     * @return `true` if a cycle is found in this component, otherwise `false`.
     */
    bool bfs(int startNode,
             const std::vector<std::vector<int>>& adjacency,
             std::vector<bool>& isVisited,
             std::vector<int>& parentNode) {

        std::queue<int> nodeQueue;

        // Initialise BFS for the start node
        nodeQueue.push(startNode);
        isVisited[startNode] = true;
        parentNode[startNode] = -1;   // root has no parent

        while (!nodeQueue.empty()) {
            int currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Explore all neighbours of the current node
            for (int neighbor : adjacency[currentNode]) {
                if (!isVisited[neighbor]) {
                    // New vertex discovered: mark visited, set parent, enqueue
                    isVisited[neighbor] = true;
                    parentNode[neighbor] = currentNode;
                    nodeQueue.push(neighbor);
                } else {
                    // Already visited: if it's not the parent, we have a back edge → cycle
                    if (parentNode[currentNode] != neighbor) {
                        return true;
                    }
                }
            }
        }

        return false;  // No cycle in this component
    }

public:
    /**
     * @brief Entry point to detect a cycle in the undirected graph.
     *
     * @param V      Number of vertices.
     * @param edges  List of undirected edges.
     * @return `true` if the graph contains a cycle, `false` otherwise.
     */
    bool isCycle(int V, const std::vector<std::vector<int>>& edges) {
        // Build adjacency list
        std::vector<std::vector<int>> adjacency(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjacency[u].push_back(v);
            adjacency[v].push_back(u);
        }

        // Tracking structures
        std::vector<bool> isVisited(V, false);
        std::vector<int> parentNode(V, -1);

        // Process every component
        for (int i = 0; i < V; ++i) {
            if (!isVisited[i]) {
                if (bfs(i, adjacency, isVisited, parentNode)) {
                    return true;
                }
            }
        }

        return false;  // No cycle anywhere
    }
};