// Question Link : 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(int x,vector<int> &nums,int k){
        int n = nums.size();
        for(int i=0;i<=x;i++){
            int rem = n-1-(x-i);

            if(nums[i]*1LL*k>=1LL*nums[rem]){
                return true;
            }
        }

        return false;
    }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n-1;

        while(low<=high){
            int mid =(low+high)/2;

            if(check(mid,nums,k)){
                ans =min(ans,mid);
                high =mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};
