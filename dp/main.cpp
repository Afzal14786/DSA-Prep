#include <iostream>
#include <vector>

using namespace std;

// normal approach with O(2^n) time complexity
int fibo(int n) {
    if (n == 0 || n == 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}

// with dp -- memoization

int fin_memo(int n, vector<int> &dp) {
    if (n == 0 || n == 1) return n;
    if (dp[n] != -1) return dp[n];

    return dp[n] = fin_memo(n-1, dp) + fin_memo(n-2, dp);
}

// with dp -- using tebulation

int fibo2(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}


int main() {
    int n = 6;
    cout << "Ans : " << fibo2(n) << endl;
    return 0;
}