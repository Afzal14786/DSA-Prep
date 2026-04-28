#include <iostream>
#include <vector>

using namespace std;

// time complexity : O(2^n)
int knapsackRec(vector<int> val, vector<int> wt, int W, int n) {
    if (n == 0 || W == 0) return 0;

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if (itemWt <= W) { // is it fisible
        // include
        int ans = knapsackRec(val, wt, W-itemWt, n-1) + itemVal;

        // excalude
        int ans2 = knapsackRec(val, wt, W, n-1);

        return max(ans, ans2);
    } else {
        return knapsackRec(val, wt, W, n-1);
    }
}

// time complexity is : O(n*W) which is similar to O(n^2)
int knapsackMemo(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>> &dp) {
    if (n == 0 || W == 0) return 0;

    if (dp[n][W] != -1) return dp[n][W];

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if (itemWt <= W) {
        int ans1 = knapsackMemo(val, wt, W-itemWt, n-1, dp) + itemVal;
        int ans2 = knapsackMemo(val, wt, W, n-1, dp);
        dp[n][W] = max(ans1, ans2);

    } else {
        dp[n][W] = knapsackMemo(val, wt, W, n-1, dp);
    }

    return dp[n][W];
}

// tabulation code 
int knapsackTabu(vector<int> val, vector<int> wt, int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < W+1; ++j) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if (itemWt <= j) dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}


int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};    
    int n = 5;
    int W = 7;

    cout << "The maximum profit is : " << knapsackRec(val, wt, W, n) << endl;

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    cout << "The maximum profit using memoization is : " << knapsackMemo(val, wt, W, n, dp) << endl;
    cout << "The Profit Matrix is : " << endl;
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Maximum Profit using tabulation : " << knapsackTabu(val, wt, W, n) << endl;

    return 0;
}