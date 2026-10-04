// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/valid-parenthesis-string/?envType=daily-question&envId=2026-10-04

class Solution {
public:
    bool checkValidString(string s) {
        int cmax = 0, cmin = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                cmin++;
                cmax++;
            } else if (ch == ')') {
                cmin--;
                cmax--;
            } else {
                cmin--;
                cmax++;
            }

            if (cmax < 0) return false;
            cmin = std::max(0, cmin);
        }

        return cmin == 0;
    }
};