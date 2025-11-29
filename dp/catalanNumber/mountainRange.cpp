#include <iostream>
#include <vector>

using namespace std;

int mountainRanges(int n) {
    if (n == 0 || n == 1) return 1;
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
    int pairs = 5;
    cout << "No of mountain ranges : " << mountainRanges(pairs) << endl;
    return 0;
}