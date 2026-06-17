#pragma once

#include <vector>
#include <queue>
#include <functional>
#include <stdexcept>

namespace GraphUtils {
    /**
     * @brief Performs a Breadth-First Search (BFS) on a graph.
     * 
     * @tparam GraphType Type of the adjacency list (e.g., std::vector<std::vector<int>>)
     * @param graph The input graph representation.
     * @param startNode The index of the node where the search begins.
     * @param onVisit A callback function executed when a node is visited.
     */

    template <typename GraphType>
    void breadthFirstSearch(const GraphType& graph, int startNode, const std::function<void(int)>& onVisit) {
        // if graph is empty then simply return
        if (graph.empty()) return;

        if (startNode < 0 || startNode >= static_cast<int>(graph.size())) {
            throw std::out_of_range("Start node is out of graph boundaries.");
        }

        size_t numNodes = graph.size();
        std::vector<bool> visited(numNodes, false);  // for tracking the visited nodes
        std::queue<int> searchQueue;


        // initially we are visiting the node
        visited[startNode] = true;
        searchQueue.push(startNode);

        while (!searchQueue.empty()) {
            // take out the current node form the queue and popped it out
            int currentNode = searchQueue.front();
            searchQueue.pop();

            if (onVisit) {
                onVisit(currentNode);
            }


            for (const auto &neighbour : graph[currentNode]) {
                if (neighbour < 0 || neighbour >= static_cast<int>(numNodes)) {
                    throw std::runtime_error("Graph contains an invalid neighbour index.");
                }

                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    searchQueue.push(neighbour);
                }
            }
        }
    }

    /**
     * @brief Recursive utility for Depth-First Search.
     */
    template <typename GraphType>
    void dfs_util(const GraphType& graph, int currentNode, std::vector<bool>& visited, const std::function<void(int)>& onVisit) {
        visited[currentNode] = true;

        // Execute the callback if it was provided
        if (onVisit) {
            onVisit(currentNode);
        }

        // Iterate through all neighbors of the current node
        for (const auto& neighbour : graph[currentNode]) {
            if (!visited[neighbour]) {
                dfs_util(graph, neighbour, visited, onVisit);
            }
        }
    }
    
    /**
     * @brief Performs a Depth-First Search (DFS) on a graph.
     * * @tparam GraphType Type of the adjacency list (e.g., std::vector<std::vector<int>>)
     * @param graph The input graph representation.
     * @param startNode The index of the node where the search begins.
     * @param onVisit An optional callback function executed when a node is visited.
     */
    template <typename GraphType>
    void depthFirstSearch(const GraphType& graph, int startNode, const std::function<void(int)>& onVisit = nullptr) {
        if (graph.empty()) return;
        
        size_t sz = graph.size();
        
        // Safety check: ensure startNode is valid to prevent out-of-bounds crashes
        if (startNode < 0 || startNode >= sz) return;

        std::vector<bool> visited(sz, false);
        
        // Call the utility function
        dfs_util(graph, startNode, visited, onVisit);
    }
}