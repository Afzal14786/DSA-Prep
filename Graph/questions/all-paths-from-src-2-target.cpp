// Question Link : https://leetcode.com/problems/all-paths-from-source-to-target/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& graph, int source, int target, vector<vector<int>> &ans, vector<int> &temp) {
        temp.push_back(source);
        if (source == target) ans.push_back(temp);

        for (int v : graph[source]) {
            dfs(graph, v, target, ans, temp);
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // graph already given in the form of adjacency list
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(graph, 0, n-1, ans, temp);
        return ans;
    }
};
