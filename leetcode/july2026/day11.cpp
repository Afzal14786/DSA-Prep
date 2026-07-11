// Question Link : https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2026-07-11

// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &adjList, int curr_node, vector<bool> &visited, int &node_count, int &edge_count) {
        visited[curr_node] = true;
        node_count++;
        edge_count += adjList[curr_node].size();

                // now process the childs
        for (int child : adjList[curr_node]) {
            if (!visited[child]) {
                dfs(adjList, child, visited, node_count, edge_count);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (const auto edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // now fds traversal
        vector<bool> visited(n, false);
        int component_count = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int node_count = 0;
                int edge_count = 0;
                dfs(adjList, i, visited, node_count, edge_count);

                if (edge_count == node_count * (node_count - 1)) component_count++;
            }
        }

        return component_count;
    }
};