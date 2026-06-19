/**
 * @brief Computes the shortest paths from a single source vertex to all other vertices in a weighted graph.
 * * @details 
 * Dijkstra's Algorithm is a greedy, single-source shortest path (SSSP) algorithm. It works by 
 * iteratively selecting the unvisited vertex with the smallest tentative distance from the source, 
 * visiting it, and relaxing all of its outgoing edges. 
 * * ### Implementation Details
 * To achieve optimal performance, this algorithm relies on specific data structures to retrieve 
 * the next minimum-distance vertex efficiently:
 * - **Min-Priority Queue (Min-Heap)**: The most common approach. It stores pairs of `(current_distance, vertex)` 
 * to quickly fetch the unvisited node with the smallest distance.
 * - **Set (e.g., `std::set` in C++)**: An alternative to a priority queue that keeps elements sorted and 
 * allows for updating shortest path values by erasing and re-inserting nodes.
 * * @warning 
 * **Constraint on Edge Weights**: This algorithm strictly requires all edge weights to be non-negative 
 * (weight >= 0). 
 * If a graph contains negative edge weights, Dijkstra's algorithm may produce incorrect results. 
 * This is because the algorithm's core assumption (the greedy choice property) dictates that once a 
 * vertex is extracted from the queue, its shortest path is finalized. Negative weights break this assumption. 
 * (Note: Use the Bellman-Ford algorithm for graphs with negative weights).
 * * @param source     The starting vertex from which to calculate the shortest paths.
 * @param graph      The adjacency list representation of the graph, containing target vertices and edge weights.
 * @param distances  A reference to a collection (e.g., vector or array) where the computed shortest 
 * distances from the source to each vertex will be stored.
 * * @pre The graph must not contain any negative edge weights.
 * * @complexity
 * - **Time Complexity**: O(E * log V), where 'E' is the total number of edges and 'V' is the total 
 * number of vertices. This assumes the use of a Min-Priority Queue/Binary Heap and an Adjacency List.
 * - **Space Complexity**: O(V + E) to store the graph (Adjacency List) and O(V) for the priority 
 * queue and distance array.
 */

// Practice Question Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <iostream>
#include <vector>
#include <queue>
#include <set>

class Solution {
  public:
    std::vector<int> dijkstra(int V, std::vector<std::vector<int>> &graph, int src) {
        // Code here

        // constructing the adjacency list contains the {node, weight}
        std::vector<std::vector<std::pair<int, int>>> adj(V); 
        for (const auto &edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            adj[u].push_back({v, weight});   // {node, weight}
            adj[v].push_back({u, weight});
        }
        // required data structure
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        //  reference to a collection (e.g., vector or array) where the computed shortest 
        std::vector<int> distances(V, 1e9);

        // distance of the source is always 0
        distances[src] = 0;
        pq.push({0, src});  // {distance, node}

        while (!pq.empty()) {
            auto [curr_dist, u] = pq.top();
            pq.pop();

            if (curr_dist > distances[u]) continue;

            // now process the neighbours
            for (const auto &neighbour : adj[u]) {
                int v = neighbour.first;  // node
                int weight = neighbour.second;  // distance

                if (weight + curr_dist < distances[v]) {
                    distances[v] = weight + curr_dist;
                    pq.push({distances[v], v});
                }
            }
        }

        return distances;
    }
};

/**
 * Implementaion using set data structure
 */

class Solution {
  public:
    std::vector<int> dijkstra(int V, std::vector<std::vector<int>> &graph, int src) {
        // Code here
        
        // constructing the adjacency list contains the {node, weight}
        std::vector<std::vector<std::pair<int, int>>> adj(V); 
        for (const auto &edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            adj[u].push_back({v, weight});   // {node, weight}
            adj[v].push_back({u, weight});
        }

        std::set<std::pair<int, int>> st;
        std::vector<int> distance(V, 1e9);

        st.insert({0, src});  // {distance, node}
        distance[src] = 0;

        while (!st.empty()) {
            auto it = st.begin();
            auto [curr_distance, u] = *it;
            st.erase(it);

            if (curr_distance > distance[u]) continue;

            // now process the neighbour nodes
            for (auto &neighbour : adj[u]) {
                int v = neighbour.first;
                int weight = neighbour.second;

                if (curr_distance + weight < distance[v]) {
                    if (distance[v] != 1e9) st.erase({distance[v], v});
                    distance[v] = weight + curr_distance;
                    st.insert({distance[v], v});
                }
            }
        }

        return distance;
    }
};