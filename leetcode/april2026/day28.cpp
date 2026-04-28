// Question Link : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/?envType=daily-question&envId=2026-04-28

#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int minOperations(std::vector<std::vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        std::vector<int> vec;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vec.push_back(grid[i][j]);
            }
        }

        std::sort(vec.begin(), vec.end());

        int target = vec[vec.size() / 2];

        int ans = 0;
        for (int &num : vec) {
            if (target % x != num % x) return -1;
            ans += abs(target - num) / x;
        }

        return ans;
    }
};