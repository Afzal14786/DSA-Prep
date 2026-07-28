// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-palindromic-rearrangement-i/?envType=daily-question&envId=2026-07-28

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int mid = n/2;

        sort(s.begin(), s.begin() + mid);

        for (int i = 0; i < mid; ++i) {
            s[n-i-1] = s[i];
        }

        return s;
    }
};