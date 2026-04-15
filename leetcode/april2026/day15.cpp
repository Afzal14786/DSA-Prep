// Question Link : https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int closestTarget(std::vector<std::string>& words, std::string target, int startIndex) {
        int min_dist = 1e9;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            if (target == words[i]) {
                int dist = abs(i-startIndex);
                int circularDist = n-dist;

                min_dist = std::min(min_dist, std::min(dist, circularDist));
            }
        }
        return (min_dist == 1e9) ? -1 : min_dist;
    }
};