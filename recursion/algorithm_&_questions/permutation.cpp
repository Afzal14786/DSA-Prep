// Question Link : https://leetcode.com/problems/permutations/

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    /**
     * Time Complexity : O(N! * N)
     * Space Complexity : O(N) + O(N)
     */
    void generatePermutations(std::vector<int> &nums, std::vector<bool> &mp, std::vector<int> &temp, std::vector<std::vector<int>> &ans) {
        int n = nums.size();
        if (temp.size() == n) ans.push_back(temp);
        for (int i = 0; i < n; ++i) {
            if (!mp[i]) {
                temp.push_back(nums[i]);
                mp[i] = true;
                generatePermutations(nums, mp, temp, ans);
                temp.pop_back();
                mp[i] = false;
            }
        }
    }

    /***
     * Better Solution With Better Space Complexity
     */

    void permutation(int idx, std::vector<int> &nums, std::vector<std::vector<int>> &ans) {
        int n = nums.size();
        if (idx == n) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < n; ++i) {
            std::swap(nums[idx], nums[i]);
            permutation(idx+1, nums, ans);
            std::swap(nums[idx], nums[i]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        // std::vector<bool> mp(nums.size()+1, false);
        std::vector<std::vector<int>> ans;
        // std::vector<int> tmp;
        // generatePermutations(nums, mp, tmp, ans);
        /**
         * In this solution we don't required two extra arrays . So space optimize 
         */
        permutation(0, nums, ans);
        return ans;
    }
};
