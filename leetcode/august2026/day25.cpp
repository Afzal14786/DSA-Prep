// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-missing-multiple-of-k/?envType=daily-question&envId=2026-08-25

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int max_elem = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] % k == 0) {
                max_elem = max(max_elem, nums[i]);
            }
        }

        if (max_elem == -1) return k;
        // now we have maximum element, compute the required size
        int required_size = max_elem / k;
        vector<int> multiples(required_size, 0); // all values initially zero

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] % 2 == 0) {
                int idx = nums[i] / k;
                multiples[idx-1] = nums[i];
            }
        }

        // now we have requird arrays so go through it 
        for (int i = 0; i < required_size; ++i) {
            if (multiples[i] == 0) {
                return k * (i + 1);
            }
        }

        return k * (required_size + 1);
    }
};

// Another Solution

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        for (int x = k; ; x += k) {
            if (!st.count(x)) return x;
        }
        return 0;
    }
};

// another solution

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> freq(101,0);

        for(int i=0;i<nums.size();i++)
            freq[nums[i]] = 1;

        int i = k;
        while(i <= 100) {
            if(!freq[i])
                return i;
            i += k;
        }
        return ((100 / k) + 1) * k;
    }
};