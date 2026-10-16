// Question Link : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        // convert into adjacency list
        vector<vector<int>> adjList(V);
        for (const auto &list : edges) {
            int u = list[0];
            int v = list[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        queue<int> q;
        vector<int> distance(V, -1);
        
        q.push(src);
        distance[src] = 0;

        // vector<int> path(V, -1);
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            
            for (int nei : adjList[node]) {
                if (distance[nei] == -1) {
                    distance[nei] = distance[node] + 1;
                    q.push(nei);
                }
            }
        }
        
        return distance;
    }
};

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 4}, {4, 5}, {2, 6}, {5, 6}, {6, 7}, {6, 8}, {7, 8}};
    int src = 0, V = 9;

    Solution s;
    vector<int> ans = s.shortestPath(V, edges, src);

    cout << "Shortest Path Is : ";
    for (const auto &p : ans) {
        cout << p << " ";
    }

    return 0;
}