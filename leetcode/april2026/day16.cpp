// Question Link : https://leetcode.com/problems/closest-equal-element-queries/?envType=daily-question&envId=2026-04-16

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> solveQueries(std::vector<int>& nums, std::vector<int>& queries) {
        int n = nums.size();
        std::unordered_map<int, std::vector<int>> mpp;

        for (int i = 0; i < n; ++i) {
            mpp[nums[i]].push_back(i);
        }

        std::vector<int> result;

        for (int queryIdx : queries) {
            int ele = nums[queryIdx];
            std::vector<int> &vec = mpp[ele];

            int size = vec.size();
            if (size == 1) {
                result.push_back(-1);
                continue;
            }

            int pos = std::lower_bound(begin(vec), end(vec), queryIdx) - begin(vec);
            int res = 1e9;

            // right neighbour
            int right = vec[(pos + 1) % size];
            int dist = abs(queryIdx - right);
            int circularDist = n - dist;
            res = std::min({res, dist, circularDist});

            // left neighbour
            int left = vec[(pos-1 + size) % size];
            dist = abs(queryIdx - left);
            circularDist = n - dist;
            res = std::min({res, dist, circularDist});

            result.push_back(res);
        }

        return result;
    }
};