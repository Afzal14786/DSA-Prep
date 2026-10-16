// Question Link : https://leetcode.com/problems/possible-bipartition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bfs_traversal(int node, unordered_map<int, vector<int>> &adjList, vector<int> &color) {
        queue<int> que;

        que.push(node);  // push the initial node into the queue
        color[node] = 0;  // let the first node into the green(0) group

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            // now process it's neighbour
            for (int v : adjList[u]) {
                // if both belongs to the same group
                if (color[v] == color[u]) return false;
                // both the nodes are different group
                if (color[v] == -1) {
                    que.push(v);
                    color[v] = 1 - color[u];  // put this into a different group - RED(1)
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // build the adjGraph
        unordered_map<int, vector<int>> adjList;

        for (const auto edge : dislikes) {
            int u = edge[0];
            int v = edge[1];

            // both hate each other so ~ bidirectional
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // now color array help to split them into two different group
        vector<int> color(n+1, -1);

        // the graph can be disconnected so;
        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1) {
                if (!bfs_traversal(i, adjList, color)) return false;
            }
        }

        return true;
    }
};


