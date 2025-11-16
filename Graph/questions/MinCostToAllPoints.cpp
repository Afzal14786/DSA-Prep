// leetcode submission link : https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/1831166099/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// there is two solution

// solution 1: 
// submission link : https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/1831193636/
class Solution {
public:
    // store the {wt, node}
    typedef pair<int, int > P;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<P, vector<P>, greater<>> pq;
        vector<bool> MST(V, false);

        int totalCost = 0;
        // we are starting with (0, 0)
        pq.push({0,0});

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (MST[node]) continue;

            MST[node] = true;
            totalCost += wt;

            for (int v = 0; v < V; ++v) {
                if (node != v) {
                    int x1 = points[node][0], y1 = points[node][1];
                    int x2 = points[v][0], y2 = points[v][1];

                    int dist = abs(x1 - x2) + abs(y1 - y2);

                    pq.push({dist, v});
                }
            }
        }

        return totalCost;
    }
};

// solution 2:
// submission link : https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/1831200639/

class Solution {
public:
    typedef pair<int, int> P;

    int PrismAlgo(vector<vector<P>> &adj, int V) {
        priority_queue<P, vector<P>, greater<>> pq;
        vector<bool> MST(V, false);
        int totalCost = 0;
        pq.push({0, 0});        // starting with zero

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (MST[node]) continue;

            MST[node] = true;
            totalCost += wt;

            for (auto &[neighbour_wt, neighbour_node] : adj[node]) {
                if (!MST[neighbour_node]) {
                    pq.push({neighbour_wt, neighbour_node});
                }
            }
        }

        return totalCost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<P>> adj(V);

        for (int i = 0; i < V; ++i) {
            for (int j = i+1; j < V; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        return PrismAlgo(adj, V);
    }
};