// Question Link : https://leetcode.com/problems/palindrome-partitioning-ii/
// Question Link : https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * this is the recursive solution
 */

class Recursive_Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string str, int i, int j) {
        if (i >= j || isPalindrome(str, i, j)) return 0;
        int ans = 1e9 + 7;

        for (int k = i; k < j; ++k) {
            int cost = solve(str, i, k) + solve(str, k+1, j) + 1;
            ans = min(ans, cost);
        }

        return ans;
    }

    int minCut(string s) {
        int i = 0, j = s.size()-1;
        return solve(s, i, j);
    }
};

/**
 * this is the memoization solution ...
 * 
 */

class Memoization {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string str, int i, vector<int> &dp) {
        int n = str.size();
        if (i == n) return 0;
        if(isPalindrome(str, i, n-1)) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = 1e9 + 7;

        for (int k = i; k < n; ++k) {
            if (isPalindrome(str, i, k)) {
                int cost = 1 + solve(str, k+1, dp);
                ans = min(cost, ans);
            } 
        }
        return dp[i] = ans; 
    }

    int minCut(string s) {
        int i = 0, n = s.size()-1;
        
        vector<int> dp(n+1, -1);
        return solve(s, i, dp);
    }
};

/**
 * This is top down approach solution
 */

class Solution0 {
public:
    bool isPalindrom(string str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;
        vector<int> dp(n+1, 0);

        dp[n] = 0;

        for (int i = n-1; i >= 0; --i) {
            if (isPalindrom(s, i, n-1)) {
                dp[i] = 0;
                continue;
            }

            int cuts = 1e9;
            for (int k = i; k < n; ++k) {
                if (isPalindrom(s, i, k)) {
                    int cost = 1 + dp[k+1];
                    cuts = min(cuts, cost);
                }
            }
            dp[i] = cuts;
        }

        return dp[0];
    }
};


class Solution1 {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int end = 0; end < n; end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] && (end - start <= 2 || isPal[start + 1][end - 1])) {
                    isPal[start][end] = true;
                }
            }
        }
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) dp[i] = 0;
            else {
                dp[i] = i;
                for (int j = 0; j < i; j++) {
                    if (isPal[j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};


class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        // pre calculation for checking palindrome 
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int mini = 1e9;

            for (int j = i; j < n; j++) {
                if (isPal[i][j]) {
                    mini = min(mini, 1 + dp[j + 1]);
                }
            }

            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};

// --------------------------------------------- Another Solution ----------------------------------------------------------------

void printDP(const vector<vector<int>> &dp) {
    cout << "After performing operation : \n";
    for (auto nums : dp) {
        for (auto x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
}

class GFG_Solution {
  public:
    bool isPalindrome(string str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string str, int i, int j, vector<vector<int>> &dp) {
        if (i >= j || isPalindrome(str, i, j)) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;

        for (int k = i; k < j; ++k) {
            int left = (dp[i][k] != -1) ? dp[i][k] : dp[i][k] = solve(str, i, k, dp);
            int right = (dp[k+1][j] != -1) ? dp[k+1][j] : dp[k+1][j] = solve(str, k+1, j, dp);
            int curr_cost = left + right + 1;

            ans = min(ans, curr_cost);
        }

        
        return dp[i][j] = ans;
    }

    int palPartition(string &str) {
        // code here
        int n = str.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solve(str, 0, n-1, dp);
        return ans;
    }
};

int main() {
    string str;
    cin >> str;

    Solution s;
    GFG_Solution gfg;
    cout << "Minimum Number Of Cuts Required : " << s.minCut(str) << endl;
    cout << "Minimum Number Of Cuts Required : " << gfg.palPartition(str) << endl;
    return 0;
}