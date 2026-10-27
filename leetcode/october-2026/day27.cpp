// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/create-grid-with-exactly-one-path/?envType=daily-question&envId=2026-10-27

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        return grid;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();