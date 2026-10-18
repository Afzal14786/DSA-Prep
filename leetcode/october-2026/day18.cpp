// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/?envType=daily-question&envId=2026-10-18

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9 + 7;
    vector<vector<ll>> pascle_trangle;
    int solve(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) return 1;

        vector<int> left_arr, right_arr;
        int root = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root)
                left_arr.push_back(nums[i]);
            else
                right_arr.push_back(nums[i]);
        }

        ll x = solve(left_arr) % MOD;
        ll y = solve(right_arr) % MOD;

        ll z = pascle_trangle[n-1][left_arr.size()];

        return (((x * y) % MOD) * z) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pascle_trangle.resize(n+1);
        for (int i = 0; i <= n; ++i) {
            pascle_trangle[i] = vector<ll>(i+1, 1);
            for (int j = 1; j < i; ++j) {
                pascle_trangle[i][j] = (pascle_trangle[i-1][j-1] + pascle_trangle[i-1][j]) % MOD;
            }
        }

        return solve(nums) - 1;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();