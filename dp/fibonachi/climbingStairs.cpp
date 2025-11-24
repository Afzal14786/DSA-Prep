#include <iostream>
#include <vector>
using namespace std;

int ways(int n) {
    if (n == 0 || n == 1) return 1;

    return ways(n - 1) + ways(n - 2);
}

// memoization (top - down) approach

int waysMemo(int n, vector<int> &dp) {
    if (n == 0 || n == 1) return 1;
    if (dp[n] != -1) return dp[n];

    dp[n] = waysMemo(n-1, dp) + waysMemo(n-2, dp);

    return dp[n];
}

//  tabulation (bottom - up) approach
int waysTabu(int n) {
    vector<int> ans(n+1);
    ans[0] = 1;
    ans[1] = 1;

    for (int i = 2; i <= n; ++i) {
        ans[i] = ans[i-1] + ans[i-2];
    }

    return ans[n];
}

// we are allowed to take 1, 2, & 3 steps at a time, now with is the no of ways to reach nth stairs

int tabu(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}



int main() {
    int n = 4;
    vector<int> dp (n+1, -1);
    cout << "No of ways for " << n << " is with O(2^n) time complexity : " << ways(n) << endl;
    cout << "No of ways for " << n << " is with O(n) time complexity using memoization : " << waysMemo(n, dp) << endl;
    cout << "No of ways for " << n << " is : with O(n) time complexity using tabulation : " << waysTabu(n) << endl;

    // allowed to take 1, 2 & 3 step at a time
    cout << "The total no of ways are : " << tabu(n) << endl;
    return 0;
}