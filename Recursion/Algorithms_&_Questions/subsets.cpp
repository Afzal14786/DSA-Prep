// Question Link : https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    void generateSubsets(int idx, std::vector<int> &nums, std::set<std::vector<int>> &st, std::vector<int> &tmp) {
        int n = nums.size();
        if (n == idx) {
            st.insert(tmp);
            return;
        }

        tmp.push_back(nums[idx]);
        generateSubsets(idx+1, nums, st, tmp);
        tmp.pop_back();

        generateSubsets(idx+1, nums, st, tmp);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> st;
        std::vector<int> temp;
        generateSubsets(0, nums, st, temp);

        return std::vector<std::vector<int>>(st.begin(), st.end());
    }
};

