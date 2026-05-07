// Question Link : https://leetcode.com/problems/jump-game-ix/?envType=daily-question&envId=2026-05-07


#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> maxValue(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, 0);
        /** 
         * leftMax --> max elemet from index 0 to i
         * rightMin --> min element from index i+1 to n
         * */

        std::vector<int> leftMax(n, 0), rightMin(n, 0);
        leftMax[0] = nums[0];
        rightMin[n-1] = nums[n-1];

        // max left
        for (int i = 1; i < n; ++i) {
            leftMax[i] = std::max(leftMax[i-1], nums[i]);
        }

        // right min
        for (int i = n-2; i >= 0; --i) {
            rightMin[i] = std::min(rightMin[i+1], nums[i]);
        }

        ans[n-1] = leftMax[n-1];
        for (int i = n-2; i >= 0; --i) {
            if (leftMax[i] <= rightMin[i+1]) ans[i] = leftMax[i];
            else ans[i] = ans[i+1];
        }
        return ans;
    }
};
