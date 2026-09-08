// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/distinct-subsequences-ii/


class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(26, 0);
        
        for (char ch : s) {
            int idx = ch - 'a';
            long long total = 0;
            for (int i = 0; i < 26; i++) {
                total = (total + dp[i]) % MOD;
            }
            long long newCount = (total + 1) % MOD;
            dp[idx] = newCount;
        }
        
        long long result = 0;
        for (int i = 0; i < 26; i++) {
            result = (result + dp[i]) % MOD;
        }
        
        return (int)result;
    }
};