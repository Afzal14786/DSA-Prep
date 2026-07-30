// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/?envType=daily-question&envId=2026-07-30

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if (n <= 8) return n;
        int sz = n/8;
        int rem = n % 8;
        int ans = 0;
        for (int i = 1; i <= sz; ++i) {
            ans += i * 8;
        }

        if (rem == 0) return ans;
        return (ans += (sz + 1) * rem);
    }
};
