// Question Link : https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adjList, int curr, int parent, vector<int> &result, vector<int> &count, string &label) {
        char curr_label = label[curr];
        int before = count[curr_label - 'a'];
        count[curr_label - 'a'] += 1;

        // now processing the nodes
        for (int &child : adjList[curr]) {
            if (child == parent) continue;
            dfs(adjList, child, curr, result, count, label);
        }

        int after = count[curr_label - 'a'];
        result[curr] = after - before;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adjList;
        for (const auto edge : edges) {
            int u = edge[0], v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> ans(n, 0);
        vector<int> count(26, 0);
        dfs(adjList, 0, -1, ans, count, labels);
        return ans;
    }
};
