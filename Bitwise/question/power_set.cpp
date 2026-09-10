// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total_subsets = 1 << n;

        vector<vector<int>> ans;
        for (int num = 0; num <= total_subsets - 1; num++) {
            vector<int> temp;
            for (int i = 0; i <= n-1; ++i) {
                if (num & (1 << i)) temp.push_back(nums[i]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
