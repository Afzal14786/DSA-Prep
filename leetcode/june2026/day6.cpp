// Question Link : https://leetcode.com/problems/left-and-right-sum-differences/description/?envType=daily-question&envId=2026-06-06

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void printvector(const vector<int> &vec) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftSum(n), rightSum(n);
        leftSum[0] = 0, rightSum[n-1] = 0;  // this is ok
        
        for (int i = 1; i < n; ++i) {
            leftSum[i] = nums[i - 1] + leftSum[i-1];
        }

        for (int i = n-2; i >= 0; --i) {
            rightSum[i] = nums[i + 1] + rightSum[i+1];
        }

        // now calulating the answer // 

        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        
        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1};
    s.leftRightDifference(nums);
    return 0;
}