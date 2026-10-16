// Question Link : https://leetcode.com/problems/sum-of-distances-in-tree/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> count;  // storage the count of sub-trees including child
    int root_result = 0;   // storing the initial sum 
    int N;  // global count

    int dfs_root(unordered_map<int, vector<int>> &adjList, int curr_node, int prev_node, int curr_depth) {
        int total_count = 1;
        root_result += curr_depth;

        // now processing the child nodes
        for (int &child : adjList[curr_node]) {
            if (child == prev_node) continue;

            total_count += dfs_root(adjList, child, curr_node, curr_depth + 1);
        }

        count[curr_node] = total_count;
        return total_count;
    }

    void dfs(unordered_map<int, vector<int>> &adjList, int parent_node, int prev_node, vector<int> &ans) {
        // process the child nodes
        for (int &child : adjList[parent_node]) {
            if (child == prev_node) continue;

            ans[child] = ans[parent_node] - count[child] + (N - count[child]);
            dfs(adjList, child, parent_node, ans);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        count.resize(n, 0);
        // creating adjList
        unordered_map<int, vector<int>> adjList;
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        root_result = 0;
        // now computing the root and fillup the count array
        dfs_root(adjList, 0, -1, 0);

        vector<int> result(n);
        result[0] = root_result;

        dfs(adjList, 0, -1, result);
        return result;
    }
};
