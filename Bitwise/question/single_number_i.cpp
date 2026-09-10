// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * efficient solution
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= nums[i];
        }
        return ans;
    }
};

// brute force -- first thought
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;  // <nums, freq>

        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
        }

        for (auto [elem, freqency] : freq) {
            if (freqency == 1) return elem;
        }

        return -1;
    }
};
