#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> Dijkstra(vector<vector<int>> &cost, int source) {
    int size = cost.size();
    
    // Initialize arrays
    vector<bool> selected(size, false);
    vector<int> distance(size, INT_MAX);  // Initialize all distances to infinity
    
    distance[source] = 0;  // Distance to source is 0

    for (int count = 0; count < size - 1; ++count) {
        // Find the vertex with minimum distance value
        int min = INT_MAX;
        int u = -1;
        
        for (int j = 0; j < size; ++j) {
            if (!selected[j] && distance[j] <= min) {
                min = distance[j];
                u = j;
            }
        }
        
        // If no vertex found, break
        if (u == -1) break;
        
        selected[u] = true;
        
        // Update distance values of adjacent vertices
        for (int v = 0; v < size; ++v) {
            // Check if vertex v is not selected, there's an edge from u to v,
            // and the new path through u is shorter
            if (!selected[v] && cost[u][v] != INT_MAX && 
                distance[u] != INT_MAX && 
                distance[u] + cost[u][v] < distance[v]) {
                distance[v] = distance[u] + cost[u][v];
            }
        }
    }
    
    return distance;
}

int main() {
    vector<vector<int>> cost = {
        {INT_MAX, 1, 5, INT_MAX, INT_MAX, INT_MAX},
        {1, INT_MAX, 3, 10, 8, INT_MAX},
        {5, 3, INT_MAX, INT_MAX, 2, INT_MAX},
        {INT_MAX, 10, INT_MAX, INT_MAX, 3, 2},
        {INT_MAX, 8, 2, 3, INT_MAX, 7},
        {INT_MAX, INT_MAX, INT_MAX, 2, 7, INT_MAX}
    };
    
    cout << "\n------------- Given Cost Matrix : -------------\n";
    for (int i = 0; i < cost.size(); i++) {
        for (int j = 0; j < cost[i].size(); j++) {
            if (cost[i][j] == INT_MAX) {
                cout << "INF\t";
            } else {
                cout << cost[i][j] << "\t";
            }
        }
        cout << endl;
    }
    
    // Dijkstra
    int source = 0;
    vector<int> distances = Dijkstra(cost, source);
    
    cout << "\n------------- Shortest distances from vertex " << source << " : -------------\n";
    for (int i = 0; i < distances.size(); i++) {
        if (distances[i] == INT_MAX) {
            cout << "Vertex " << i+1 << ": INF\n";
        } else {
            cout << "Vertex " << i+1 << ": " << distances[i] << "\n";
        }
    }
    
    return 0;
}