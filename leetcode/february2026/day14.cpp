// Question Link : https://leetcode.com/problems/champagne-tower/?envType=daily-question&envId=2026-02-14

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>dp(query_row+2,0.0);
        dp[0]=poured;
        for(int i=1;i<=query_row;i++){
            for(int j=i;j>=0;j--){
                dp[j+1] += dp[j] = max((dp[j]-1)/2,0.0);
            }
        }
        return min(dp[query_glass],1.0);
    }
};

class Solution {
public:
    double solve(int poured, int i, int j, vector<vector<double>> &t) {
        if (i < 0 || j < 0 || i < j) return 0.0;
        if (i == 0 && j == 0) return (double)poured;

        if (t[i][j] != -1.0) return t[i][j];

        double left_up = (solve(poured, i-1, j-1, t) - 1) / 2.0;
        double right_up = (solve(poured, i-1, j, t) - 1) / 2.0;
        if (left_up < 0) left_up = 0;
        if (right_up < 0) right_up = 0;

        return t[i][j] = left_up + right_up;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(101, vector<double>(101, -1.0));
        return min(1.0, solve(poured, query_row, query_glass, t));
    }
};
