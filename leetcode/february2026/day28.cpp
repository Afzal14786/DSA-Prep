// Question Link : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/?envType=daily-question&envId=2026-02-28

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    long long fast(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = (ans * 1LL * a) % mod;
            }

            a = (a * a) % mod;
            b = b >> 1;
        }

        return ans;
    }

    int solve(int n) {

        for (int i = 20; i >= 0; i--) {
            if ((1 << i) & n) {
                return i + 1;
            }
        }

        return -1;
    }
    int concatenatedBinary(int n) {

        long long int ans = n;
        int bits = solve(n);

        for (int i = n - 1; i >= 1; i--) {

            int val = fast(2LL, bits);
            ans = (ans + (i * 1LL * val) % mod) % mod;
            bits += solve(i);
        }

        return ans;
    }
};


class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0, len = 0, MOD = 1e9+7;
        for(int i = 1; i <= n; i++){
            if((i & (i-1)) == 0)len++;
            ans = ((ans << len) | i) % MOD;
        }
        return ans;
    }
};
