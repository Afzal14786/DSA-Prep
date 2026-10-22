// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/description/?envType=daily-question&envId=2026-10-22

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                p = i;
                break;
            }
        }

        bool inc = true, dec = true;
        for (int i = 0; i < n; i++) {
            int next = nums[(i + 1) % n];
            if (next != (nums[i] + 1) % n) inc = false;
            if (next != (nums[i] - 1 + n) % n) dec = false;
        }

        int ans = INT_MAX;
        if (inc) ans = min(ans, min(p, n - p + 2));
        if (dec) ans = min(ans, min(p + 2, n - p));
        return ans == INT_MAX ? -1 : ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();