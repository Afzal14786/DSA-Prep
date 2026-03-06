// Question Link : https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06

#include <iostream>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string& s) {
        const int n=s.size();
        int i0=s.find('0');
        if (i0==-1) return 1;
        int i1=s.find_last_of('1');
        return i0>i1;
    }
};

// Two pointer approach 

class Solution {
public:
    bool checkOnesSegment(string& s) {
        const int n=s.size();
        int i0=0;
        while(s[i0]=='1') i0++;
        if (i0==n) return 1;
        int i1=n-1;
        while(s[i1]=='0') i1--;
        return i0>i1;
    }
};
