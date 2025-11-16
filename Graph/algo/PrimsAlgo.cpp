#include <iostream>
#include <queue>
#include <vector>
#include <functional>

// question solution link : https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/1831208189/

typedef std::pair<int, int> P;
// in this algorithm we have to find the min cost to connect all the points
int PrismAlgo(std::vector<std::vector<int>> &points) {
    int V = points.size();
    std::priority_queue<P, std::vector<P>, std::greater<>> pq;
    std::vector<bool> MST(V, false);

    // start with (0,0) -> (weight, node)
    pq.push({0,0});

    int minCost = 0;

    while (!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if (MST[node]) continue;
        MST[node] = true;
        minCost += wt;

        for (int v = 0; v < V; ++v) {
            // calculate the distance here 
            if (node != v) {
                int x1 = points[node][0], y1 = points[node][1];
                int x2 = points[v][0], y2 = points[v][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                pq.push({dist, v});
            }
        }
    }

    return minCost;
}