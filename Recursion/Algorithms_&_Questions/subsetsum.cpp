// Question Link : https://www.naukri.com/code360/problems/subset-sum_3843086?interviewProblemRedirection=true&search=Subset%20Sum

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * TIME COMPLEXITY : O(N * 2 ^ N)
 * SPACE COMPLEXITY : O(2 ^ N)
 */

class SubsetSum {
public:
    // time complexity :  O(2 ^ N)
    void generateSubset(int idx, std::vector<int> &nums, int currSum, std::vector<int> &ans) {
        int n = nums.size();
        if (idx == n) {
            ans.push_back(currSum);
            return;
        }

        currSum += nums[idx];
        generateSubset(idx + 1, nums, currSum, ans);
        currSum -= nums[idx];

        generateSubset(idx + 1, nums, currSum, ans);
    }
    // over all time complexity :  O(2 ^ N) + O(N * 2^N) & 
    // Space Complexity : recursive call stack depth is O(N) & The ans vector stores 2^N subset sums, so space complexity for ans is O(2^N).
    std::vector<int> subsetSum(std::vector<int> &nums){
	    // Write your code here.
        std::vector<int> ans;
        generateSubset(0, nums, 0, ans);
        std::cout << "ans[] we got after function call : ";
        for (int x : ans) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
        std::sort(ans.begin(), ans.end());   // time complexity for sorting : O(N * 2^N)
        return ans;
    }
};

int main() {

    SubsetSum sum;
    std::vector<int> nums = {3,1,2};
    std::vector<int> ans = sum.subsetSum(nums);

    std::cout << "ans[] we got after function call from main : ";
        for (int x : ans) {
            std::cout << x << " ";
        }
    std::cout << std::endl;

    return 0;
}