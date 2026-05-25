// Question Link : https://leetcode.com/problems/jump-game-vii/?envType=daily-question&envId=2026-05-25

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Recursion + Memoization
 */
class Solution {
public:
    bool solve(string s, int idx, int n, int minJump, int maxJump, vector<bool> &dp) {
        // base case 
        if (idx == n-1) return true;

        if (dp[idx]) return dp[idx];

        // now explore all the paths
        for (int jump = minJump; jump <= maxJump; ++jump) {
            int j = idx + jump;

            if (j >= n) break;
            if (s[j] == '0') {  // then only jump
                if (solve(s, j, n, minJump, maxJump, dp)) return dp[j] = true;
            }
        }

        return dp[idx] = false;
    }

    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        return solve(s, 0, n, minJump, maxJump, dp);
    }
};


class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);

        for (int i = n-2; i >= 0; --i) {
            for (int jump = minJump; jump <= maxJump; ++jump) {
                int j = i + jump;

                if (j >= n) return false;
                if (s[j] == '0') if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};


// optimal soluiton

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);

        dp[0] = true;
        int count = 0;
        for (int j = 1; j < n; ++j) {
            if (j - minJump >= 0) count += dp[j - minJump];
            if (j - maxJump - 1 >= 0) count -= dp[j - maxJump - 1];
            
            if (count > 0 && s[j] == '0') dp[j] = true;
        }

        return dp[n-1] > 0;
    }
};