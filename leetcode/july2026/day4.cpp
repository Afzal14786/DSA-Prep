/**
 * @brief Finds the minimum possible score of a path between city 1 and city n.
 *
 * @details
 * We have n cities numbered 1..n and a set of bidirectional roads, each with a
 * positive distance. The score of a path is defined as the minimum edge distance
 * along that path. We are allowed to revisit cities and roads any number of times.
 * The goal is to find the path with the **maximum possible minimum edge**,
 * which is equivalent to finding the **minimum score** among all paths from 1 to n.
 *
 * **Key Observation:**
 * Since we can repeat roads and cities, the set of reachable edges from city 1
 * (in the connected component containing city 1) is exactly the set of edges we
 * can use in some path to city n. Because the graph is undirected, any road
 * reachable from 1 can be included in a walk from 1 to n (by going there and back).
 * Therefore, the minimum score of a path from 1 to n equals the **minimum edge
 * weight in the entire connected component of city 1**.
 *
 * **Why:** The component of city 1 contains all edges that are reachable via
 * some walk. Since walks can repeat edges, we can traverse to the smallest‑edge
 * in the component and then go to n, so the path score will be that minimum edge.
 * Thus the answer is simply the minimum distance among all edges in the component
 * that contains node 1.
 *
 * **Approach:**
 * 1. Build an adjacency list of the graph (undirected).
 * 2. Run DFS (or BFS) starting from city 1 to traverse all nodes in its component.
 * 3. While traversing, keep track of the minimum edge distance encountered.
 * 4. Return that minimum value.
 *
 * **Why DFS works:**
 * - We only need to visit the component of node 1, because node n is guaranteed
 *   to be in the same component (there is at least one path).
 * - By exploring all reachable roads, we are sure to see every edge in that component.
 *
 * @param n      Number of cities (nodes numbered 1..n).
 * @param roads  Vector of roads, each road = [u, v, dist] (bidirectional).
 * @return int   The minimum possible score of a path from 1 to n.
 *
 * @par Complexity
 * - **Time:** O(V + E) where V = n, E = roads.size().
 *   Each node and edge is visited once during DFS.
 * - **Auxiliary Space:** O(V + E) for adjacency list + O(V) for visited + recursion stack.
 *
 * @par Examples
 * - Example 1:
 *   n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
 *   Output: 5 (minimum edge in component = 5 from 2-4)
 *
 * - Example 2:
 *   n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
 *   Output: 2 (minimum edge = 2 from 1-2)
 *
 * @company Google
 * @see https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

class Solution {
private:
    /**
     * @brief DFS to traverse the component of a starting node and find the minimum edge.
     *
     * @param node       Current node being visited.
     * @param adj        Adjacency list of the graph.
     * @param visited    Boolean array marking visited nodes.
     * @param minEdge    Reference to the current minimum edge found so far.
     */
    void dfsTraverse(int node,
                     const std::unordered_map<int, std::vector<std::pair<int, int>>>& adj,
                     std::vector<bool>& visited,
                     int& minEdge) {
        visited[node] = true;

        for (const auto& [neighbor, distance] : adj.at(node)) {
            // Update the minimum edge distance
            minEdge = std::min(minEdge, distance);

            // Recurse if neighbor not visited
            if (!visited[neighbor]) {
                dfsTraverse(neighbor, adj, visited, minEdge);
            }
        }
    }

public:
    int minScore(int n, const std::vector<std::vector<int>>& roads) {
        // Build adjacency list (undirected graph)
        std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
        for (const auto& road : roads) {
            int u = road[0], v = road[1], dist = road[2];
            adj[u].emplace_back(v, dist);
            adj[v].emplace_back(u, dist);
        }

        std::vector<bool> visited(n + 1, false);  // 1‑based indexing
        int minimumEdge = INT_MAX;

        // DFS from city 1
        dfsTraverse(1, adj, visited, minimumEdge);

        return minimumEdge;
    }
};

#include <queue>

class Solution {
public:
    /**
     * @brief Computes the minimum possible score of a path from city 1 to city n.
     *        The score is the minimum edge distance along the path.
     *        Since roads can be reused, the answer is simply the minimum edge
     *        weight in the connected component of city 1.
     *
     * @param n      Number of cities (1‑based indexing).
     * @param roads  Vector of roads, each as [u, v, dist].
     * @return int   Minimum edge distance in the component of city 1.
     */
    int minScore(int n, const std::vector<std::vector<int>>& roads) {
        // Build adjacency list: for each city, store {neighbor, distance}
        std::unordered_map<int, std::vector<std::pair<int, int>>> adjacencyList;

        // Populate adjacency list with bidirectional edges
        for (const auto& road : roads) {
            int cityU = road[0];
            int cityV = road[1];
            int distance = road[2];

            adjacencyList[cityU].emplace_back(cityV, distance);
            adjacencyList[cityV].emplace_back(cityU, distance);
        }

        // visited array for BFS; size n+1 because cities are 1-indexed
        std::vector<bool> visited(n + 1, false);

        // Queue for Breadth‑First Search starting from city 1
        std::queue<int> bfsQueue;

        // Start BFS from city 1
        bfsQueue.push(1);
        visited[1] = true;

        // Variable to store the minimum edge distance found in the component
        int minimumEdge = INT_MAX;

        // BFS loop: explore all reachable cities in the component of 1
        while (!bfsQueue.empty()) {
            int currentCity = bfsQueue.front();
            bfsQueue.pop();

            // Examine all roads from current city
            for (const auto& [neighborCity, edgeDistance] : adjacencyList[currentCity]) {
                // Update the minimum edge distance among all encountered edges
                minimumEdge = std::min(minimumEdge, edgeDistance);

                // If neighbor not visited, mark and push for further exploration
                if (!visited[neighborCity]) {
                    visited[neighborCity] = true;
                    bfsQueue.push(neighborCity);
                }
            }
        }

        // The minimum edge in the entire component of city 1 is the answer
        return minimumEdge;
    }
};