/**
 * @file reorder-routes.cpp
 * @brief Solution for LeetCode "Reorder Routes to Make All Paths Lead to the City Zero".
 * @see https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 * * Problem Statement:
 * There are n cities (0 to n-1) and n-1 directed roads forming a tree. 
 * We need to ensure that every city can reach city 0. To achieve this, 
 * we can reverse the direction of any road.
 * * Task: Return the minimum number of roads that must be reversed.
 */

#include <iostream>
#include <vector>

class Solution {
private:
    /**
     * @brief Depth-First Search traversal to count required edge reversals.
     * * We traverse outward from city 0. Because we want paths to point TOWARDS city 0,
     * any edge pointing AWAY from the current traversal path (forward edges) is facing 
     * the wrong direction and must be reversed.
     * * @param node The current city being visited.
     * @param forward_nbrs Adjacency list of original edges (pointing away).
     * @param backward_nbrs Adjacency list of reversed edges (pointing towards).
     * @param ans Reference to the accumulator for the number of reversals needed.
     * @param visited Boolean array to prevent cyclic or redundant traversals.
     */
    void dfs(int node, 
             const std::vector<std::vector<int>>& forward_nbrs, 
             const std::vector<std::vector<int>>& backward_nbrs, 
             int& ans, 
             std::vector<bool>& visited) {
        
        visited[node] = true;

        // Traverse edges pointing away from the current node.
        // Since we are moving outward from 0, these edges point away from 0.
        // Therefore, they need to be reversed to point towards 0.
        for (int nei : forward_nbrs[node]) {
            if (!visited[nei]) {
                ans++; // This edge faces the wrong way; increment reversal count.
                dfs(nei, forward_nbrs, backward_nbrs, ans, visited);
            }
        }

        // Traverse edges pointing towards the current node.
        // These edges naturally point back towards 0, so no reversal is needed.
        for (int nei : backward_nbrs[node]) {
            if (!visited[nei]) {
                dfs(nei, forward_nbrs, backward_nbrs, ans, visited);
            }
        }
    }

public:
    /**
     * @brief Calculates the minimum number of roads to reverse.
     * * @param n The total number of cities (0 to n-1).
     * @param connections 2D vector where connections[i] = [a, b] represents a directed road from a to b.
     * @return int The minimum number of edge reversals required.
     * * @complexity Time: O(n) - We visit every node and edge exactly once.
     * @complexity Space: O(n) - Used by adjacency lists and the DFS recursion stack.
     */
    int minReorder(int n, const std::vector<std::vector<int>>& connections) {
        // Initialize adjacency lists for original (forward) and artificial (backward) edges
        std::vector<std::vector<int>> forward_nbrs(n);
        std::vector<std::vector<int>> backward_nbrs(n);
        std::vector<bool> visited(n, false);

        // Build the graph
        for (const auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];

            forward_nbrs[u].push_back(v);  // Original road: u -> v
            backward_nbrs[v].push_back(u); // Artificial road: v -> u
        }

        int ans = 0;
        
        // Start DFS from the capital (city 0)
        dfs(0, forward_nbrs, backward_nbrs, ans, visited);
        
        return ans;
    }
};