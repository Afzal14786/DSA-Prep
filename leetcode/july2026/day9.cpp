// Question Link : https://leetcode.com/problems/path-existence-queries-in-a-graph-i/?envType=daily-question&envId=2026-07-09

// رَّبِّ زِدْنِي عِلْمًا

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(unordered_map<int, vector<int>> &adjList, int src, int dest, vector<bool> &visited) {
        if (src == dest) {
            return true;
        }
        
        visited[src] = true;

        // if not then process the child
        for (int nbr : adjList[src]) {
            if (!visited[nbr]) {
                if (dfs(adjList, nbr, dest, visited)) return true;
            }
        }

        return false;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        unordered_map<int, vector<int>> adjList;
        
        // graph is created
        for (int i = 0; i < n-1; ++i) {
            if (abs(nums[i] - nums[i+1]) <= maxDiff) {
                adjList[i].push_back(i+1);
                adjList[i+1].push_back(i);
            }
        }

        // now process the each query as source and destination and findout the path exisit or not 

        int querySize = queries.size();

        vector<bool> result(querySize, false);

        for (int i = 0; i < querySize; ++i) {
            int src = queries[i][0], dest = queries[i][1];
            // now process the DFS 
            vector<bool> visited(n, false);
            result[i] = dfs(adjList, src, dest, visited);
        }

        return result;
    }
};

/**
 * Optimization
 */

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n);
        for (int i = 1; i < n; ++i) {
            component[i] = component[i-1] + (nums[i] - nums[i-1] > maxDiff);
        }

        vector<bool> result;

        for (const auto query : queries) {
            result.push_back(component[query[0]] == component[query[1]]);
        }

        return result;
    }
};