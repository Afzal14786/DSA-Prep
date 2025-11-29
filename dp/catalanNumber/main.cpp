#include <iostream>
#include <vector>

using namespace std;

// recursive -- catalan number

int catalan(int n) {
    if (n == 0 || n == 1) return 1;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += catalan(i) * catalan(n-i-1);
    }

    return ans;
}

// Memoization
int catalanMemo(int n, vector<int> &dp) {
    if (n == 0 || n == 1) return 1;
    if (dp[n] != -1) return dp[n];

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += catalanMemo(i, dp) * catalanMemo(n-i-1, dp);
    }

    return dp[n] = ans;
}

// catalan tabulation

int catalanTabu(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main() {
    int n = 4;
    vector<int> dp(n+1, -1);
    cout << "Catalan Number Of Given N is : " << catalan(n) << endl;
    cout << "Catalan Number Of Given N Using Memoization is : " << catalanMemo(n, dp) << endl;
    cout << "Catalan Number Of Given N Using Tabulation is : " << catalanTabu(n) << endl;
    return 0;
}