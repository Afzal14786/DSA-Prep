// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * This is the day, I don't want to solve the leetcode of the day, but I am solving
 * I want to go to Delhi and Support `Sonam Wangchuk` & `CJP` Protest and take 
 * resignation of Dharmendra Pradhan and Buccher Of India `Narendra Damodar Das Modi`.
 * 
 * Today July 20, and I am in Mumbai, I don't want to be here, But unfortunately I am here.
 * 
 * Fuck You BJP -- Tumhara PAAP ka ghara bhar chuka hai.
 */

// Question Link : https://leetcode.com/problems/shift-2d-grid/description/?envType=daily-question&envId=2026-07-20

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (!k) return grid;
        int r = grid.size(), c = grid[0].size();
        int n = r * c;

        k = k % n;
        if (!k) return grid;

        auto shift = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / c][i % c], grid[j / c][j % c]);
                i++;
                j--;
            }
        };

        shift(0, n - 1);
        shift(0, k - 1);
        shift(k, n - 1);

        return grid;
    }
};