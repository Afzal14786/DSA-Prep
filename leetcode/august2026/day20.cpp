// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/?envType=daily-question&envId=2026-08-20

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1 = {nums[0]}, arr2 = {nums[1]};

        for (int i = 2; i < n; ++i) {
            if (arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }

        for (auto it : arr2) arr1.push_back(it);

        return arr1;
    }
};