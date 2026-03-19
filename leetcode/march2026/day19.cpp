// Question Link : https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/?envType=daily-question&envId=2026-03-19

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        vector<vector<int>> px(m, vector<int>(n, 0));
        vector<vector<int>> py(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                px[i][j] = (grid[i][j] == 'X');
                py[i][j] = (grid[i][j] == 'Y');

                if (i > 0) {
                    px[i][j] += px[i - 1][j];
                    py[i][j] += py[i - 1][j];
                }
                if (j > 0) {
                    px[i][j] += px[i][j - 1];
                    py[i][j] += py[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    px[i][j] -= px[i - 1][j - 1];
                    py[i][j] -= py[i - 1][j - 1];
                }

                if (px[i][j] == py[i][j] && px[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        vector<int> px(n, 0), py(n, 0);

        for (int i = 0; i < m; i++) {
            int rowX = 0, rowY = 0;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X') rowX++;
                else if (grid[i][j] == 'Y') rowY++;

                px[j] += rowX;
                py[j] += rowY;

                if (px[j] == py[j] && px[j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
