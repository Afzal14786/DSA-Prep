// Question Link : https://leetcode.com/problems/largest-submatrix-with-rearrangements/?envType=daily-question&envId=2026-03-17

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        auto m = matrix.size(), n = matrix[0].size();
        int res = 0;

        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];

        for (int i = 0; i < m; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for (int j = 0; j < n; j++)
                res = max(res, matrix[i][j] * (j + 1));
        }

        return res;
    }
};


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
         int maxarea = 0 ;  
        for(int i = 0 ; i<n ;i++){
            for(int j = 0 ; j<m ;j++){
                if(matrix[i][j] == 1 && i-1>=0){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
            vector<int>heights = matrix[i] ;
            sort(heights.begin() , heights.end() , greater<int>()) ;
            for(int k =0 ; k<m ;k++){
                int ht = heights[k] ;
                int base = k+1 ;
                maxarea = max(maxarea , ht*base) ;

            }
        }
        return maxarea ;
    }
};
