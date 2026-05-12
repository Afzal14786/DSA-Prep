#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void print2D(const vector<vector<int>> &matrix) {
    for (auto &nums : matrix) {
        for (auto &x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
}

/**
 * this is the recursion solution it takes
 * time complexity : O(N^n)
 * space complexity : O(N) ~ Recursion Stack 
 */
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

/**
 * another way of memoization
 */

int mcm_Memo2(vector<int> &chain, int i, int j, vector<vector<int>> &dp) {
    if (i == j) {
        dp[i][j] = 0;
        return 0;
    }

    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 1e9 + 7;
    int cost = 0;
    for (int k = i; k < j; ++k) {
        dp[i][k] = mcm_Memo2(chain, i, k, dp);
        dp[k+1][j] = mcm_Memo2(chain, k+1, j, dp);
        cost = dp[i][k] + dp[k+1][j] + (chain[i-1] * chain[k] * chain[j]);

        dp[i][j] = min(dp[i][j], cost);
    }

    return dp[i][j];
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
    print2D(dp);

    return dp[1][n-1];
}

/**
 * we can also identify where exacly we parenthesis the chain such that we got minimum number of operations
 */

int parenthesis_generation(vector<int> &dimentions, int n) {

    if (n <= 1) return 0;
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1)), parenthesis(n+1, vector<int>(n+1, 0));

    // we know that when i == j the answer is 0
    for (int i = 0; i <= n; ++i) dp[i][i] = 0;      // fill diagonally 0

    for (int diff = 1; diff < n; ++diff) {
        for (int i = 1; i <= n - diff; ++i) {
            int j = i + diff;
            dp[i][j] = 1e9 + 7;
            int cost = 0;
            for (int k = i; k < j; ++k) {
                cost = dp[i][k] + dp[k+1][j] + dimentions[i-1] * dimentions[k] * dimentions[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    parenthesis[i][j] = k;
                }
            }
        }
    }

    cout << "\n\n Just Before Returning The Answer Here Is What Inside Matrices : \n\n";
    cout << "\n ----------------- Values Inside DP Matrix -----------------\n";
    print2D(dp);

    cout << "\n ----------------- Values Inside Parenthesis Matrix -----------------\n";
    print2D(parenthesis);

    // here we are returning the answer ..
    return dp[1][n];
}


int main() {
    vector<int> nums = {1,2,3,4,3};
    int n = nums.size();
    // cout << "Total Cost = " << mcm(nums, 1, n-1) << endl;

    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << "Total Minimum Cost Using Memoization : " << mcm_Memo(nums, 1, n-1, dp) << endl;
    // cout << "Total Minimum Cost Using Memoization 2 : " << mcm_Memo2(nums, 1, n-1, dp) << endl;  
    // cout << "Total Minimum Cost Using Tabulation : " << mcm_Tabulation(nums) << endl;

    // vector<vector<int>> parenthesis(n + 1, vector<int>(n+1, -1));
    cout << "Total Minimum Cost Using Tabulation 2 & also generate parenthesis matrix to identify where exactly we did : " << parenthesis_generation(nums, n-1) << endl;
    return 0;
}