// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/number-of-unique-xor-triplets-ii/?envType=daily-question&envId=2026-07-24

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;  // store all the pairs XOR

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                st.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> ans;
        for (auto XORPAIR : st) {
            for (int &num : nums) {
                ans.insert(num ^ XORPAIR);
            }
        }

        return ans.size();
    }
};

int main() {
    
    return 0;
}