// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=daily-question&envId=Invalid%20Date

// brute force
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_elem = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                max_elem = max(max_elem, (nums[i] - 1) * (nums[j]-1));
            }
        }

        return max_elem;
    }
};

// using sorting --- TC -- (n log n) 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n-1] - 1) * (nums[n-2] - 1);
    }
};

// linear  -- (n)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for (int x : nums) {
            if (max1 <= x) {
                max2 = max1;
                max1 = x;
            } else if (max2 <= x) {
                max2 = x;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};