// Question Link : https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = 0;

    int dfs(unordered_map<int, vector<int>> &adjList, int curr, int parent, string &s) {
        int longest = 0, second_longest = 0;
        // process the childs
        for (int &child : adjList[curr]) {
            if (child == parent) continue;
            int child_longest_path = dfs(adjList, child, curr, s);

            if (s[child] == s[curr]) continue;

            if (child_longest_path > second_longest) second_longest = child_longest_path;
            if (second_longest > longest) swap(longest, second_longest);
        }

        int at_root = 1;  // means the adjacent nodes having same characters
        int one_best = 1 + max(second_longest, longest);
        int ans_at_bottom = 1 + longest + second_longest;

        result = max({result, at_root, one_best, ans_at_bottom});
        return max(at_root, one_best);
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int, vector<int>> adjList;

        for (int i = 1; i < n; ++i) {
            int u = i;
            int v = parent[i];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        result = 0;

        dfs(adjList, 0, -1, s);
        return result;
    }
};
