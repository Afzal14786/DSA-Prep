// Question Linnnnk : https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-03-02

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);

       
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = n-1; j >= 0 && grid[i][j] == 0; j--) {
                count++;
            }
            zeros[i] = count;
        }

        int swaps = 0;

       
        for(int i = 0; i < n; i++) {
            int required = n - 1 - i;

            int j = i;
            while(j < n && zeros[j] < required) {
                j++;
            }

            if(j == n) return -1;

            while(j > i) {
                swap(zeros[j], zeros[j-1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};
