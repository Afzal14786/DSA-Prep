// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * more optmize solution
 */

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
  }
};

/**
 * efficient solution
 */

 class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int bit_idx = 0; bit_idx <= 31; ++bit_idx) {
            int count = 0;
            for (int i = 0; i <= n-1; ++i) {
                if (nums[i] & (1 << bit_idx)) count++;
            }

            if (count % 3 == 1) ans |= (1 << bit_idx);
        }

        return ans;
    }
};

// brute force using hash map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        // <val, freq>
        unordered_map<int, int> freq;
        
        for (int &x : nums) freq[x]++;
        int ans = 0;
        for (auto [val, frequency] : freq) {
            if (frequency == 1) {
                ans = val;
                break;
            }
        }

        return ans;
    }
};