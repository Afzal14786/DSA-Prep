// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/?envType=daily-question&envId=2026-08-21

#define ll long long int

class Solution {
public:

    ll count_less_than_equaltoo_X(vector<int> &coins, long long x) {
        int mid_x = coins.size();
        int all_ones = (1 << mid_x) - 1;
        ll count = 0;

        for (int mask = 1; mask <= all_ones; ++mask) {
            ll set_bits_lcm = 1;
            for (int j = 0; j < mid_x; ++j) {
                if (mask & (1 << j)) {
                    set_bits_lcm = lcm(set_bits_lcm, coins[j]);
                }
            }

            if (__builtin_popcount(mask) & 1) count += x / set_bits_lcm;
            else count -= x / set_bits_lcm;
        }

        return count;
    }

    ll findKthSmallest(vector<int>& coins, int k) {
        ll left = 0, right = 25 * 2 * 1e9 + 25, ans = 0;

        while (left <= right) {
            ll mid_x = left + (right - left) / 2;
            ll count = count_less_than_equaltoo_X(coins, mid_x);

            if (count < k) {
                left = mid_x + 1;
            } else {
                ans = mid_x;
                right = mid_x - 1;
            }
        }

        return ans;
    }
};