/**
 * @brief Finds the maximum possible minimum edge cost along any valid path from
 *        node 0 to node n-1 in a directed acyclic graph, subject to:
 *        - all intermediate nodes must be online,
 *        - total recovery cost ≤ k.
 *
 * @details
 * The graph has n nodes (0 … n-1) and m directed edges, each with a cost.
 * Nodes 0 and n-1 are guaranteed online. A path is valid if:
 * - every intermediate node is online,
 * - sum of edge costs ≤ k.
 * The score of a path is the minimum edge cost on that path.
 * We want the maximum score among all valid paths, or -1 if none exists.
 *
 * **Solution Approach:**
 * This is a **maximise‑the‑minimum** problem, solvable with **binary search**
 * on the score threshold `mid`.
 *
 * 1. Build a directed adjacency list **only for edges whose both endpoints are online**.
 * 2. Binary search over the range of possible scores (minimum and maximum edge costs).
 * 3. For a candidate score `mid`, we check if there exists a valid path where
 *    every edge has cost ≥ `mid` and total cost ≤ `k`.
 * 4. The feasibility check uses **Dijkstra's algorithm**:
 *    - Run shortest‑path (by total cost) from 0 to n-1.
 *    - During relaxation, only consider edges with `cost ≥ mid`.
 *    - Stop early if the shortest distance to target exceeds `k` (no feasible path).
 * 5. If feasible, try a higher `mid`; else lower it.
 *
 * **Why this works:**
 * - The property is monotonic: if a path exists with all edges ≥ `X`, then it also
 *   exists for any lower threshold.
 * - Dijkstra gives the minimum total cost under the edge‑filter constraint,
 *   so we can accurately check if total cost ≤ `k`.
 *
 * @param edges  Vector of directed edges: [u, v, cost] (u -> v).
 * @param online Boolean array indicating which nodes are online.
 * @param k      Maximum allowed total recovery cost.
 *
 * @return The maximum possible path score, or -1 if no valid path exists.
 *
 * @par Complexity
 * - **Time:** O(m log V * log(maxCost – minCost))
 *   - Binary search over score range: O(log C), where C ≈ 1e9.
 *   - Each Dijkstra run: O((V + E) log V) – using a priority queue.
 *   - Overall: O((V + E) log V * log C), which is acceptable for the given limits.
 * - **Auxiliary Space:** O(V + E) for adjacency list and Dijkstra arrays.
 *
 * @par Examples
 * - Example 1:
 *   edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]], online = [T,T,T,T], k = 10
 *   → Output: 3 (path 0→2→3 has min edge 3, total 7 ≤ 10)
 *
 * - Example 2:
 *   edges = [[0,1,7],[1,4,5],[0,2,6],[2,3,6],[3,4,2],[2,4,6]],
 *   online = [T,T,T,F,T], k = 12
 *   → Output: 6 (path 0→2→4 has min edge 6, total 12 ≤ 12)
 *
 * @see https://leetcode.com/problems/network-recovery-pathways/?envType=daily-question&envId=2026-07-03
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using ll = long long;
    using Edge = pair<int, int>;          // {neighbour, cost}
    using State = pair<ll, int>;          // {totalCost, node}

    /**
     * @brief Checks if there exists a path from 0 to n-1 such that:
     *        - each edge cost ≥ `minEdgeCost`
     *        - total path cost ≤ `k`
     *
     * @param minEdgeCost  Lower bound on each edge in the path.
     * @param n            Number of nodes.
     * @param k            Maximum allowed total cost.
     * @param adj          Adjacency list (only online nodes included).
     * @return true if such a path exists, false otherwise.
     */
    bool isFeasible(int minEdgeCost, int n, ll k, const vector<vector<Edge>>& adj) {
        const ll INF = 1e18;
        vector<ll> dist(n, INF);
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currentDist, node] = pq.top();
            pq.pop();

            // If the cheapest path to any node already exceeds k, no route to target can be ≤ k
            if (currentDist > k) return false;

            // Early exit if we reached the target
            if (node == n - 1) return true;

            // Skip outdated entries
            if (currentDist != dist[node]) continue;

            // Explore neighbours
            for (const auto& [neighbour, cost] : adj[node]) {
                // Only consider edges with cost >= minEdgeCost
                if (cost < minEdgeCost) continue;

                ll newDist = currentDist + cost;
                if (newDist < dist[neighbour]) {
                    dist[neighbour] = newDist;
                    pq.push({newDist, neighbour});
                }
            }
        }

        // If we exit the loop, target was never reached within cost limit
        return false;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        // Build adjacency list for only online nodes
        vector<vector<Edge>> adj(n);
        int minCost = INT_MAX;
        int maxCost = 0;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            // Both endpoints must be online to use this edge
            if (!online[u] || !online[v]) continue;

            adj[u].push_back({v, cost});
            minCost = min(minCost, cost);
            maxCost = max(maxCost, cost);
        }

        // No valid edges → no path possible (except if n==1? but n>=2)
        if (adj[0].empty()) return -1;

        // Binary search over possible minimum edge cost
        int low = minCost, high = maxCost;
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isFeasible(mid, n, k, adj)) {
                answer = mid;
                low = mid + 1;          // try higher score
            } else {
                high = mid - 1;         // try lower score
            }
        }

        return answer;
    }
};