// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/reverse-degree-of-a-string/description/?envType=daily-question&envId=2026-09-20

class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += (i + 1) * ('z' - s[i] + 1);
        return sum;
    }
};