// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-commas-in-range/description/

class Solution {
public:
    int countCommas(int n) {
        return (n > 999) * (n - 999);
    }
};