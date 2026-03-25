// Question Link : https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25

#include <iostream>
#include <vector>

using namespace std;

long long rowSum[100000], colSum[100000];
class Solution {
public:
    static bool canPartitionGrid(vector<vector<int>>& grid) {
        const int r=grid.size(), c=grid[0].size();
        memset(rowSum, 0, r*8);
        memset(colSum, 0, c*8);
        for (int i=0; i<r; i++){
            if (i>0)[[likely]]
                rowSum[i]+=rowSum[i-1];
            for(int j=0; j<c; j++){
                const int x=grid[i][j];
                rowSum[i]+=x;
                colSum[j]+=x;
            }
        }
        partial_sum(colSum, colSum+c, colSum);
        const long long Tsum=colSum[c-1], target=Tsum/2;
        if (Tsum&1) return 0;
        int i=lower_bound(rowSum, rowSum+r, target)-rowSum;
        if (i<r && rowSum[i]==target) return 1;
        int j=lower_bound(colSum, colSum+c, target)-colSum;
        return j<c && colSum[j]==target;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


class Solution {
public:
    static bool canPartitionGrid(vector<vector<int>>& grid) {
        long long Tsum=0;
        for(auto& row : grid)
            Tsum+=accumulate(row.begin(), row.end(), 0LL);
        if (Tsum&1) return 0;
        const long long target=Tsum/2;
        const int r=grid.size(), c=grid[0].size();
        long long rowSum=0, colSum=0;
        for(int i=0; rowSum<target && i<r; i++){
            rowSum+=accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }
        if (rowSum==target) return 1;
        for(int j=0; colSum<target && j<c; j++){
            for(int i=0; i<r; i++) colSum+=grid[i][j];
        }
        return colSum==target;
    }
};
