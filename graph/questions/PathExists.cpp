/**
 * Problem: Find if Path Exists in Graph
 * -------------------------------------------------
 * Given n vertices (0 to n-1) and a list of undirected edges,
 * determine if there is a valid path from source to destination.
 *
 * Approach: Depth-First Search (Recursive)
 * -----------------------------------------
 * We build an adjacency list from the edges, then perform DFS from the source.
 * If we reach the destination, we return true. We mark visited nodes to avoid cycles.
 * If DFS exhausts all reachable nodes without finding destination, return false.
 *
 * Time Complexity  : O(n + e), where n = vertices, e = edges.
 *                    Each vertex and edge is processed once.
 * Space Complexity : O(n + e) for adjacency list, plus O(n) for recursion stack in worst case.
 *
 * @see https://leetcode.com/problems/find-if-path-exists-in-graph/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    /**
     * Recursive DFS to check if destination is reachable from current node.
     * @param currentNode      The vertex we are currently at.
     * @param destination      The target vertex.
     * @param adjacencyList    Map from vertex to its neighbors.
     * @param visited          Boolean array marking visited vertices.
     * @return true if destination is reachable, false otherwise.
     */
    bool depthFirstSearch(int currentNode, int destination,
                          std::unordered_map<int, std::vector<int>>& adjacencyList,
                          std::vector<bool>& visited) {
        // Base case: if we reached the destination, path exists.
        if (currentNode == destination) return true;

        // Mark the current node as visited to avoid revisiting.
        visited[currentNode] = true;

        // Explore all neighbors of the current node.
        for (int neighbor : adjacencyList[currentNode]) {
            // If neighbor is not visited, recurse into it.
            if (!visited[neighbor]) {
                // If any recursive call returns true, propagate true.
                if (depthFirstSearch(neighbor, destination, adjacencyList, visited)) {
                    return true;
                }
            }
        }

        // No path found from this node; backtrack.
        return false;
    }

    /**
     * Main function to check if a valid path exists.
     * @param n             Number of vertices.
     * @param edges         Vector of undirected edges [u, v].
     * @param source        Starting vertex.
     * @param destination   Target vertex.
     * @return true if path exists, false otherwise.
     */
    bool validPath(int n, std::vector<std::vector<int>>& edges,
                   int source, int destination) {
        // Build adjacency list from edges.
        std::unordered_map<int, std::vector<int>> adjacencyList;
        for (const auto& edge : edges) {
            int vertexU = edge[0];
            int vertexV = edge[1];
            adjacencyList[vertexU].push_back(vertexV);
            adjacencyList[vertexV].push_back(vertexU);   // undirected: add both directions
        }

        // Visited array to track explored nodes.
        std::vector<bool> visited(n, false);

        // Start DFS from the source.
        return depthFirstSearch(source, destination, adjacencyList, visited);
    }
};


/**
 *
 * Approach: Breadth-First Search (Iterative)
 * --------------------------------------------
 * We build an adjacency list from the edges, then perform BFS from the source.
 * BFS explores level by level; if we encounter the destination, we return true.
 * If BFS finishes without finding destination, return false.
 * BFS is efficient for shortest path but here we only need existence.
 *
 * Time Complexity  : O(n + e), where n = vertices, e = edges.
 *                    Each vertex and edge is processed once.
 * Space Complexity : O(n + e) for adjacency list, plus O(n) for the queue in worst case.
 *
 * @see https://leetcode.com/problems/find-if-path-exists-in-graph/
 */

#include <queue>

class Solution {
public:
    /**
     * Main function to check if a valid path exists using BFS.
     * @param n             Number of vertices.
     * @param edges         Vector of undirected edges [u, v].
     * @param source        Starting vertex.
     * @param destination   Target vertex.
     * @return true if path exists, false otherwise.
     */
    bool validPath(int n, std::vector<std::vector<int>>& edges,
                   int source, int destination) {
        // Trivial case: source is the destination.
        if (source == destination) return true;

        // Build adjacency list from edges.
        std::unordered_map<int, std::vector<int>> adjacencyList;
        for (const auto& edge : edges) {
            int vertexU = edge[0];
            int vertexV = edge[1];
            adjacencyList[vertexU].push_back(vertexV);
            adjacencyList[vertexV].push_back(vertexU);   // undirected graph
        }

        // Queue for BFS and visited array.
        std::queue<int> queue;
        std::vector<bool> visited(n, false);

        // Initialize BFS with the source.
        queue.push(source);
        visited[source] = true;

        // Process nodes level by level.
        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            // If we reached the destination, a path exists.
            if (currentNode == destination) return true;

            // Explore all neighbors of the current node.
            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;   // Mark as visited before enqueueing
                    queue.push(neighbor);
                }
            }
        }

        // BFS completed without reaching destination → no path.
        return false;
    }
};