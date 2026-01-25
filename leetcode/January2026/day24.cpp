/**
 * Minimize Maximum Pair Sum In Array
 * Question Link : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2026-01-24
 * Solution Link : 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        vector<int> values;
        while (i < j) {
            values.push_back(nums[i] + nums[j]);
            i++;
            j--;
        }
        return *max_element(values.begin(), values.end());   
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,5,2,3};
    cout << "Maximum Pair Sum is : " << s.minPairSum(nums) << endl;  // 8
    return 0;
}