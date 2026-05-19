// Question Link : https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2026-05-19


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans=-1;
        int n = nums1.size(),m = nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                ans=nums1[i];
                break;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};