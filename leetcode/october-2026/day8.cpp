// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/remove-outermost-parentheses/description/?envType=daily-question&envId=2026-10-08

class Solution {
public:
    string removeOuterParentheses(string& s) {
        string res;
        int lvl = 0;

        for (auto& c : s)
            if (c & 1 ? --lvl : lvl++)
                res += c;

        return res;
    }
};
