#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// leetcode question link : https://leetcode.com/problems/find-if-path-exists-in-graph/


class Solution {
    bool dfs(int src, int dest, vector<vector<int>>& adj, vector<bool>& visited) {
        if (src == dest) return true;
        visited[src] = true;

        for (int neighbour : adj[src]) {
            if (!visited[neighbour]) {
                if (dfs(neighbour, dest, adj, visited)) return true;
            }
        }

        return false;
    }

    bool bfs(int src, int dest, vector<vector<int>> &adj, vector<bool> &visited) {
        if (src == dest) 
            return true;

        queue<int> q;
        q.push(src);    // push the source into the queue
        visited[src] = true;    // mark it as true

        while (!q.empty()) {
            int curr = q.front();  q.pop();
            if (curr == dest) return true;

            for (int neighbour : adj[curr]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

        return false;
        
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        // make the adjecency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return dfs(source, destination, adj, visited);
    }
};