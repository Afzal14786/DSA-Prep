// Question Link : https://leetcode.com/problems/subsets-ii/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void generateAllSubsetsWithDuplicates(int idx, std::vector<int> &nums, std::set<std::vector<int>> &ans, std::vector<int> &temp) {
        int n = nums.size();
        if (n == idx) {
            ans.insert(temp);
            return;
        }

        temp.push_back(nums[idx]);
        generateAllSubsetsWithDuplicates(idx+1, nums, ans, temp);
        temp.pop_back();

        generateAllSubsetsWithDuplicates(idx+1, nums, ans, temp);
    }
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::set<std::vector<int>> ans;
        std::vector<int> tmp;

        generateAllSubsetsWithDuplicates(0, nums, ans, tmp);
        return std::vector<std::vector<int>>(ans.begin(), ans.end());
    }
};