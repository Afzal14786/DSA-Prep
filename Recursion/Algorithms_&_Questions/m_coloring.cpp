// Question Link : https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1


#include <iostream>
#include <vector>

class Solution {
  public:
    bool isSafe(int node, std::vector<std::vector<int>> &adj, std::vector<int> &colors, int col) {
        for (auto neighbor : adj[node]) {
            if (colors[neighbor] == col) return false;
        }
        
        return true;
    }

    bool solve(int node, int v, std::vector<std::vector<int>> &adj, int m, std::vector<int> &colors) {
        if (node == v) return true;

        for (int i = 1; i <= m; ++i) {
            if (isSafe(node, adj, colors, i)) {
                colors[node] = i;
                if (solve(node + 1, v, adj, m, colors)) return true;
                colors[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(int v, std::vector<std::vector<int>>& edges, int m) {
        // 1. Build Adjacency List
        std::vector<std::vector<int>> adj(v);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // 2. Initialize colors and solve
        std::vector<int> colors(v, 0);
        return solve(0, v, adj, m, colors);
    }
};
