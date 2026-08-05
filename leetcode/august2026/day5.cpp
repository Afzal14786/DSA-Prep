
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/remove-methods-from-project/?envType=daily-question&envId=2026-08-05

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // first forms a graph
        vector<vector<int>> graph(n);
        vector<int> in_degree(n);
        vector<bool> suspecious(n, false);

        for (auto &inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            graph[u].push_back(v);
            in_degree[v]++;
        }

        queue<int> que;
        que.push(k);
        suspecious[k] = true;

        while (!que.empty()) {
            int curr = que.front();
            que.pop();

            for (int &ngbr : graph[curr]) {
                in_degree[ngbr]--;
                if (!suspecious[ngbr]) {
                    suspecious[ngbr] = true;
                    que.push(ngbr);
                }
            }
        }

        vector<int> ans;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (suspecious[i] && in_degree[i] > 0) {
                ok = true;
                break;
            }

            if (!suspecious[i]) ans.push_back(i);
        }

        if (ok) {
            vector<int> vec(n);
            for (int i = 0; i < n; ++i) vec[i] = i;
            return vec;
        }

        return ans;
    }
};
