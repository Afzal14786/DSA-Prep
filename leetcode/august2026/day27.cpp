// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/?envType=daily-question&envId=2026-08-27

class Solution {
public:

    bool solve(string &curr, string &ans, vector<int> &freq, string &target, int i, bool greater) {
        if (i == target.size()) {
            if (greater) {
                ans = curr;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (freq[ch - 'a'] == 0) continue;
            if (!greater && ch < target[i]) continue;

            curr.push_back(ch);
            freq[ch - 'a']--;

            bool is_greater = greater || ch > target[i];
            if (solve(curr, ans, freq, target, i+1, is_greater)) return true;

            // back track
            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char &ch : s) freq[ch - 'a']++;

        string curr = "", res = "";

        solve(curr, res, freq, target, 0, false);

        return res;
    }
};