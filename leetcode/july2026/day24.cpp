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

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int max_elem = *max_element(nums.begin(), nums.end());

        int T = 1;
        while (T <= max_elem)  T *= 2;

        vector<bool> S1(T, false);  // XOR for pairs
        vector<bool> s2(T, false); // XOR for triplates

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                S1[nums[i] ^ nums[j]] = true;
            }
        }

        for (int i = 0; i < T; ++i) {
            if (S1[i]) {
                for (int num : nums) {
                    S2[i ^ num] = true;
                }
            }
        }

        int count = 0;
        for (bool x : S2) {
            if (x) count++;
        }

        return count;
    }
};

int main() {
    
    return 0;
}