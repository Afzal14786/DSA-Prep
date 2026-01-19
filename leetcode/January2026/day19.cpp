/**
 * Maximum Side Length Of A Square With Sum Less Than Or Equal To Threshold
 * Question Link : https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/?envType=daily-question&envId=2026-01-19
 * Solution Link : 
 */

// Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

// Example 1:
// Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
// Output: 2
// Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

// Example 2:
// Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
// Output: 0

// Constraints:

//  m == mat.length
//  n == mat[i].length
//  1 <= m, n <= 300
//  0 <= mat[i][j] <= 10^4
//  0 <= threshold <= 10^5

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check( int k,int i, int j,  int threshold,vector<vector<int>>& prefix) {
        int n = prefix.size()-1;
        int m = prefix[0].size()-1;

        if(i+k> n || j+k>m){
            return false;
        }
        int sum = prefix[i+k][j+k]-prefix[i+k][j-1]-prefix[i-1][j+k]+prefix[i-1][j-1];
        return sum<=threshold;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int maxi = 0;

        vector<vector<int>> prefix(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix[i][j]=mat[i-1][j-1];
                prefix[i][j]+=prefix[i-1][j];
                prefix[i][j]+=prefix[i][j-1];
                prefix[i][j]-=prefix[i-1][j-1];
            }
        }

        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= m; j++) {
                int low =maxi;
                int high = min(n,m);

                while(low<=high){
                    int mid =(low+high)/2;
                    if(check(mid,i,j,threshold,prefix)){
                        low =mid+1;
                        maxi =max(maxi,mid+1);
                    }else{
                        high =mid-1;
                    }
                }
            }
        }

        return maxi;
    }
};