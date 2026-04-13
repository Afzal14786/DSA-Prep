// Question Link : https://leetcode.com/problems/minimum-distance-to-the-target-element/description/?envType=daily-question&envId=2026-04-13

#include <iostream>
#include <vector>

class Solution {
public:
    int getMinDistance(std::vector<int>& nums, int target, int start) {
        int min_dist = 1e9;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) min_dist = std::min(min_dist, abs(i-start));
        }

        return min_dist;
    }
};


int main() {
    std::vector<int> nums = {1,1,1,1,1,1,1,1,1,1};
    int target = 1, start = 0;
    Solution s;

    std::cout << "[Minimum Distance] : " << s.getMinDistance(nums, target, start) << std::endl;
    return 0;
}