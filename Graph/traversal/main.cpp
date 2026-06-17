#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include "traversal.hpp"
#include "transforming_matrix_into_edgelist.hpp"

void showGraph(std::vector<std::vector<int>> &graph) {
    std::cout << "\n This is how the dense graph look like. \n";
    for (auto mat : graph) {
        for (auto x : mat) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Define an unweighted, directed graph using an adjacency list.
    // Index map: 0 = Node A, 1 = Node B, 2 = Node C, 3 = Node D, 4 = Node E
    int totalNodes = 50;
    
    // Density factor of 10 means each node connects to the next 10 consecutive nodes.
    // This will generate around 400+ edges for 50 nodes.
    int densityFactor = 10; 

    std::vector<std::vector<int>> graph = transform_matrix_into_edgelist::generateDenseGraph(totalNodes, densityFactor);
    
    std::cout << "--- Starting BFS Traversal ---" << std::endl;

    // Define the start vertex (Node 0)
    int startNode = 10;

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

    std::cout << "\n\n ---------------------------------------------------------------- \n\n";
    std::cout << "--- Starting DFS Traversal ---" << std::endl;
    auto startTime_dfs = std::chrono::high_resolution_clock::now();

    try {
        GraphUtils::depthFirstSearch(graph, startNode, [](int node) {
            std::cout << "Visited Node: " << node << std::endl;
        });
    } catch (const std::exception& e) {
        std::cerr << "Error during DFS: " << e.what() << std::endl;
        return 1;
    }

    auto endTime_dfs = std::chrono::high_resolution_clock::now();
    auto duration_dfs = std::chrono::duration_cast<std::chrono::microseconds>(endTime_dfs - startTime_dfs);
    std::cout << "--- DFS Traversal Complete ---" << std::endl;
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
