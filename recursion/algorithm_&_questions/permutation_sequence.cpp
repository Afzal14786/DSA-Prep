// Question Link : https://leetcode.com/problems/permutation-sequence/
// Question Link : https://www.geeksforgeeks.org/problems/find-kth-permutation-0932/1
// Question Link : https://www.naukri.com/code360/problems/k-th-permutation-sequence_1112626?leftPanelTabValue=PROBLEM

#include <iostream>
#include <vector>
#include <string>


/**
 * This solution give up time limit exceed
 */
class Solution {
public:
    void permutation(int idx, std::vector<int> &nums, std::vector<std::string> &ans, int k) {
        int n = nums.size();

        if (ans.size() == k) return;
        if (idx == n) {
            std::string s = "";
            for (int x : nums) {
                s += std::to_string(x);
            }
            ans.push_back(s);
            return;
        }

        for (int i = idx; i < n; ++i) {
            int temp = nums[i];
            nums.erase(nums.begin() + i);
            nums.insert(nums.begin() + idx, temp);
            permutation(idx+1, nums, ans, k);

            nums.erase(nums.begin() + idx);
            nums.insert(nums.begin() + i, temp);
        }
    }

    std::string getPermutation(int n, int k) {
        // std::vector<int> nums;
        // for (int i = 1; i <= n; ++i) {
        //     nums.push_back(i);
        // }
        // std::vector<std::string> ans;
        // permutation(0, nums, ans, k);
        // return ans[k-1];

        /**
         * Better and optimize solution
         * Time Compexity : O(N^2)
         * Space Complexity : O(N) + Answer
         */

        std::vector<int> numbers;
        int fact = 1; // calculate the factorial initially from 1 to n-1
        for (int i = 1; i < n; ++i) {
            fact *= i;
            numbers.push_back(i);
        }
        // now at last push_back the n into number
        numbers.push_back(n);
        k--; // reduse k by 1 because we are dealing with 0-based indexing ...

        std::string ans = "";

        while (true) {
            // now put the number into answer
            ans += std::to_string(numbers[k/fact]);
            // now erase that number 
            numbers.erase(numbers.begin() + k/fact);
            if (numbers.size() == 0) break;
            // again now calculate factorial for new number because we just removed one value from number 

            k %= fact;  // calculate the k for the next set of numbers
            fact /= numbers.size();  // calculate the factorial for the next set
        }

        return ans;
    }
};