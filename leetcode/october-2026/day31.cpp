// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/twisted-mirror-path-count/description/?envType=daily-question&envId=2026-10-31

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        vector<int> down(grid[0].size());  // ways to enter each cell from above
        down[0] = 1;
        for (auto& row : grid) {
            int right = 0;  // ways to enter the current cell from the left
            for (int j = 0; j < row.size(); j++) {
                if (row[j]) {  // a mirror swaps the flows
                    swap(right, down[j]);
                } else {  // an empty cell merges them
                    right = down[j] = (right + down[j]) % mod;
                }
            }
        }
        return down.back();
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();