// Question Link https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int DFS(unordered_map<int, vector<int>> &adjList, int current, int parent, vector<bool>& hasApple) {
        int time = 0;
        for (int child : adjList[current]) {
            if (child == parent) continue;
            int time_from_child = DFS(adjList, child, current, hasApple);
            if (time_from_child > 0 || hasApple[child]) time += time_from_child + 2;
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adjList;
        for (const auto edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // adjList, starting node, parent_of_node, hasApple
        return DFS(adjList, 0, -1, hasApple);
    }
};
