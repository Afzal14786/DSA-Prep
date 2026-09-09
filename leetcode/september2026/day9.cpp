// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-commas-in-range-ii/description/?envType=daily-question&envId=2026-09-09

class Solution {
public:
    int64_t countCommas(long long n) {
        int64_t count = 0;
        for (int64_t p = 1000; p <= n; p *= 1000) 
            count += n - p + 1;
        
            return count;
    }
};