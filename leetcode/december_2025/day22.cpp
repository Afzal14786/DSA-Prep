// You are given an array of n strings strs, all of the same length.

// We may choose any deletion indices, and we delete all the characters in those indices for each string.

// For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].

// Suppose we chose a set of deletion indices answer such that after deletions, the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.

 
// Example 1:

// Input: strs = ["babca","bbazb"]
// Output: 3
// Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["bc", "az"].
// Both these rows are individually in lexicographic order (ie. strs[0][0] <= strs[0][1] and strs[1][0] <= strs[1][1]).
// Note that strs[0] > strs[1] - the array strs is not necessarily in lexicographic order.

// Example 2:

// Input: strs = ["edcba"]
// Output: 4
// Explanation: If we delete less than 4 columns, the only row will not be lexicographically sorted.

// Example 3:

// Input: strs = ["ghi","def","abc"]
// Output: 0
// Explanation: All rows are already lexicographically sorted.

 

// Constraints:

//     n == strs.length
//     1 <= n <= 100
//     1 <= strs[i].length <= 100
//     strs[i] consists of lowercase English letters.

// Question Link : https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/?envType=daily-question&envId=2025-12-22

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int solve(int i, int prev,vector<string>& strs,vector<vector<int>> &dp){
        int m = strs[0].size();
        int n = strs.size();

        if(i==m){
            return 0;
        }

        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        //Pick this index
        int pick =0;
        int skip = solve(i+1,prev,strs,dp);
          if(prev==-1){
                pick = 1 +solve(i+1,i,strs,dp);
          }else{

            bool flag = true;

            for(int j=0;j<n;j++){
                if(strs[j][i]<strs[j][prev]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                pick = 1 +solve(i+1,i,strs,dp);
            }
          } 

          return dp[i][prev+1]=max(skip,pick);

    }
    int minDeletionSize(vector<string>& strs) {
         int m = strs[0].size();
         int n = strs.size();
        vector<vector<int>> dp(m,vector<int>(m+1,-1));
        return m-solve(0,-1,strs,dp);
    }
};