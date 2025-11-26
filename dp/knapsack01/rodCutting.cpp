#include <iostream>
#include <vector>

using namespace std;

int rodCuttingMaxProfit(vector<int> price, vector<int> length, int rodLength) {
    int n = length.size();
    if (n == 0 || rodLength == 0) return 0;

    vector<vector<int>> dp(n+1, vector<int>(rodLength+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= rodLength; ++j) {
            if (length[i-1] <= j) {
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][rodLength];
}


int minCost(int n, vector<int>& cuts) {

    int size = cuts.size();

    vector<vector<int>> dp(size+1, vector<int>(n+1, 0));

    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (cuts[i-1] <= j) {
                dp[i][j] = max(cuts[i-1] + dp[i][j-cuts[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << "Cutting The Stick Cost : \n";
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[size][n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    int rodLength = 8;

    cout << "Maximum Profit After Cutting The Rod & Selling It : " << rodCuttingMaxProfit(prices, length, rodLength) << endl;

    vector<int> cust = {1,3,4,5};
    int n = 7;
    cout << "Minimum Cost To Cut A Stick Is : " << minCost(n, cust) << endl;
    return 0;
}