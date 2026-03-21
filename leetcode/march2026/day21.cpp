// Question Link : https://leetcode.com/problems/flip-square-submatrix-vertically/?envType=daily-question&envId=2026-03-21

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int t=x, b=x+k-1; t<b; t++, b--){
            for(int j=y; j<y+k; j++)
                swap(grid[t][j], grid[b][j]);
        }
        return grid;
    }
};
