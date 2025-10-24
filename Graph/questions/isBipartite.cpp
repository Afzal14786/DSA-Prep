#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

// leetcode question link: https://leetcode.com/problems/is-graph-bipartite/



class Solution {
    bool helper(vector<vector<int>> &graph, int source, vector<int> &color) {
        queue<int> q;
        q.push(source);
        color[source] = 0;      // starting color is blue

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbour : graph[curr]) {
                if (color[neighbour] == -1) {
                    // assign the color 
                    color[neighbour] = !color[curr];
                    q.push(neighbour);
                } else if (color[neighbour] == color[curr]) return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i< n; ++i) {
            if (color[i] == -1) {
                if (!helper(graph, i, color)) return false;
            }
        }

        return true;
    }
};