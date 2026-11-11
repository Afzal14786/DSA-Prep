// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/minimum-cost-to-acquire-required-items/description/?envType=daily-question&envId=2026-11-11

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;
        long long pairs = min(n1, n2);
        long long costPairs = pairs * min(cb, c1 + c2);
        long long rem1 = n1 - pairs;
        long long rem2 = n2 - pairs;
        long long costRem = rem1 * min(c1, cb) + rem2 * min(c2, cb);
        return costPairs + costRem;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();