// Question Link : https://leetcode.com/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);


        for(int i=0;i<n;i++){
            int index =i;
            if(nums[i]>0){
                index = (index+nums[i])%n;
            }else{
                index = ((index -abs(nums[i]))%n+n)%n;
            }
            
            ans[i]=nums[index];
        }

        return ans;

    }
};
