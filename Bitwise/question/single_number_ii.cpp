// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

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