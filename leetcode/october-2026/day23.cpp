// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/maximum-k-to-sort-a-permutation/solutions/8584322/and-of-the-misplaced-numbers-k-is-a-joke-g7b2/?envType=daily-question&envId=2026-10-23

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;  // all bits set: nothing misplaced yet
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i) {  // this number has to move
                k &= nums[i];  // keep only the bits it shares
                if (k == 0) return 0;  // bits only disappear, so 0 stays 0
            }
        return max(k, 0);  // -1 means nothing has to move
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();