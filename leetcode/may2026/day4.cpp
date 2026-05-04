// https://leetcode.com/problems/rotate-image/?envType=daily-question&envId=2026-05-04

#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& mat) {
        int n = mat.size(), k = n - 1;
        for (int i = 0; i < n >> 1; i++) {
            for (int j = i; j < k - i; j++) {
                int t = mat[i][j];
                mat[i][j] = mat[k - j][i];
                mat[k - j][i] = mat[k - i][k - j];
                mat[k - i][k - j] = mat[j][k - i];
                mat[j][k - i] = t;
            }
        }
    }
};
