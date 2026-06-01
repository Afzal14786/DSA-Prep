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
}