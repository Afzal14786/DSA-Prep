// Question Link : https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2026-05-06

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        
        std::vector<std::vector<char>> ans(m, std::vector<char>(n, '.'));

        for (int i = 0; i < m; ++i) {
            int P = n-1;
            for (int j = n-1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    ans[j][m-1-i] = '*';
                    P = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    ans[P--][m-1-i] = '#';
                }
            }
        }

        return ans;
    }
};