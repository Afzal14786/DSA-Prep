// Question Link : https://leetcode.com/problems/permutations-ii/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


class Solution {
public:
    void permutation(int idx, std::vector<int> &nums, std::set<std::vector<int>> &ans) {
        int n = nums.size();
        if (idx == n) {
            ans.insert(nums);
            return;
        }

        for (int i = idx; i < n; ++i) {
            std::swap(nums[idx], nums[i]);
            permutation(idx+1, nums, ans);
            std::swap(nums[idx], nums[i]);
        }
    }
    
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> ans;
        permutation(0, nums, ans);
        return std::vector<std::vector<int>>(ans.begin(), ans.end());
    }
};

/**
 * 
 * 
 * Another solution
 */

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        std::vector<int> curr;
        std::vector<bool> used(nums.size(), false);
        
        backtrack(nums, used, curr, result);
        return result;
    }

private:
    void backtrack(std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& curr, std::vector<std::vector<int>>& result) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // check if the index is already used 

            // Skip duplicates: if curr is same as previous AND previous wasn't used
            // This forces a specific order for duplicate elements
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true; // mark the index or the value is used
            curr.push_back(nums[i]);
            
            backtrack(nums, used, curr, result);
            
            // Backtrack
            curr.pop_back();
            used[i] = false;
        }
    }
};