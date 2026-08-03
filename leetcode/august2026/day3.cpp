// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/stone-game-iii/?envType=daily-question&envId=2026-08-03

// Bottom Up 
class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = stones[i] - dp[i+1];
            if (i + 2 <= n)
                dp[i] = max(dp[i], stones[i] + stones[i+1] - dp[i+2]);
            if (i + 3 <= n)
                dp[i] = max(dp[i], stones[i] + stones[i+1] + stones[i+2] - dp[i+3]);
        }

        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        }
        return "Tie";
    }
};

class Solution {
public:
    int n;
    vector<int> t;
    int solve(vector<int> &S, int idx) {
        if (idx >= n) return 0;
        if (t[idx] != -1) return t[idx];
        
        int res = S[idx] - solve(S, idx + 1);
        if (idx + 1 < n) {
            res = max(res, S[idx] + S[idx + 1] - solve(S, idx + 2));
        }

        if (idx + 2 < n) {
            res = max(res, S[idx] + S[idx + 1] + S[idx + 2] - solve(S, idx + 3));
        }

        return t[idx] = res;
    }

    string stoneGameIII(vector<int>& stones) {
        n = stones.size();
        t.resize(n+1, -1);

        int diff = solve(stones, 0);

        if (diff < 0) 
            return "Bob";
        else if (diff > 0) 
            return "Alice";
        
        return "Tie";
    }
};

// with constant space 
class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        int a = 0, b = 0, c = 0;

        for (int i = n - 1; i >= 0; --i) {
            int res = INT_MIN;
            res = max(res, stones[i] - a);
            if (i + 2 <= n)
                res = max(res, stones[i] + stones[i+1] - b);
            if (i + 3 <= n)
                res = max(res, stones[i] + stones[i+1] + stones[i+2] - c);
            
            c = b;
            b = a;
            a = res;
        }

        if (a < 0) return "Bob";
        else if (a > 0) return "Alice";
        return "Tie";
    }
};