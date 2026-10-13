// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/?envType=daily-question&envId=2026-10-13


// Fast I/O block for LeetCode performance boost
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();

class Solution {
public:
    // TODO: Paste the specific LeetCode function declaration here (e.g., int twoSum(vector<int>& nums, int target))
    static long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; i++) {
            sq[i] = 1LL * nums[i] * nums[i];
        }
        sort(sq.rbegin(), sq.rend());
        long long ans = 0;
        int pos = (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            if (i < pos) ans += sq[i];
            else ans -= sq[i];
        }
        return ans;
    }
};
