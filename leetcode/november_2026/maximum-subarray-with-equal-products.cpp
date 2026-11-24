// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/maximum-subarray-with-equal-products/description/?envType=daily-question&envId=2026-11-24

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int g = 0;
            long long lc = 1;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                if (g == 0) g = x;
                else {
                    int a = g, b = x;
                    while (b) {
                        int t = b;
                        b = a % b;
                        a = t;
                    }
                    g = a;
                }
                long long gg = lc;
                int b = x;
                while (b) {
                    long long t = b;
                    b = gg % b;
                    gg = t;
                }
                if (lc / gg > LLONG_MAX / x) break;
                lc = lc / gg * x;
                if (prod > LLONG_MAX / x) break;
                prod *= x;
                if (prod == lc * g) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();