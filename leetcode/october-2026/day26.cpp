// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/?envType=daily-question&envId=2026-10-26

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        auto dfs = [&](auto&& self, int i, int j) -> long long {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
            long long sum = grid[i][j];
            grid[i][j] = 0;
            sum += self(self, i + 1, j);
            sum += self(self, i - 1, j);
            sum += self(self, i, j + 1);
            sum += self(self, i, j - 1);
            return sum;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long s = dfs(dfs, i, j);
                    if (s % k == 0) ++ans;
                }
            }
        }
        return ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();