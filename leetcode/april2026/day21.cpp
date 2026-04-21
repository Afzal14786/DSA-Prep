// Question Link : https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/?envType=daily-question&envId=2026-04-21

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

class Solution {
public:
    std::vector<int> parent;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    int minimumHammingDistance(std::vector<int>& source, std::vector<int>& target, std::vector<std::vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);

        for (auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }

        // Group source values by their component root
        std::unordered_map<int, std::unordered_map<int, int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)][source[i]]++;
        }

        int hammingDist = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            auto& freq = groups[root];
            if (freq.count(target[i]) && freq[target[i]] > 0) {
                freq[target[i]]--;  // matched, consume this source value
            } else {
                hammingDist++;      // no match found in this component
            }
        }

        return hammingDist;
    }
};