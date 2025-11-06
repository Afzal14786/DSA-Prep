// You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).

// These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.

// Initially, all stations are online (operational).

// You are also given a 2D array queries, where each query is one of the following two types:

//     [1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.

//     [2, x]: Station x goes offline (i.e., it becomes non-operational).

// Return an array of integers representing the results of each query of type [1, x] in the order they appear.

// Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking it offline does not alter connectivity.

 

// Example 1:

// Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]

// Output: [3,2,3]

// Explanation:

//     Initially, all stations {1, 2, 3, 4, 5} are online and form a single power grid.
//     Query [1,3]: Station 3 is online, so the maintenance check is resolved by station 3.
//     Query [2,1]: Station 1 goes offline. The remaining online stations are {2, 3, 4, 5}.
//     Query [1,1]: Station 1 is offline, so the check is resolved by the operational station with the smallest id among {2, 3, 4, 5}, which is station 2.
//     Query [2,2]: Station 2 goes offline. The remaining online stations are {3, 4, 5}.
//     Query [1,2]: Station 2 is offline, so the check is resolved by the operational station with the smallest id among {3, 4, 5}, which is station 3.

// Example 2:

// Input: c = 3, connections = [], queries = [[1,1],[2,1],[1,1]]

// Output: [1,-1]

// Explanation:

//     There are no connections, so each station is its own isolated grid.
//     Query [1,1]: Station 1 is online in its isolated grid, so the maintenance check is resolved by station 1.
//     Query [2,1]: Station 1 goes offline.
//     Query [1,1]: Station 1 is offline and there are no other stations in its grid, so the result is -1.

 

// Constraints:

//     1 <= c <= 105
//     0 <= n == connections.length <= min(105, c * (c - 1) / 2)
//     connections[i].length == 2
//     1 <= ui, vi <= c
//     ui != vi
//     1 <= queries.length <= 2 * 105
//     queries[i].length == 2
//     queries[i][0] is either 1 or 2.
//     1 <= queries[i][1] <= c


#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    vector<priority_queue<int, vector<int>, greater<int>>> onlineStations;
    vector<bool> online;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                // Merge priority queues
                while (!onlineStations[rootX].empty()) {
                    onlineStations[rootY].push(onlineStations[rootX].top());
                    onlineStations[rootX].pop();
                }
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                while (!onlineStations[rootY].empty()) {
                    onlineStations[rootX].push(onlineStations[rootY].top());
                    onlineStations[rootY].pop();
                }
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                while (!onlineStations[rootY].empty()) {
                    onlineStations[rootX].push(onlineStations[rootY].top());
                    onlineStations[rootY].pop();
                }
            }
        }
    }
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c + 1);
        rank.resize(c + 1, 0);
        onlineStations.resize(c + 1);
        online.resize(c + 1, true);
        
        // Initialize
        for (int i = 1; i <= c; i++) {
            parent[i] = i;
            onlineStations[i].push(i);
        }
        
        // Build connections
        for (auto& conn : connections) {
            unite(conn[0], conn[1]);
        }
        
        vector<int> result;
        
        for (auto& query : queries) {
            int type = query[0];
            int x = query[1];
            
            if (type == 1) { // Maintenance check
                if (online[x]) {
                    result.push_back(x);
                } else {
                    int root = find(x);
                    // Clean up the priority queue - remove offline stations from top
                    while (!onlineStations[root].empty() && !online[onlineStations[root].top()]) {
                        onlineStations[root].pop();
                    }
                    if (onlineStations[root].empty()) {
                        result.push_back(-1);
                    } else {
                        result.push_back(onlineStations[root].top());
                    }
                }
            } else { // type == 2, station goes offline
                online[x] = false;
                // The priority queue will handle this naturally when we query
            }
        }
        
        return result;
    }
};