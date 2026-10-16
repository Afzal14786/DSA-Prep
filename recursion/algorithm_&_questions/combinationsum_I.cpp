/**
 * Combination Sum
 * Question Link : https://leetcode.com/problems/combination-sum/description/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    void findCombnation(int idx, int target, std::vector<int> &candidates, std::vector<int> &temp, std::vector<std::vector<int>> &ans) {
        int n = candidates.size();
        if (idx == n) {
            if (target == 0) ans.push_back(temp);
            return;
        }

        if (candidates[idx] <= target) {
            // we choose the element
            temp.push_back(candidates[idx]);
            findCombnation(idx, target-candidates[idx], candidates, temp, ans);
            temp.pop_back();
        }

        // we don't choose the elemment
        findCombnation(idx+1, target, candidates, temp, ans);
    }
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> temp;
        findCombnation(0, target, candidates, temp, ans);
        return ans;
    }
};


/**
 * Combination Sum II
 * Question Link : https://leetcode.com/problems/combination-sum-ii/description/
 * Here the different is : Each number in candidates may only be used once in the combination.
 */

class Solution {
public:
    void findCombination(int idx, int target, std::vector<int> &candidtes, std::vector<std::vector<int>> &ans, std::vector<int> &temp) {
        int n = candidtes.size();
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < n; ++i) {
            if (i > idx && candidtes[i] == candidtes[i-1]) continue;
            if (candidtes[i] > target) break;
            temp.push_back(candidtes[i]);
            findCombination(idx+1, target - candidtes[i], candidtes, ans, temp);
            temp.pop_back();
        }
    }
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> ans;
        std::vector<int> temp;

        findCombination(0, target, candidates, ans, temp);
        return ans;
    }
};

int main() {

    return 0;
}