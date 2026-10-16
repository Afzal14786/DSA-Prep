#pragma once

#include <vector>
#include <unordered_map>

namespace transform_matrix_into_edgelist {

    /**
     * @brief Transforms a 2D vector of edges into an adjacency list.
     * * This function takes a list of edges (where each inner vector contains a pair 
     * of connected nodes) and builds an undirected graph representation using a hash map.
     * * @param matrix A 2D vector where each element is a vector of two integers representing an edge [u, v].
     * @return std::unordered_map<int, std::vector<int>> The resulting adjacency list mapping each node to its neighbors.
     */
    inline std::unordered_map<int, std::vector<int>> transform(const std::vector<std::vector<int>>& matrix) {
        std::unordered_map<int, std::vector<int>> adjacencyList;
        
        // Use a range-based for loop for better safety and readability
        for (const auto& edge : matrix) {
            // Ensure the edge is well-formed before accessing to prevent out-of-bounds errors
            if (edge.size() >= 2) {
                int u = edge[0];
                int v = edge[1];
                
                // Add the connection for an undirected graph
                adjacencyList[u].push_back(v);
                adjacencyList[v].push_back(u);
            }
        }

        return adjacencyList;
    }

    inline std::vector<std::vector<int>> generateDenseGraph(int numNodes, int densityFactor) {
        std::vector<std::vector<int>> edgeList;
        
        // Step 1: Guarantee every node is connected (Creates a spanning path)
        // This ensures there are absolutely ZERO isolated nodes.
        for (int i = 1; i < numNodes; ++i) {
            edgeList.push_back({i, i + 1});
        }
        
        // Step 2: Add extra connections to make it dense.
        // densityFactor determines how many forward connections each node gets.
        // E.g., if densityFactor is 5, Node 1 connects to 3, 4, 5, and 6.
        for (int i = 1; i <= numNodes; ++i) {
            for (int step = 2; step <= densityFactor; ++step) {
                if (i + step <= numNodes) {
                    edgeList.push_back({i, i + step});
                }
            }
        }
        
        return edgeList;
    }

} // namespace transform_matrix_into_edgelist