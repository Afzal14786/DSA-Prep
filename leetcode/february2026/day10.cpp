// Question Link : https://leetcode.com/problems/longest-balanced-subarray-i/?envType=daily-question&envId=2026-02-10

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxLength =0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            unordered_set<int> even;
            unordered_set<int> odd;
            if (n - i <= maxLength) break;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    even.insert(nums[j]);
                }else{
                    odd.insert(nums[j]);
                }

                if(odd.size()==even.size()){
                    maxLength = max(maxLength,j-i+1);
                }
            }
        }

        return maxLength;
    }
};


class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
       int res=0;
       for(int i=0;i<n;i++){
             unordered_set<int>e,o;
            for(int j=i;j<n;j++){
               if(nums[j]%2==0){
                   e.insert(nums[j]);
               } else {
                   o.insert(nums[j]);
               } if(e.size()==o.size()){
                   res=max(res,j-i+1);
               }                
            }
        }
        return res;
    }
};
