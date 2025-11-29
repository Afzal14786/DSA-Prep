#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int mcm(vector<int> mat, int i, int j) {
    if (i == j) return 0;
    int ans = INT_MAX;

    for (int k = i; k < j; ++k) {
        int cost1 = mcm(mat, i, k);
        int cost2 = mcm(mat, k+1, j);

        int currCost = cost1 + cost2 + (mat[i-1] * mat[k] * mat[j]);
        ans = min(ans, currCost);
    }

    return ans;
}

// memoization

int mcm_Memo(vector<int> chain, int i, int j, vector<vector<int>> &dp) {
    if (i == j) return 0;
    int ans = INT_MAX;

    if (dp[i][j] != -1) return dp[i][j];

    for (int k = i; k < j; ++k) {
        int cost1 = mcm_Memo(chain, i, k, dp);
        int cost2 = mcm_Memo(chain, k+1, j, dp);
        int currCost = cost1 + cost2 + (chain[i-1] * chain[k] * chain[j]);

        ans = min(ans, currCost);
    }

    return dp[i][j] = ans;
}

// tabulation 

int mcm_Tabulation(vector<int> chain) {
    int n = chain.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // diagional
    // for (int i = 1; i < n; ++i) {
    //     dp[i][i] = 0;
    // }

    for (int len = 2; len < n; ++len) {
        for (int i = 1; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + (chain[i-1] * chain[k] * chain[j]);

                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    cout << "\n The Resultant Matrix : \n";
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[1][n-1];
}

int main() {
    vector<int> nums = {1,2,3,4,3};
    int n = nums.size();
    cout << "Total Cost = " << mcm(nums, 1, n-1) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Total Minimum Cost Using Memoization : " << mcm_Memo(nums, 1, n-1, dp) << endl;    
    cout << "Total Minimum Cost Using Tabulation : " << mcm_Tabulation(nums) << endl;
    return 0;
}