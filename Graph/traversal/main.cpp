#include <iostream>
#include <vector>
#include <chrono>
#include "traversal.hpp"

std::vector<std::vector<int>> generateDenseGraph(int numNodes, int densityFactor) {
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

int main() {
    // Define an unweighted, directed graph using an adjacency list.
    // Index map: 0 = Node A, 1 = Node B, 2 = Node C, 3 = Node D, 4 = Node E
    int totalNodes = 50;
    
    // Density factor of 10 means each node connects to the next 10 consecutive nodes.
    // This will generate around 400+ edges for 50 nodes.
    int densityFactor = 10; 

    std::vector<std::vector<int>> graph = generateDenseGraph(totalNodes, densityFactor);

    std::cout << "--- Starting BFS Traversal ---" << std::endl;

    // Define the start vertex (Node 0)
    int startNode = 0;

    auto startTime = std::chrono::high_resolution_clock::now();

    try {
        // Execute BFS and pass a lambda function to handle visited nodes
        GraphUtils::breadthFirstSearch(graph, startNode, [](int node) {
            std::cout << "Visited Node: " << node << std::endl;
        });
        
    } catch (const std::exception& e) {
        std::cerr << "Error during BFS: " << e.what() << std::endl;
        return 1;
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "--- Traversal Complete ---" << std::endl;
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
