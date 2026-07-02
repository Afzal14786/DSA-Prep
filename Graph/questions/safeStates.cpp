/**
 * @brief Finds all safe nodes in a directed graph.
 *
 * A node is **safe** if every path starting from it eventually reaches a terminal
 * node (a node with no outgoing edges). Nodes that lie on a cycle or lead to a
 * cycle are **unsafe** and are excluded from the result.
 *
 * @details
 * **Approach:**
 * We use Depth‑First Search with a **3‑state coloring** to detect cycles and
 * determine which nodes are safe.
 *
 * - `0` = unvisited
 * - `1` = visiting (currently in the recursion stack)
 * - `2` = safe (confirmed to lead only to terminal nodes)
 *
 * **Algorithm Steps:**
 * 1. Build an adjacency list from the given directed edges.
 * 2. Initialise `state` array with `0` for all vertices.
 * 3. For each vertex `i` from `0` to `V-1`:
 *    - If `state[i] == 0`, run DFS from `i`.
 * 4. The DFS function `isSafeNode(node)`:
 *    - Mark `state[node] = 1` (visiting).
 *    - For each neighbour `nbr`:
 *      - If `state[nbr] == 0`, recursively call `isSafeNode(nbr)`.  
 *        If it returns `false`, the neighbour is unsafe → current node is unsafe → return `false`.
 *      - Else if `state[nbr] == 1`, a cycle is detected → current node is unsafe → return `false`.
 *      - Else (`state[nbr] == 2`), the neighbour is safe; continue.
 *    - If all neighbours are safe, mark `state[node] = 2` and return `true`.
 * 5. After all DFS calls, nodes with `state == 2` are safe; collect them in
 *    ascending order (which is natural as we iterate `i` from `0` to `V-1`).
 *
 * @note The graph is directed. Terminal nodes (no outgoing edges) are inherently
 *       safe because there are no paths to cycles.
 *
 * @param V      Number of vertices (0 … V-1).
 * @param edges  Vector of directed edges, each `[u, v]` means `u -> v`.
 *
 * @return A vector containing all safe node indices in ascending order.
 *
 * @par Complexity
 * - **Time:** O(V + E) – each vertex and edge is processed once.
 * - **Auxiliary Space:** O(V) for the state array and recursion stack (worst‑case
 *   recursion depth O(V)); the adjacency list uses O(V + E).
 *
 * @par Examples
 * - Input: `V = 5, edges = [[1,0],[1,2],[1,3],[1,4],[2,3],[3,4]]`  
 *   Output: `[0,1,2,3,4]` (all nodes reach a terminal; 0 and 4 are terminals).
 *
 * - Input: `V = 4, edges = [[1,2],[2,3],[3,2]]`  
 *   Output: `[0]` (only node 0 is safe; 1,2,3 form a cycle).
 *
 * @see https://www.geeksforgeeks.org/problems/eventual-safe-states/1               GFG
 * @see https://leetcode.com/problems/find-eventual-safe-states/description/        Leetcode
 */

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * @brief Determines whether a node is safe (does not lead to a cycle).
     *
     * @param node  Current vertex.
     * @param adj   Adjacency list of the graph.
     * @param state 3‑state array (0=unvisited, 1=visiting, 2=safe).
     * @return true  if the node is safe,
     *         false otherwise.
     */
    bool isSafeNode(int node, std::vector<std::vector<int>>& adj, std::vector<int>& state) {
        state[node] = 1; // visiting

        for (int neighbor : adj[node]) {
            if (state[neighbor] == 0) {
                if (!isSafeNode(neighbor, adj, state)) {
                    return false; // neighbor leads to a cycle → current is unsafe
                }
            } else if (state[neighbor] == 1) {
                return false; // cycle detected
            }
            // state[neighbor] == 2 → safe, continue
        }

        state[node] = 2; // mark as safe
        return true;
    }

    /**
     * @brief Returns all safe nodes in the graph.
     *
     * @param V      Number of vertices.
     * @param edges  Directed edges.
     * @return std::vector<int>  Sorted list of safe node indices.
     */
    std::vector<int> safeNodes(int V, std::vector<std::vector<int>>& edges) {
        // Build directed adjacency list
        std::vector<std::vector<int>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // 0 = unvisited, 1 = visiting, 2 = safe
        std::vector<int> state(V, 0);

        // Run DFS from every unvisited node
        for (int i = 0; i < V; ++i) {
            if (state[i] == 0) {
                isSafeNode(i, adj, state);
            }
        }

        // Collect all nodes marked as safe (state == 2)
        std::vector<int> safeNodes;
        for (int i = 0; i < V; ++i) {
            if (state[i] == 2) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

/**
 * @brief Finds all nodes that are eventually safe in a directed graph.
 *
 * A node is **safe** if every path starting from it eventually reaches a
 * terminal node (a node with no outgoing edges). Nodes that can reach a cycle
 * are **unsafe** and excluded from the result.
 *
 * @details
 * We use DFS with a **3‑state colouring** to detect cycles and identify safe nodes:
 * - `0` = unvisited
 * - `1` = visiting (currently in the recursion stack)
 * - `2` = safe (proven to lead only to terminal nodes)
 *
 * **Algorithm:**
 * 1. `graph` is already given as an adjacency list: `graph[u]` contains all `v` such that `u -> v`.
 * 2. Maintain a `state` array for all vertices.
 * 3. For each unvisited vertex, run `dfsSafe(node)`:
 *    - Mark `state[node] = 1`.
 *    - For each neighbour `nbr`:
 *      - If `state[nbr] == 0`, recursively call `dfsSafe(nbr)`.  
 *        If it returns `false`, the neighbour is unsafe → current is unsafe → return `false`.
 *      - Else if `state[nbr] == 1`, a cycle is found → current is unsafe → return `false`.
 *      - Else (`state[nbr] == 2`), neighbour is safe, continue.
 *    - After processing all neighbours, mark `state[node] = 2` and return `true`.
 * 4. After all DFS calls, nodes with `state == 2` are safe; collect them in ascending order.
 *
 * **Why it works:**  
 * This is a standard cycle‑detection in a directed graph. Nodes that are not part
 * of any cycle and do not lead to a cycle are marked safe.
 *
 * @param graph  Adjacency list representing a directed graph.
 *               `graph[i]` is a vector of outgoing neighbours from node `i`.
 *
 * @return A vector containing all safe node indices in ascending order.
 *
 * @par Complexity
 * - **Time:** O(V + E) – each vertex and edge is processed once.
 * - **Auxiliary Space:** O(V) for the `state` array and recursion stack (depth up to V).
 *
 * @par Examples
 * - Input: `graph = [[1,2],[2,3],[5],[0],[5],[],[]]`  
 *   Output: `[2,4,5,6]` (nodes 2,4,5,6 are safe; 0,1,3 lead to cycles)
 *
 * - Input: `graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]`  
 *   Output: `[4]` (only node 4 is terminal and safe; others can reach a cycle)
 *
 * @see https://leetcode.com/problems/find-eventual-safe-states/description/
 */


class Solution {
private:
    /**
     * @brief DFS to determine if a node is safe.
     *
     * @param node   Current vertex.
     * @param graph  Adjacency list of the graph.
     * @param state  3‑state array (0=unvisited, 1=visiting, 2=safe).
     * @return true  if the node is safe (does not lead to a cycle),
     *         false otherwise.
     */
    bool dfsSafe(int node, const std::vector<std::vector<int>>& graph, std::vector<int>& state) {
        state[node] = 1;  // mark as visiting

        for (int neighbour : graph[node]) {
            if (state[neighbour] == 0) {
                // unvisited neighbour – recurse
                if (!dfsSafe(neighbour, graph, state)) {
                    return false;  // neighbour leads to cycle → current is unsafe
                }
            } else if (state[neighbour] == 1) {
                // neighbour is currently in the recursion stack → cycle detected
                return false;
            }
            // else (state == 2) → safe, continue
        }

        state[node] = 2;  // all neighbours safe → mark current as safe
        return true;
    }

public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
        int numNodes = graph.size();
        std::vector<int> state(numNodes, 0);  // 0: unvisited, 1: visiting, 2: safe

        // Run DFS from each unvisited node
        for (int node = 0; node < numNodes; ++node) {
            if (state[node] == 0) {
                dfsSafe(node, graph, state);
            }
        }

        // Collect all nodes that are marked safe
        std::vector<int> safeNodes;
        for (int node = 0; node < numNodes; ++node) {
            if (state[node] == 2) {
                safeNodes.push_back(node);
            }
        }
        return safeNodes;
    }
};