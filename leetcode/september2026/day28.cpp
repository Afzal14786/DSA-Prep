// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2026-09-28

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, depth = 0;
        for (char ch : s) {
            depth += (ch == '(') - (ch == ')');
            ans = max(ans, depth);
        }
        return ans;
    }
};
