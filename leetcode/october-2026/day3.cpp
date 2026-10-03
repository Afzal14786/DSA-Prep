// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-valid-parentheses/?envType=daily-question&envId=2026-10-03

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int open = 0, close = 0;

        int res = 0;

        // left to right
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') open++;
            else close++;

            if (open == close) res = max(res, close + open);
            else if (close > open) {  // left to right
                open = close = 0;
            }
        }

        open = 0;
        close = 0;
        
        // right to left
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == ')') close++;
            else open++;

            if (open == close) res = max(res, open + close);
            else if (open > close) {
                open = 0;
                close = 0;
            }
        }

        return res;
    }
};