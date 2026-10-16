// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/?envType=daily-question&envId=2026-10-16

#include <bits/stdc++.h>
using namespace std;

/**
 * brute force solution
 * @time complexity : O(n^2)
 * @space complexity : O(n)
 * 
 * @details but this will solution will give us TLE because the constraints are :
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 */
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> st;
            for (int j = i; j < n; ++j) {
                st.insert(nums[j]);
                int distince = st.size();
                res += distince * distince;
            }
        }
        return res;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();