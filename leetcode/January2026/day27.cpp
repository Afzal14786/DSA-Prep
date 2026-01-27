/**
 * Question Link : https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=2026-01-27
 * Solution Link : https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/submissions/1898514779/?envType=daily-question&envId=2026-01-27
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2*wt});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> res(n, INT_MAX);
        res[0] = 0;
        pq.push({0,0});
        while(!pq.empty()) {
            int curr_dist = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            if (curr_node == n-1) return res[n-1];
            for (auto &neighbour : adj[curr_node]) {
                int adjNode = neighbour.first;
                int dist = neighbour.second;

                if (curr_dist + dist < res[adjNode]) {
                    res[adjNode] = curr_dist + dist;
                    pq.push({curr_dist + dist, adjNode});
                }
            }
        }

        return -1;
    }
};