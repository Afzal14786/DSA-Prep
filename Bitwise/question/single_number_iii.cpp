// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;


// brute force and first thought
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
        }

        for (auto [val, f] : freq) {
            if (f == 1) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};