// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/description/?envType=daily-question&envId=2026-08-28

class Solution {
public:

    bool solve(string &curr, string &ans, vector<int> &freq, string &tar, int &half_len, char &mid_char, int i, bool is_greater) {
        if (curr.length() == half_len) {
            string candidate    = curr;
            string right_half   = curr;
            reverse(right_half.begin(), right_half.end());

            if (mid_char != '$') candidate += mid_char;
            candidate += right_half;

            if (candidate > tar) {
                ans = candidate;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0) continue;
            if (!is_greater && ch < tar[i]) continue;
            curr.push_back(ch);
            freq[ch - 'a']--;

            bool greater = is_greater || ch > tar[i];
            if (solve(curr, ans, freq, tar, half_len, mid_char, i+1, greater)) return true;
            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char &ch : s) freq[ch - 'a']++;
        int odd_count = 0;
        char mid_char = '$';
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1) {
                odd_count++;
                mid_char = i + 'a';
            }

        }

        if (odd_count > 1) return "";  // not possible to make a palindrome

        for (int c = 0; c < 26; ++c) freq[c] /= 2;  // for computing the left half of the palindrome
        int half_len = n/2;

        string curr = "", res = "";
        solve(curr, res, freq, target, half_len, mid_char, 0, false);
        return res;
    }
};